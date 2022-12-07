# CMakeList.txt: проект CMake для cursovaya; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required(VERSION 3.13)

project ("cursovaya")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (cursovaya "cursovaya.cpp" "cursovaya.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
# include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()

# add_executable(echobot src/main.cpp)




# project(tess_example CXX)


set(SW_BUILD_SHARED_LIBS 1)
set(DEPENDENCIES
    org.sw.demo.google.tesseract.libtesseract-master
    org.sw.demo.intel.opencv.imgproc
    org.sw.demo.intel.opencv.highgui
)

find_package(SW REQUIRED)
sw_add_package(${DEPENDENCIES})
sw_execute()

# target_link_libraries(${PROJECT_NAME} ${DEPENDENCIES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

target_link_libraries(cursovaya C:/dev/vcpkg/installed/x64-windows/lib/TgBot.lib ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES} ${DEPENDENCIES})


