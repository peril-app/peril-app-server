add_library(peril-app-server-crowdoth crow.h)

set_target_properties(peril-app-server-crowdoth PROPERTIES LINKER_LANGUAGE C)

add_subdirectory(crow)