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


#include "Block.h"

/**
 *
 */
Block::Block() : m_Position(0, 0),
                 m_TempPosition(0.0f),
                 m_DeltaPosition(1.0f),
                 m_Moveable(true),
                 m_Speed(20.0f)
{
}

/**
 *
 */
Block::~Block()
{
   LOG("Block destructor");
}


/**
 *
 */
Block::Block(const Block &source) : m_Position(source.m_Position),
                                    m_TempPosition(source.m_TempPosition),
                                    m_DeltaPosition(source.m_DeltaPosition),
                                    m_Moveable(source.m_Moveable),
                                    m_Speed(20.0f)
{
}


/**
 *
 */
Block &Block::operator=(const Block &source)
{
   if (this != &source) {
      m_Position = source.m_Position;

      m_TempPosition = source.m_TempPosition;
      m_DeltaPosition = source.m_DeltaPosition;

      m_Moveable = source.m_Moveable;
   }

   return *this;
}


/**
 *
 */
void Block::update()
{

   if (m_Moveable) {

      m_TempPosition += m_DeltaPosition * Timer::getDeltaTime() * m_Speed;

      m_Speed = m_Speed + 2.0f;

      if (m_TempPosition < 0.0f) {
         m_TempPosition = 0.0f;
         m_DeltaPosition = 1.0f;
      }
      if (m_TempPosition >= 19.0f) {
         m_TempPosition = 19.0f;
         m_DeltaPosition = -1.0f;

         // We need to check if we cannot fall any further

         m_Moveable = false;

         m_Position = Vector2d(m_Position.x, m_Position.y + 1);

         m_TempPosition = 0.0f;
      }
   }
}


/**
 *
 */
void Block::draw()
{
   Vector2d newTemp = Vector2d(0, m_TempPosition);

   Primitives::rectFill(Rect((m_Position * Vector2d(20, 20)) + newTemp, Vector2d(20, 20)), colorRed);
   Primitives::rect(Rect((m_Position * Vector2d(20, 20)) + newTemp, Vector2d(20, 20)), colorWhite);
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
