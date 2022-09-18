/**
 *
 *	This file is part of PuzzleBlocks
 *	Copyright (C) 2020-2022 Andreas Rönnquist
 *
 *	PuzzleBlocks is free software: you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as published
 *	by the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	PuzzleBlocks is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with PuzzleBlocks.
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

using namespace GraphicsLib;

using namespace EventLib;

#include "EventHandler/EventHandlerMainMenu.h"

#include "GameMode.h"
#include "GameModeMainMenu.h"


/**
 *
 */
GameModeMainMenu::GameModeMainMenu() : GameMode(), mainMenuEventHandler(nullptr)
{
   LOG("Game Mode Main Menu Constructor");
   mainMenuEventHandler = std::make_shared<EventHandlerMainMenu>();
}


/**
 *
 */
GameModeMainMenu::~GameModeMainMenu()
{
   LOG("Game Mode Main Menu Destructor");
}


/**
 *
 */
void GameModeMainMenu::enterGameMode()
{
   GameMode::enterGameMode();
   LOG("GameModeMainMenu::enterGameMode");

   EventSystem::addEventHandler(mainMenuEventHandler);
}


/**
 *
 */
void GameModeMainMenu::leaveGameMode()
{
   GameMode::leaveGameMode();
   LOG("GameModeMainMenu::leaveGameMode");

   EventSystem::removeEventHandler(mainMenuEventHandler);
}


/**
 *
 */
void GameModeMainMenu::draw()
{

}
