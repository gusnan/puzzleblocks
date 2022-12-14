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

const int BLOCK_TYPE_COLORED_BLOCK =   0;
const int BLOCK_TYPE_GEM =             1;

class Block
{
public:
   Block();
   explicit Block(int type, int inColor = 0);
   virtual ~Block();

   Block(const Block &source);
   Block &operator=(const Block &source);

   bool operator!=(const Block &inBlock);
   bool operator==(const Block &inBlock);

   void update();

   void draw(bool includeMinorPosition = true);

   void setPosition(const Vector2d &pos);
   Vector2d getPosition();

   bool getMovable();
   void setMovable(bool moveable);

   bool getFalling();
   void setFalling(bool inFalling = true);

   double getCounter() const;
   void setCounter(double inCounter);

   void setMapPosition(const Vector2d &pos);

   int getColor() const;

   int getType() const;

protected:

   Vector2d m_Position;

   bool m_Moveable;

   double m_Speed;

   bool m_Falling;

   // double m_PixelsWeCanFall;

   int m_Color;

   double m_Counter;

   int m_BlockType;

   Vector2d m_MapPosition; // the position of the map gui object on the screen
};

extern const int blockSize;

#endif /*__HEADER_BLOCK_*/
