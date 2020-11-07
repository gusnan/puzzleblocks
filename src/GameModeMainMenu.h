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
#ifndef __HEADER_GAME_MODE_MAIN_MENU_
#define __HEADER_GAME_MODE_MAIN_MENU_

class GameModeMainMenu : public GameMode
{
public:
   GameModeMainMenu();
   virtual ~GameModeMainMenu();

   virtual void enterGameMode() override;
   virtual void leaveGameMode() override;

   virtual void draw() override;
protected:
};


#endif /*__HEADER_GAME_MODE_MAIN_MENU_*/
