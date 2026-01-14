cmake_minimum_required(VERSION 3.15)
project(odyssey)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(glad CONFIG REQUIRED)

# Collect source files
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/**/*.cpp"
)

# Create executable
add_executable(odyssey ${SOURCES})

# Include directories
target_include_directories(odyssey PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${Stb_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(odyssey PRIVATE 
    glfw
    glm::glm
    glad::glad
)

# Copy assets to build directory
add_custom_command(TARGET odyssey POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:odyssey>/assets
)
