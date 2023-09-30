message("Hello from common")
message(${CMAKE_CURRENT_SOURCE_DIR})
message(${PROJECT_SOURCE_DIR})

#list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/common/test")

add_subdirectory("test")