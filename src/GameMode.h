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
#ifndef __HEADER_GAME_MODE_
#define __HEADER_GAME_MODE_

class GameMode
{
public:
   GameMode();
   virtual ~GameMode();

   virtual void EnterGameMode() = 0;
   virtual void LeaveGameMode() = 0;

   virtual void Draw();

protected:
};

#endif /*__HEADER_GAME_MODE_*/