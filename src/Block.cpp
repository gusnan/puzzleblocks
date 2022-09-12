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
Block::Block() : m_Position(0, 0), m_TempPosition(0.0f), m_DeltaPosition(1.0f), m_Moveable(true)
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
void Block::update()
{

   if (m_Moveable) {

      m_TempPosition += m_DeltaPosition * Timer::getDeltaTime() * 20.0f;

      if (m_TempPosition < 0.0f) {
         m_TempPosition = 0.0f;
         m_DeltaPosition = 1.0f;
      }
      if (m_TempPosition >= 100.0f) {
         m_TempPosition = 99.0f;
         m_DeltaPosition = -1.0f;
      }
   }
}


/**
 *
 */
void Block::draw()
{
   Primitives::rectFill(Rect((m_Position * Vector2d(20, 20)) + Vector2d(m_TempPosition, 0), Vector2d(20, 20)), colorRed);
   Primitives::rect(Rect((m_Position * Vector2d(20, 20)) + Vector2d(m_TempPosition, 0), Vector2d(20, 20)), colorWhite);
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
