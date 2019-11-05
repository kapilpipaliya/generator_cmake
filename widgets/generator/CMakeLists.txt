cmake_minimum_required(VERSION 3.15)
#    find_package(Filesystem REQUIRED)


find_package(Qt5 COMPONENTS Core Gui Widgets Network Xml Sql WebSockets REQUIRED)
find_package(range-v3 CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem locale) #1.71.0
set (Boost_ARCHITECTURE "-x64")
include(CheckIncludeFileCXX)


#set(CMAKE_MODULE_PATH  "/home/kapili3/k/cpp_stuff/vcpkg/installed/x64-linux/share/pegtl")
#add_subdirectory(thirdparty/PEGTL)

#AUX_SOURCE_DIRECTORY(Grammer GRAMMER_SRC)
AUX_SOURCE_DIRECTORY(gui GRAMMER_SRC)
AUX_SOURCE_DIRECTORY(gui/editor GRAMMER_SRC)
AUX_SOURCE_DIRECTORY(generator GRAMMER_SRC)
set(QRC1_DIR ./gui/editor/application.qrc)


file(GLOB SCP_LIST ${CMAKE_CURRENT_SOURCE_DIR}/templates/*.csp)
foreach(cspFile ${SCP_LIST})
  message(STATUS "cspFile:" ${cspFile})
  exec_program(basename
               ARGS
               "${cspFile} .csp"
               OUTPUT_VARIABLE
               classname)
  message(STATUS "view classname:" ${classname})
  add_custom_command(OUTPUT ${classname}.h ${classname}.cc
                     COMMAND drogon_ctl
                             ARGS
                             create
                             view
                             ${cspFile}
                     DEPENDS ${cspFile}
                     VERBATIM)
  set(TEMPL_SRC ${TEMPL_SRC} ${classname}.cc)
endforeach()


add_library(generator ${GRAMMER_SRC}
    ${QRC1_DIR}
    ${TEMPL_SRC}
    )

target_link_libraries(generator
#     taocpp::pegtl
     Qt5::Core
     Qt5::Gui
     Qt5::Widgets
     Qt5::Network
     Qt5::Xml
     Qt5::Sql
     stdc++fs
     meta concepts range-v3
      Boost::filesystem
     )
