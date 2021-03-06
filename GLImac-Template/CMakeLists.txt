cmake_minimum_required(VERSION 2.8)

project(ImacGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(assimp REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(StbImage REQUIRED)

# Pour gérer un bug a la fac, a supprimer sur machine perso:
set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${assimp_INCLUDE_DIR} $(SDL_TTF_INCLUDE_DIR) ${StbImage_INCLUDE_DIR} glimac/include third-party/include)

set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${SDLTTF_LIBRARY} ${assimp_LIBRARIES} ${StbImage_LIBRARY})

add_subdirectory(glimac)

file(GLOB TP_DIRECTORIES "TP*")

foreach(TP ${TP_DIRECTORIES})
    add_subdirectory(${TP})
endforeach()
