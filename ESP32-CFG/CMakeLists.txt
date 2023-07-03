cmake_minimum_required(VERSION 3.5)

project(ESP32-CFG VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/resources/ui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    enable_language("RC")
    set (WIN32_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/windows/icons.rc)
endif()

set(PROJECT_HEADERS
        include/mainwindow.h

        include/livefeed.h
        include/configure.h
        include/about.h
        include/connect.h

        include/weeklyweatherentry.h

        include/fontsizes.h
        include/fontweights.h
        include/colordefinitions.h
        include/settings.h
        include/structs.h

        include/iconpainter.h
        include/styleloader.h
        include/weathericon.h
        include/stringparser.h

        include/serialport.h
        include/serialdefault.h
        include/serialcommands.h
        include/recordsizes.h
)

set(PROJECT_UIS
        resources/ui/mainwindow.ui
        resources/ui/livefeed.ui
        resources/ui/configure.ui
        resources/ui/about.ui
        resources/ui/connect.ui
)

set(PROJECT_RES
        resources/res.qrc
)


set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/livefeed.cpp
        src/iconpainter.cpp
        src/configure.cpp
        src/about.cpp
        src/weeklyweatherentry.cpp
        src/weathericon.cpp
        src/colordefinitions.cpp
        src/serialport.cpp
        src/connect.cpp
        src/styleloader.cpp
        src/stringparser.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ESP32-CFG
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_RES}
        ${PROJECT_HEADERS}
        ${PROJECT_UIS}
        ${WIN32_RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ESP32-CFG APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ESP32-CFG SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ESP32-CFG
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(ESP32-CFG PRIVATE include)

target_link_libraries(ESP32-CFG PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ESP32-CFG PRIVATE Qt${QT_VERSION_MAJOR}::SerialPort)

set_target_properties(ESP32-CFG PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ESP32-CFG
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ESP32-CFG)
endif()
