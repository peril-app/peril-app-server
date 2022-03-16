#include <crow_all.h>
#include <iostream>
#include <string>

using namespace std;

// the "man in the middle" for requests being sent to and from the server
struct PerilAppMiddleman {

    std::string logMsg;

    PerilAppMiddleman() {logMsg = '0';}

    void setMessage(std::string msg) {logMsg = msg;}
    
    struct context {};

    // before handling the request - usually stuff like logging
    void before_handle(crow::request& req, crow::response& res, context& ctx) {cout << logMsg << endl;}

    // for now, do nothing
    void after_handle(crow::request& req, crow::response& res, context& ctx) {;}
};

int main() {

    return 0;
}