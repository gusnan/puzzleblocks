#
#	This file is part of PuzzleBlocks
#	Copyright (C) 2020 Andreas Rönnquist
#
#	PuzzleBlocks is free software: you can redistribute it and/or
#	modify it under the terms of the GNU General Public License as published
#	by the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	PuzzleBlocks is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with PuzzleBlocks.
#	If not, see <http://www.gnu.org/licenses/>.
#
#

cmake_minimum_required(VERSION 3.10)

project(puzzleblocks)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

option (DEBUG "Build Debug executable" off)

find_package(Allegro5 REQUIRED)

if (DEBUG)
	message(STATUS "Building Debug executable")
	set(CMAKE_BUILD_TYPE "Debug")
	add_definitions(-D_DEBUG)
	#add_definitions(-Wwrite-strings
			#-Wextra
			#-Wall
			#-Winit-self
			#-O
			#-Wno-uninitialized
			#-Wno-unused-parameter
			#-Wno-switch
			#-w
			#-Wreturn-type
			#-Weffc++
		#)
	# Cpp only flags: (Will not be applied to C files.)
	set(CMAKE_CXX_FLAGS -Weffc++)

else (DEBUG)
	message(STATUS "Building Release executable")
	#add_definitions(-fomit-frame-pointer)
	set(CMAKE_BUILD_TYPE "Release")

endif (DEBUG)

# set(DLL_FLAGS -DBUILDING_GUSGAME_DLL)

set(BUILD_SHARED_LIBS on)

SET(CMAKE_SHARED_LIBRARY_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CXX_FLAGS} -DBUILDING_GUSGAME_DLL")

if (MSYS)
	set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-enable-auto-import")
endif (MSYS)


message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")


cmake_policy(SET CMP0072 NEW)


find_package(OpenGL REQUIRED)

find_package(GusGame REQUIRED)
find_package(Allegro5 REQUIRED)
find_package(Lua REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem thread)

message(STATUS "GusGame Library: ${GUSGAME_LIBRARY}")

include_directories(include ${GUSGAME_INCLUDE_DIR})

include_directories(include ${CMAKE_SOURCE_DIR}/include)
include_directories(include ${ALLEGRO_INCLUDE_DIR})
include_directories(include ${LUA_INCLUDE_DIR})


if (WIN32)
	if (MSYS)
		Set (WINGL_LIBS glu32)
	else (MSYS)
		Set (WINGL_LIBS glu32)
	endif (MSYS)

endif(WIN32)

find_package(OpenGL REQUIRED)
find_package(GusGame REQUIRED)

# find_package(Boost REQUIRED )

message(STATUS "GusGame Library: ${GUSGAME_LIBRARY}")


include_directories(include ${CMAKE_SOURCE_DIR}/src)
include_directories(include ${CMAKE_SOURCE_DIR}/src/Objects)

include_directories(include ${GUSGAME_INCLUDE_DIR})
include_directories(include ${Boost_INCLUDE_DIR})

if (MSYS)
	message(STATUS "MingDir: $ENV{MINGDIR}")
endif (MSYS)

message(STATUS "Boost INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
message(STATUS "GUSGAME_INCLUDE_DIR: ${GUSGAME_INCLUDE_DIR}")

if (NOT ALLEGRO_FOUND)
	message(FATAL_ERROR "Allegro not found!")
endif (NOT ALLEGRO_FOUND)

# And some libs:

message(STATUS "Allegro5 LIBRARY: ${ALLEGRO_LIBRARIES}")

message(STATUS "OPENGL_LIBRARY: ${OPENGL_LIBRARY}")
message(STATUS "OPENGL_LIBRARIES: ${OPENGL_LIBRARIES}")
message(STATUS "GLUT_LIBRARY: ${GLUT_LIBRARY}")

message(STATUS "GUSGAME_LIBRARY: ${GUSGAME_LIBRARY}")

message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")

if (USE_GLEW)
	set (MY_GLEW_LIB ${GLEW_LIBRARY})
else (USE_GLEW)
	set (MY_GLEW_LIB )
endif (USE_GLEW)

if (MSYS)
	set (GL_LIBS ${OPENGL_LIBRARY} ${OPENGL_LIBRARIES})
else (MSYS)
	set (GL_LIBS ${OPENGL_LIBRARY})
endif (MSYS)

set(ALL_LIBS

	${LUA_LIBRARIES}
	${GL_LIBS}
	${GLUT_LIBRARY}
	${WINGL_LIBS}
	${MY_GLEW_LIB}
	${Boost_LIBRARIES}
	${GUSGAME_LIBRARIES}
	${ALLEGRO_LIBRARIES}
)


link_libraries(${ALL_LIBS} ${GUSGAME_LIBRARY})

include_directories(include "/usr/local/include")
include_directories(include ${GUSGAME_INCLUDE})

# LINK_DIRECTORIES( ${LINK_DIRECTORIES} ${LIBRARY_OUTPUT_PATH})

message (STATUS "Link directories: ${LINK_DIRECTORIES}")
message (STATUS "Library output path: ${LIBRARY_OUTPUT_PATH}")



set(SRC_FOLDER src/)

set (SOURCE_FILES
	${SRC_FOLDER}/Entry.cpp
	${SRC_FOLDER}/Program.cpp

	${SRC_FOLDER}/GameMode.cpp
	${SRC_FOLDER}/GameModeMainMenu.cpp
	${SRC_FOLDER}/GameModeGame.cpp
	${SRC_FOLDER}/EventHandler/EventHandlerMainMenu.cpp
	${SRC_FOLDER}/EventHandler/EventHandlerGame.cpp
	${SRC_FOLDER}/GameModeHandler.cpp
)

add_executable(puzzleblocks ${SOURCE_FILES})
