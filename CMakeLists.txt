cmake_minimum_required(VERSION 3.22)

project(Game_sfml)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "D:\\Programs\\vcpkg\\installed\\x64-windows\\share\\sfml")
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

include_directories("D:\\Projects\\Projects Clion\\SFML-2.5.1\\include")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(${PROJECT_NAME})

add_executable(Game_sfml
        Game-sfml/Ai.cpp
        Game-sfml/Ai.h
        Game-sfml/Config.h
        Game-sfml/EventHandler.cpp
        Game-sfml/EventHandler.h
        Game-sfml/Figure.cpp
        Game-sfml/Figure.h
        Game-sfml/Game.cpp
        Game-sfml/Game.h
        Game-sfml/GameView.cpp
        Game-sfml/GameView.h
        Game-sfml/main.cpp
        Game-sfml/Player.cpp
        Game-sfml/Player.h)

target_link_libraries(${PROJECT_NAME} sfml-graphics)