/**
 *
 *	This file is part of PuzzeBlocks
 *	Copyright (C) 2020 Andreas Rönnquist
 *
 *	PuzzeBlocks is free software: you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as published
 *	by the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	PuzzeBlocks is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with PuzzeBlocks.
 *	If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <memory>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>

#include "GusGame/GusGame.h"

using namespace Gus;

using namespace LogLib;


#include "GameMode.h"
#include "GameModeMainMenu.h"


/**
 *
 */
GameModeMainMenu::GameModeMainMenu() : GameMode()
{
}


/**
 *
 */
GameModeMainMenu::~GameModeMainMenu()
{
}


/**
 *
 */
void GameModeMainMenu::EnterGameMode()
{
   LOG("Enter Main Menu Gamemode");
}


/**
 *
 */
void GameModeMainMenu::LeaveGameMode()
{
   LOG("Leave Main Menu Gamemode");
}
