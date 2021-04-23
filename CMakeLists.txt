cmake_minimum_required(VERSION 3.20k)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is
# highly recommended that you include this block for all projects.

project(gencmake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)
find_package(Qt5 COMPONENTS Core Gui Widgets Network Xml Sql WebSockets REQUIRED)

set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

include(CheckIncludeFileCXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

remove_definitions(USE_MYSQL)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall ${CMAKE_CXX_STD_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall ${CMAKE_CXX_STD_FLAGS}")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules/ "$ENV{HOME}/k/cpp_stuff/actor-framework/cmake/")

#find_package (UUID REQUIRED)

find_package (OpenSSL)
if(OpenSSL_FOUND)
    list(APPEND _OPTIONAL_LIBS OpenSSL::SSL OpenSSL::Crypto)
endif()

find_package(ZLIB REQUIRED)

#find_package(Boost REQUIRED COMPONENTS chrono filesystem date_time program_options iostreams)

#find_package(Boost REQUIRED COMPONENTS filesystem locale) #1.71.0
#set (Boost_ARCHITECTURE "-x64")
# find_package(Boost REQUIRED COMPONENTS filesystem date_time system timer)
#find_package(cppzmq REQUIRED)
find_package(PNG REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
#find_package(GDAL REQUIRED)
#find_package(msgpack REQUIRED)
#find_package(fmt REQUIRED)
#find_package(yaml-cpp CONFIG REQUIRED)


#find_package(HighFive 2.0 REQUIRED)
#https://abseil.io/docs/cpp/quickstart-cmake
#git clone https://github.com/abseil/abseil-cpp.git
# Process Abseil's CMake build system
#add_subdirectory(abseil-cpp)
#find_package(Wt REQUIRED Wt HTTP)

#find_package(sqlite3 CONFIG REQUIRED)
find_package(KF5WidgetsAddons)
#find_package(range-v3 CONFIG REQUIRED)
#find_package(amqpcpp CONFIG REQUIRED)

AUX_SOURCE_DIRECTORY(./ SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/yaml SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/svelte SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/react SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/modelwriter SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/dgraphcode SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/stl SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/sqlcompare SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/reminder SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/apihandler SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/classgenerator SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/bookmarks SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/bashrcconfig SRC_DIR)
include_directories(widgets/bashrcconfig)
set(SRC_DIR_MX
    ./widgets/bashrcconfig/aliastab.ui
    ./widgets/bashrcconfig/window_fix.ui
    ./widgets/bashrcconfig/prompttab_fix.ui
    ./widgets/bashrcconfig/othertab.ui
    ./widgets/bashrcconfig/resource.qrc
)
AUX_SOURCE_DIRECTORY(./widgets/scripter SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/scripter/editor SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/bashhistoryviewer SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/querybuilder SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/generator SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/protobuff SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/wstest SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/syncroute SRC_DIR)
AUX_SOURCE_DIRECTORY(./widgets/terminal SRC_DIR)
AUX_SOURCE_DIRECTORY(./thirdparty/pystring SRC_DIR)
AUX_SOURCE_DIRECTORY(./thirdparty/toolwindowmanager/src  SRC_DIR)
#add_subdirectory(./thirdparty/)
include_directories(thirdparty/)

AUX_SOURCE_DIRECTORY(./MdiMainWindow SRC_DIR)

AUX_SOURCE_DIRECTORY(./sqlite SRC_DIR)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(./models)
add_subdirectory(widgets/generator)
set(QRC1_DIR ./widgets/scripter/editor/application.qrc)
add_executable(codegen ${SRC_DIR} ${SRC_DIR_MX} ${WSCTL_SRC} ${WSCTL_SRC_CONTEXT} ${HTTPCTL_SRC} ${ACTOR_SRC} ${FILTER_SRC} ${VIEWSRC} ${PLUGIN_SRC} ${MODEL_SRC} ${QRC1_DIR})
add_subdirectory(thirdparty/QCodeEditor)
target_link_libraries(codegen
  Threads::Threads
  ${CMAKE_DL_LIBS}
  ${_OPTIONAL_LIBS}
  ZLIB::ZLIB
  ${DROGON_LIBRARIES}
  ${CAF_LIBRARIES}
  KF5::WidgetsAddons
#  yaml-cpp
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::Network
  Qt5::Xml
  Qt5::Sql
  Qt5::WebSockets
  QCodeEditor
  sqlite3
  #  amqpcpp
  stdc++fs
#  meta concepts
  generator
  qtermwidget5

)
