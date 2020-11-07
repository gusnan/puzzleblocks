/**
 *
 *	This file is part of PuzzleBlocks
 *	Copyright (C) 2020 Andreas Rönnquist
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
#include <list>
#include <sstream>

#include "GusGame/GusGame.h"


using namespace Gus;

using namespace LogLib;

#include "GameMode.h"
#include "GameModeMainMenu.h"
#include "GameModeHandler.h"

std::shared_ptr<GameMode> GameModeHandler::currentGameMode = nullptr;

std::shared_ptr<GameModeMainMenu> GameModeHandler::gameModeMainMenu = nullptr;

/**
 *
 */
void GameModeHandler::initGameModes()
{
   LOG("Init GameModeHandler...");
   
   gameModeMainMenu = std::make_shared<GameModeMainMenu>();
}


/**
 *
 */
void GameModeHandler::doneGameModes()
{
   LOG("Done GameModeHandler...");
   
   switchGameMode(nullptr);

   gameModeMainMenu.~shared_ptr();
   
   currentGameMode.~shared_ptr();
}


/**
 *
 */
void GameModeHandler::switchGameMode(std::shared_ptr<GameMode> inGameMode)
{
   if (currentGameMode != nullptr) {
      currentGameMode->leaveGameMode();
   }

   currentGameMode = inGameMode;
   
   if (currentGameMode != nullptr) {
      currentGameMode->enterGameMode();
   }
}


/**
 *
 */
void GameModeHandler::draw()
{
   if (currentGameMode != nullptr) {
      
      currentGameMode->draw();
   }
}
