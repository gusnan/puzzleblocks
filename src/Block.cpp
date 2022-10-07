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
#include <memory>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>

#include "GusGame/GusGame.h"

using namespace Gus;

using namespace LogLib;

using namespace GraphicsLib;


#include "Data.h"

#include "Block.h"

const int blockSize = 48;

/**
 *
 */
Block::Block() : m_Position(0, 0),
                 m_Moveable(true),
                 m_Speed(20.0f),
                 m_Falling(false),
                 m_Color(0),
                 m_Counter(0.0f),
                 m_MapPosition()
{
}


/**
 *
 */
Block::Block(int inColor) : m_Position(0, 0),
                            m_Moveable(true),
                            m_Speed(20.0f),
                            m_Falling(false),
                            m_Color(inColor),
                            m_Counter(0.0f),
                            m_MapPosition()
{
}

/**
 *
 */
Block::~Block()
{
}


/**
 *
 */
Block::Block(const Block &source) : m_Position(source.m_Position),
                                    m_Moveable(source.m_Moveable),
                                    m_Speed(source.m_Speed),
                                    m_Falling(source.m_Falling),
                                    m_Color(source.m_Color),
                                    m_Counter(source.m_Counter),
                                    m_MapPosition(source.m_MapPosition)
{
}


/**
 *
 */
Block &Block::operator=(const Block &source)
{
   if (this != &source) {
      m_Position = source.m_Position;

      m_Moveable = source.m_Moveable;

      m_Color = source.m_Color;

      m_Counter = source.m_Counter;

      m_Speed = source.m_Speed;
   }

   return *this;
}


/**
 *
 */
bool Block::operator==(const Block &inBlock)
{
   bool result = true;

   if (inBlock.m_Position.x != this->m_Position.x) {
      result = false;
   }

   if (inBlock.m_Position.y != this->m_Position.y) {
      result = false;
   }

   if (inBlock.m_Color != this->m_Color) {
      result = false;
   }

   return result;
}


/**
 *
 */
bool Block::operator!=(const Block &inBlock)
{
   return !(this == &inBlock);
}


/**
 *
 */
void Block::update()
{
   if (m_Moveable) {

      // if (getFalling()) {
      m_Counter -= 0.5f * m_Speed * Timer::getDeltaTime();

      if (m_Counter <= 0.0f) {
         // setPosition(getPosition() + Vector2d(0, 1));

         // m_Counter -= 1.0f;
         m_Counter = 0.0f;

         // setFalling(false);
      }
   }
}


/**
 *
 */
void Block::draw(bool includeMinorPosition)
{
   int tempPosition = ((double)m_Counter / (double)1.0f) * (double)(blockSize);
   Vector2d newTemp = Vector2d(0, tempPosition);

   // Primitives::rectFill(Rect((m_Position * Vector2d(BLOCK_SIZE, BLOCK_SIZE)) + newTemp, Vector2d(BLOCK_SIZE, BLOCK_SIZE)), colorRed);
   // Primitives::rect(Rect((m_Position * Vector2d(BLOCK_SIZE, BLOCK_SIZE)) + newTemp, Vector2d(BLOCK_SIZE, BLOCK_SIZE)), colorWhite);

   Vector2d position = m_Position * Vector2d(blockSize, blockSize) + m_MapPosition - Vector2d(0, blockSize);

   if (includeMinorPosition) {
      position -= newTemp;
   }

   Data::instance().blocksBitmap->blit(Rect(m_Color * 32, 0, 32, 32), Rect(position, Vector2d(blockSize, blockSize)));
}

/**
 *
 */
void Block::setPosition(const Vector2d &pos)
{
   m_Position = pos;
}


/**
 *
 */
Vector2d Block::getPosition()
{
   return m_Position;
}


/**
 *
 */
bool Block::getMovable()
{
   return m_Moveable;
}

/**
 *
 */
void Block::setMovable(bool moveable)
{
   m_Moveable = moveable;
}


/**
 *
 */
bool Block::getFalling()
{
   return m_Falling;
}


/**
 *
 */
void Block::setFalling(bool inFalling)
{
   if (inFalling) {
      setPosition(getPosition() + Vector2d(0, 1));
      m_Counter = 1.0f;
   }
   m_Falling = inFalling;
}


/**
 *
 */
double Block::getCounter() const
{
   double result = m_Counter;
   // if (result == 1.0f) result = 0.0f;
   return result;
}


/**
 *
 */
void Block::setCounter(double inCounter)
{
   m_Counter = inCounter;
}

/**
 *
 */
void Block::setMapPosition(const Vector2d &pos)
{
   m_MapPosition = pos;
}


/**
 *
 */
int Block::getColor() const
{
   return m_Color;
}