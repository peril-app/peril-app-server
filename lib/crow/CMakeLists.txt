add_library(peril-app-server-libs
    app.h  
    ci_map.h  
    common.h  
    dumb_timer_queue.h  
    http_connection.h  
    http_parser_merged.h  
    http_request.h  
    http_response.h  
    http_server.h  
    json.h 
    logging.h  
    middleware_context.h  
    middleware.h  
    mustache.h  
    parser.h  
    query_string.h  
    routing.h  
    settings.h  
    socket_adaptors.h  
    TinySHA1.hpp  
    utility.h  
    websocket.h
)

set_target_properties(peril-app-server-libs PROPERTIES LINKER_LANGUAGE C)