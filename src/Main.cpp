#include <iostream>
#include <string>

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MainAPIController : public oatpp::web::server::api::ApiController {

    MainAPIController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) : oatpp::web::server::api::ApiController(objectMapper)) {}

    ENDPOINT("GET", "/", root) {

        return createResponse(Status::CODE_200, "return homepage information");
    }

    ENDPOINT("GET", "/auth_action/{actionID}", login, PATH(Int64, actionID)) {

        return createResponse(Status::CODE_200, String.toString(actionID->getValue()));
    }
}

#include OATPP_CODEGEN_END(ApiController)