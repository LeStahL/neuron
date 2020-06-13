cmake_minimum_required(VERSION 3.12)
project(neuron)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Set the module path to custom path where qt is
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Qt/5.12.6/msvc2017")

find_package(Qt5 REQUIRED COMPONENTS Widgets Gui)

# Add main executable
set(${${PROJECT_NAME}_SOURCES}
    ${PROJECT_NAME}.cpp
)
add_executable(${PROJECT_NAME} WIN32 ${${PROJECT_NAME}_SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Gui)

# Copy DLLS to target folder
if(WIN32)
    get_filename_component(_qt_bin_dir "${QT_QMAKE_EXECUTABLE}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt.exe HINTS "${_qt_bin_dir}")
    message("Found windeployqt executable: ${WINDEPLOYQT_EXECUTABLE}")
    message("Binary is in: $<TARGET_FILE_DIR:${PROJECT_NAME}>")
    add_custom_command(TARGET ${PROJECT_NAME} COMMAND ${WINDEPLOYQT_EXECUTABLE} "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
endif()
