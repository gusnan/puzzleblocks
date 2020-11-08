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

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>

#include "GusGame/GusGame.h"

using namespace Gus;

using namespace LogLib;

using namespace GraphicsLib;


#include "GameMode.h"
#include "GameModeGame.h"


/**
 *
 */
GameModeGame::GameModeGame() : GameMode()
{
   LOG("Game Mode Game Constructor");
}


/**
 *
 */
GameModeGame::~GameModeGame()
{
   LOG("Game Mode Game Destructor");
}


/**
 *
 */
void GameModeGame::enterGameMode()
{
   GameMode::enterGameMode();
   LOG("GameModeGame::enterGameMode");
}


/**
 *
 */
void GameModeGame::leaveGameMode()
{
   GameMode::leaveGameMode();
   LOG("GameModeGame::leaveGameMode");
}


/**
 *
 */
void GameModeGame::draw()
{
   for (int co1 = 0; co1 < 10; co1++)
   for (int co2 = 0; co2 < 10; co2++) {
      Primitives::rect(Rect(co1*20, co2*20, 20, 20), colorWhite);
   }
}