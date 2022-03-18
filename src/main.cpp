#define CROW_MAIN

#include <crow_all.h>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <vector>

using namespace std;

/*
    the "man in the middle" for requests being sent to and from the server
    current just here so that I dont forget to add this later
    does nothing
*/
struct PerilAppMiddleman {

    std::string logMsg;
    PerilAppMiddleman() {logMsg = '0';}
    void setMessage(std::string msg) {logMsg = msg;}
    struct context {};

    // before handling the request - usually stuff like logging
    // [peril-app-server] [PID] [PPID] message
    void before_handle(crow::request& req, crow::response& res, context& ctx) {cout << "[peril-app-server] [" << getpid() << "] [" << getppid() << "] " << logMsg << endl;}

    // for now, do nothing
    void after_handle(crow::request& req, crow::response& res, context& ctx) {;}
};

/*
    takes no arguments, is based off of the session itself.
    this will check the stored session information against the database to check if the user is still logged in.
    for any private route, this is REQUIRED before any sort of database access happens!
*/
bool checkSessionValidity() {

    // todo
    return false;
}

/*
    adapted from from https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
    basic sql callback
*/
static int sqlCallback(void* data, int argc, char** argv, char** azColName) {
    
    // [key0, value0, key1, value1, etc...]
    std::vector<std::string> keyValuePairs;

    for (int i = 0; i < argc; i++) {
        keyValuePairs.push_back(azColName[i]);
        keyValuePairs.push_back(argv[i] ? argv[i] : "NULL");
    }

    // pass the pointer of 'databaseKeyValuePairs' back to 'data'
    data = &keyValuePairs;

    return 0;
}

/*
    checks that the database is healthy
    if it is not healthy, it will refuse any connections
*/
bool dbCheck(sqlite3* db) {

    std::string dbQuery = "SELECT * FROM pas_info;";
    std::vector<std::string> dbQueryResults;
    int rc = sqlite3_exec(db, dbQuery.c_str(), sqlCallback, &dbQueryResults, NULL);

    cout << dbQueryResults.size() << endl;

    if (rc != SQLITE_OK) return false;
    else if (1) return false;
    else return true;
}

/* 
    standard route response should be:
    {
        "debugMsg":std::string,
        "statusCode:int,
    }
    standard response code should be 200 - if not, then return crow::response(int)
    all requests sent to the server should at least contain a empty json body, ex {}
*/
int main() {

    crow::App<PerilAppMiddleman> app;
    app.get_middleware<PerilAppMiddleman>().setMessage("REQUEST RECIEVED");

    // -------------------------------------------- api route -------------------------------------------- //
    CROW_ROUTE(app, "/")
    ([] () {

        return "{debugMsg:\"homepage test\"}";
    });

    // -------------------------------------------- api route -------------------------------------------- //
    CROW_ROUTE(app, "/auth/<int>").methods("POST"_method)
    ([] (const crow::request& req, int authActionID) {

        // check authentication stuff first to avoid excess computation wasted on un-authenticated users
        auto requestBody = crow::json::load(req.body);
        if (!requestBody) {return std::string("{debugMsg:'malformed request (no json body)',statusCode:400}");}

        sqlite3 *db;
        int rc = sqlite3_open("peril-app-server-main-db.db", &db);
        char* dbErrorMsg;

        if (!dbCheck(db)) return std::string("{debugMsg:'internal server error (database error)',statusCode:504}");
        if (!checkSessionValidity()) return std::string("{debugMsg:'authentication error',statusCode:401}");

        switch (authActionID) {

            case 0 : // wants to create an account

                return std::string("{debugMsg:\"account created\",statusCode:200}");
                break;
            
            case 1 : // wants to delete an account
                return std::string("{debugMsg:\"unfinished route\",statusCode:503}");
                break;
            
            case 2 : // wants to sign in
                return std::string("{debugMsg:\"unfinished route\",statusCode:503}");
                break;
            
            case 3 : // wants to sign out
                return std::string("{debugMsg:\"unfinished route\",statusCode:503}");
                break;
            
            case 4 : // wants to check if signed in (only for error handling)
                return std::string("{debugMsg:\"\",auth:" + std::string(checkSessionValidity() ? "true" : "false") + ",statusCode:200}");
                break;

            default : // wrong action ID
                return std::string("{debugMsg:\"route does not exist\",statusCode:404}");
        }
    });

    app.loglevel(crow::LogLevel::Warning);

    app.port(7348).multithreaded().run();

    return 0;
}