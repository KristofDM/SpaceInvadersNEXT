# Copyright (C) 2013
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
# Last modified: 27 November 2013
# By: Stijn Wouters & Kristof De Middelaer
cmake_minimum_required(VERSION 2.6)
project("SPACE INVADERS")

# Define DATADIR, used to find textures and font
add_definitions(-DGRAPHICS="../${CMAKE_SOURCE_DIR}/Graphics/")
add_definitions(-DDATADIR="../${CMAKE_SOURCE_DIR}/Data/")

# Lists all sourcefiles (no testfiles and no main)
set(SRC
    src/factories/BulletFactory.cpp
    src/factories/DataParser.cpp
    src/factories/EnemyShipFactory.cpp
    src/factories/GameParser.cpp
    src/factories/HUDFactory.cpp
    src/factories/ShieldFactory.cpp
    src/factories/SpaceShipFactory.cpp
    src/models/Bullet.cpp
    src/models/EnemyShip.cpp
    src/models/HUD.cpp
    src/models/Model.cpp
    src/models/MovingObject.cpp
    src/models/Shield.cpp
    src/models/Ship.cpp
    src/models/SpaceShip.cpp
    src/models/StaticObject.cpp
    src/observers/controllers/BulletController.cpp
    src/observers/controllers/Controller.cpp
    src/observers/controllers/EnemyShipController.cpp
    src/observers/controllers/HUDController.cpp
    src/observers/controllers/MovingObjectController.cpp
    src/observers/controllers/ShipController.cpp
    src/observers/controllers/SpaceShipController.cpp
    src/observers/controllers/StaticController.cpp
    src/observers/views/BulletView.cpp
    src/observers/views/HUDView.cpp
    src/observers/views/ModelView.cpp
    src/observers/views/SpaceShipView.cpp
    src/observers/Observer.cpp
    src/Exception.cpp
    src/Game.cpp
    src/GameController.cpp
    src/GameView.cpp
    src/tinyXML/tinystr.cpp
    src/tinyXML/tinyxml.cpp
    src/tinyXML/tinyxmlerror.cpp
    src/tinyXML/tinyxmlparser.cpp)

# Set flags
set(CMAKE_CXX_FLAGS "-pedantic -Wall -std=c++11")

# Set the CMake Modules library module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Detect and add SFML
find_package(SFML 2 REQUIRED COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})

# Target to build the main program
add_executable(SpaceInvaders src/SP_INV_NEXT.cpp ${SRC})

# Link executable with SFML
target_link_libraries(SpaceInvaders ${SFML_LIBRARIES})

# Install all executables into the bin directory.
install(TARGETS SpaceInvaders DESTINATION ${PROJECT_SOURCE_DIR}/)
