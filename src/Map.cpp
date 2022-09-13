/**
 *
 *	This file is part of PuzzleBlocks
 *	Copyright (C) 2021-2022 Andreas Rönnquist
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

#include "Map.h"


/**
 *
 */
Map::Map() : m_SizeX(0), m_SizeY(0), m_BlockList(nullptr)
{
}

/**
 *
 */
Map::Map(int xsize, int ysize) : m_SizeX(xsize), m_SizeY(ysize), m_BlockList(nullptr)
{
   initMap();
}


/**
 *
 */
Map::Map(const Map &source) : m_SizeX(0), m_SizeY(0), m_BlockList(nullptr)
{
   LOG("Map copy constructor");
}


/**
 *
 */
Map &Map::operator=(const Map &inData)
{
   //this->mouseBitmap = inData.mouseBitmap->makeCopy();

   return *this;
}


/**
 *
 */
Map::~Map()
{
   LOG("Map destructor");

   doneMap();
}


/**
 *
 */
void Map::draw()
{

   for (int co1 = 0; co1 < 10; co1++)
   for (int co2 = 0; co2 < 10; co2++) {
      Primitives::rect(Rect(co1*20, co2*20, 20, 20), colorWhite);
      // m_MapData[co2 * m_SizeX + co1]->draw(co1 * 20, co2 * 20);
   }

   std::list<std::shared_ptr<Block> >::iterator iter;

   for (iter = m_BlockList->begin(); iter != m_BlockList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      temp->draw();

      ++iter;
   }
}


/**
 *
 */
void Map::initMap()
{
   LOG("Init Map");
   int totalsize = m_SizeX * m_SizeY;

   m_BlockList = new std::list<std::shared_ptr<Block>>();

   m_BlockList->clear();

   // m_MapData = new std::shared_ptr<Block>[totalsize];

   /*
   for (int co = 0; co < totalsize; co++) {
      m_MapData[co] = std::make_shared<Block>();
   }
   */

   std::shared_ptr<Block> block = std::make_shared<Block>();
   block->setMovable(false);
   block->setPosition(Vector2d(1, 1));
   m_BlockList->push_back(block);

   for (int co = 0; co < 10; co++) {
      std::shared_ptr<Block> tempBlock = std::make_shared<Block>();
      tempBlock->setPosition(Vector2d(co, 9));
      tempBlock->setMovable(false);

      m_BlockList->push_back(tempBlock);
   }

}

/**
 *
 */
void Map::doneMap()
{
   LOG("Done Map");

   delete m_BlockList;
}


/**
 *
 */
void Map::update()
{

   std::list<std::shared_ptr<Block> >::iterator iter;

   for (iter = m_BlockList->begin(); iter != m_BlockList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      temp->update();

      ++iter;
   }

}
