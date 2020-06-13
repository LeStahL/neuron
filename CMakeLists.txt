cmake_minimum_required(VERSION 3.8)
project(neuron)

# Set the module path to custom path inside tree
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules")

# Find and configure SDL2
set(ENV{SDL2DIR} "C:/Users/NR4/Downloads/SDL2-devel-2.0.12-VC/SDL2-2.0.12/")
find_package(SDL2 REQUIRED)

# Add main executable
add_executable(${PROJECT_NAME} WIN32 ${PROJECT_NAME}.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

# Copy libraries from SDL bin directory to project bin directory automatically
string(REGEX REPLACE "[.]lib$" ".dll" SDL2_DLL ${SDL2_LIBRARY})
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DLL}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
