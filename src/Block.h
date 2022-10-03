/**
 *
 *	This file is part of PuzzleBlocks
 *	Copyright (C) 2022 Andreas Rönnquist
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
#ifndef __HEADER_BLOCK_
#define __HEADER_BLOCK_

class Block
{
public:
   Block();
   Block(int inColor);
   virtual ~Block();

   Block(const Block &source);
   Block &operator=(const Block &source);

   bool operator!=(const Block &inBlock);
   bool operator==(const Block &inBlock);

   void update();

   void draw();

   void setPosition(const Vector2d &pos);
   Vector2d getPosition();

   bool getMovable();
   void setMovable(bool moveable);

   bool getFalling();
   void setFalling(bool inFalling = true);

   double getCounter();

   void setMapPosition(const Vector2d &pos);

protected:

   Vector2d m_Position;

   double m_TempPosition;
   double m_DeltaPosition;

   bool m_Moveable;

   double m_Speed;

   bool m_Falling;

   // double m_PixelsWeCanFall;

   int m_Color;

   double m_Counter;

   Vector2d m_MapPosition; // the position of the map gui object on the screen
};

#endif /*__HEADER_BLOCK_*/
