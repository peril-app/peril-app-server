#define CROW_MAIN

#include <crow_all.h>
#include <iostream>
#include <string>

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
    void before_handle(crow::request& req, crow::response& res, context& ctx) {cout << "[peril-app-server] " << logMsg << endl;}

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

    app.get_middleware<PerilAppMiddleman>().setMessage("STARTING PERIL APP SERVER");

    CROW_ROUTE(app, "/")
    ([] () {

        return "{debugMsg:\"homepage test\"}";
    });

    CROW_ROUTE(app, "/auth/<int>").methods("POST"_method)
    ([] (const crow::request& req, int authActionID) {

        auto requestBody = crow::json::load(req.body);

        if (!requestBody) {return std::string("{debugMsg:\"malformed request (no json body)\",statusCode:400}");}

        switch (authActionID) {

            case 0 : // wants to create an account
                return std::string("{debugMsg:\"\",statusCode:503}");
                break;
            
            case 1 : // wants to delete an account
                return std::string("{debugMsg:\"\",statusCode:503}");
                break;
            
            case 2 : // wants to sign in
                return std::string("{debugMsg:\"\",statusCode:503}");
                break;
            
            case 3 : // wants to sign out
                return std::string("{debugMsg:\"\",statusCode:503}");
                break;
            
            case 4 : // wants to check if signed in (only for error handling)
                return std::string("{debugMsg:\"\",auth:" + std::string(checkSessionValidity() ? "true" : "false") + ",statusCode:200}");
                break;

            default: // wrong action ID
                return std::string("{debugMsg:\"route does not exist\",statusCode:404}");
        }
    });

    app.loglevel(crow::LogLevel::Debug);

    app.port(7348).multithreaded().run();

    return 0;
}