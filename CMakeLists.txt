cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(shooter VERSION 0.1.0)

set(murl_PATH "/Users/hapass/Downloads/murl_2018.2.7478/murl")
set(murl_BINARIES "${murl_PATH}/base/binaries/osx/Release")
set(murl_THIRDPARTY_BINARIES "${murl_PATH}/3rd_party/binaries/osx/Release")
set(murl_INCLUDES "${murl_PATH}/base/include")
set(murl_THIRDPARTY_INCLUDES "${murl_PATH}/3rd_party/include")

#executable
file(GLOB shooter_SRC
    "src/main/cpp/*.cpp"
    "src/main/cpp/*.h"
    
)

file(GLOB shooter_RESOURCES
    "${murl_PATH}/base/source/platform/osx/cocoa/murl_platform_osx_cocoa_main_window.xib"
)
set_source_files_properties(${shooter_RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

add_executable(shooter MACOSX_BUNDLE
    ${shooter_SRC}
    ${shooter_RESOURCES}
)

target_link_libraries(shooter 
    ${murl_BINARIES}/libmurl_engine.a
    ${murl_BINARIES}/libmurl_platform.a
    ${murl_THIRDPARTY_BINARIES}/libmurl_3rd_party.a
    "-framework OpenGL"
    "-framework OpenAL"
    "-framework CoreLocation"
    "-framework GameKit"
    "-framework StoreKit"
    "-framework AppKit"
    "-framework Foundation"
    "-framework CloudKit"
    "-framework GameController"
    "-framework IOKit"
    "-framework QuartzCore"
    "-framework AVFoundation"
    "-framework CoreMedia"
    "-framework Carbon"
    "-framework AudioToolbox"
    "-framework AudioUnit"
    "-framework CoreAudio"
    "-framework Security"
)

target_include_directories(shooter PUBLIC
    ${murl_INCLUDES}/addons/**
    ${murl_INCLUDES}/app/**
    ${murl_INCLUDES}/engine/**
    ${murl_INCLUDES}/platform/**
)

set(MACOSX_BUNDLE_INFO_STRING "Shooter")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "1")
set(MACOSX_BUNDLE_BUNDLE_NAME "com.watercolorgames.shooter")
set(MACOSX_BUNDLE_BUNDLE_VERSION "1")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")