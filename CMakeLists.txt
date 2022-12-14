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
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()
set(TG_BOT ${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/lib/TgBot.lib)


find_package( Tesseract 5.2.0 REQUIRED )
include_directories(${Tesseract_INCLUDE_DIRS})


add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/config
                ${CMAKE_CURRENT_BINARY_DIR}/config)

add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/tessdata
                ${CMAKE_CURRENT_BINARY_DIR}/tessdata)

target_link_libraries(cursovaya ${TG_BOT} ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES} Tesseract::libtesseract)
