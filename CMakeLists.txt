cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(shooter VERSION 0.1.0)

set(MACOSX_BUNDLE_LONG_VERSION_STRING ${PROJECT_VERSION})
set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
set(MACOSX_BUNDLE_INFO_STRING "Shooter game")
set(MACOSX_BUNDLE_BUNDLE_NAME "com.watercolorgames.shooter")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#shooter executable
set(murl_BINARIES_OSX "${murl_PATH}/base/binaries/osx")
set(murl_THIRDPARTY_BINARIES_OSX "${murl_PATH}/3rd_party/binaries/osx")
set(murl_INCLUDES "${murl_PATH}/base/include")
set(murl_THIRDPARTY_INCLUDES "${murl_PATH}/3rd_party/include")

set(murl_ENGINE_LIB optimized ${murl_BINARIES_OSX}/Release/libmurl_engine.a debug ${murl_BINARIES_OSX}/Debug/libmurl_engine.a)
set(murl_PLATFORM_LIB optimized optimized ${murl_BINARIES_OSX}/Release/libmurl_platform.a debug ${murl_BINARIES_OSX}/Debug/libmurl_platform.a)
set(murl_THIRDPARTY_LIB optimized ${murl_THIRDPARTY_BINARIES_OSX}/Release/libmurl_3rd_party.a debug ${murl_THIRDPARTY_BINARIES_OSX}/Debug/libmurl_3rd_party.a)

file(GLOB shooter_SRC
    "src/main/cpp/*.cpp"
    "src/main/cpp/*.h"
)

file(GLOB shooter_RESOURCES
    "${murl_PATH}/base/source/platform/osx/cocoa/murl_platform_osx_cocoa_main_window.xib"
    "assets/root.murlres"
)
set_source_files_properties(${shooter_RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

add_executable(shooter MACOSX_BUNDLE
    ${shooter_SRC}
    ${shooter_RESOURCES}
)

target_link_libraries(shooter 
    ${murl_ENGINE_LIB}
    ${murl_PLATFORM_LIB}
    ${murl_THIRDPARTY_LIB}
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
    "${murl_INCLUDES}/addons/filepanel"
    "${murl_INCLUDES}/addons/lua"
    "${murl_INCLUDES}/app"
    "${murl_INCLUDES}/engine"
    "${murl_INCLUDES}/engine/audio"
    "${murl_INCLUDES}/engine/core"
    "${murl_INCLUDES}/engine/debug"
    "${murl_INCLUDES}/engine/graph"
    "${murl_INCLUDES}/engine/input"
    "${murl_INCLUDES}/engine/logic"
    "${murl_INCLUDES}/engine/math"
    "${murl_INCLUDES}/engine/net"
    "${murl_INCLUDES}/engine/output"
    "${murl_INCLUDES}/engine/physics"
    "${murl_INCLUDES}/engine/resource"
    "${murl_INCLUDES}/engine/system"
    "${murl_INCLUDES}/engine/util"
    "${murl_INCLUDES}/engine/video"
    "${murl_INCLUDES}/platform"
)