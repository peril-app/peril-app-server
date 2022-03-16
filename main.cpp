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
    standard route response should be:

    {
        "debugMsg":std::string,
        "username":std::string,
    }

    standard response code should be 200 - if not, then return crow::response(int)
*/
int main() {

    crow::App<PerilAppMiddleman> app;

    app.get_middleware<PerilAppMiddleman>().setMessage("STARTING PERIL APP SERVER");

    CROW_ROUTE(app, "/")
    ([] () {

        return "{debugMsg:\"homepage test\"}";
    });

    app.loglevel(crow::LogLevel::Debug);

    app.port(7348).multithreaded().run();

    return 0;
}