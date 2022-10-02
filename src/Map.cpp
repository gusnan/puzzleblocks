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
#include <random>

#include "GusGame/GusGame.h"

using namespace Gus;

using namespace LogLib;

using namespace GraphicsLib;

using namespace EventLib;

#include "GusGui/GusGui.h"

using namespace GusGui;

#include "Map.h"


/**
 *
 */
Map::Map() : m_Size(), m_BlockList(nullptr), m_FullBlock(nullptr)
{
}

/**
 *
 */
Map::Map(const Vector2d &inSize) : GuiObject(),  m_Size(inSize), m_BlockList(nullptr), m_FullBlock(nullptr)
{
   initMap();
}


/**
 *
 */
Map::Map(const Map &source) : m_Size(source.m_Size), m_BlockList(nullptr), m_FullBlock(nullptr)
{
   LOG("Map copy constructor");
}


/**
 *
 */
Map &Map::operator=(const Map &inData)
{
   //this->mouseBitmap = inData.mouseBitmap->makeCopy();
   LOG("Map copy");

   if (this != &inData) {

      m_Size = inData.m_Size;

      m_BlockList = new std::list<std::shared_ptr<Block>>();

      m_BlockList->clear();

      std::list<std::shared_ptr<Block> >::iterator iter;

      for (iter = inData.m_BlockList->begin(); iter != inData.m_BlockList->end(); ) {

         std::shared_ptr<Block> iterblock = *iter;

         std::shared_ptr<Block> tempBlock = std::make_shared<Block>(*iterblock);
         m_BlockList->push_back(tempBlock);

         ++iter;
      }

   }

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
void Map::draw(const Vector2d &pos, float alpha)
{

   for (int co1 = 0; co1 < m_Size.x; co1++)
   for (int co2 = 0; co2 < m_Size.y; co2++) {
      // Primitives::rect(Rect(co1 * 32, co2 * 32, 32, 32), colorWhite);
      // m_MapData[co2 * m_SizeX + co1]->draw(co1 * 20, co2 * 20);
   }

   std::list<std::shared_ptr<Block> >::iterator iter;

   for (iter = m_BlockList->begin(); iter != m_BlockList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      if (temp->getPosition().y < m_Size.y) {

         temp->draw();
      }

      ++iter;
   }
}


/**
 *
 */
void Map::initMap()
{
   LOG("Init Map");
   // int totalsize = m_SizeX * m_SizeY;

   m_BlockList = new std::list<std::shared_ptr<Block>>();

   m_BlockList->clear();

   // m_MapData = new std::shared_ptr<Block>[totalsize];

   /*
   for (int co = 0; co < totalsize; co++) {
      m_MapData[co] = std::make_shared<Block>();
   }
   */

   m_FullBlock = std::make_shared<Block>();
   m_FullBlock->setMovable(false);
   m_FullBlock->setFalling(false);

   for (int co = 0; co < 10; co++) {
      std::shared_ptr<Block> tempBlock = std::make_shared<Block>();
      tempBlock->setPosition(Vector2d(co, 10));
      tempBlock->setMovable(false);

      m_BlockList->push_back(tempBlock);
   }


   createBlock(Vector2d(1, 2), 0);
   createBlock(Vector2d(1, 1), 1);
   createBlock(Vector2d(3, 2), 2);
   createBlock(Vector2d(8, 7), 3);
   createBlock(Vector2d(8, 5), 4);



   createBlock(Vector2d(6, 0), 4);
   createBlock(Vector2d(7, 4), 4);

   std::random_device device;

   std::default_random_engine generator(device());
   std::uniform_int_distribution<int> distribution(1, 6);

   int q = 0;

   for (int co1 = 0; co1 < 5; co1++)
   for (int co2 = 0; co2 < 5; co2++) {

      createBlock(Vector2d(co1 + 3, co2 + 3), distribution(generator)); // (q % 3));

      q++;
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

struct compareBlocks {
   bool operator()(std::shared_ptr<Block> left, std::shared_ptr<Block> right) {
      if ((left->getPosition().y) > (right->getPosition().y)) {
         return false;
      }
      return true;
   }
};


/**
 *
 */
void Map::update()
{
   m_BlockList->sort(compareBlocks());

   std::list<std::shared_ptr<Block> >::iterator iter;

   for (iter = m_BlockList->begin(); iter != m_BlockList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      Vector2d pos = temp->getPosition();

      // temp->setCanFall(false);

      if (temp->getCounter() == 0.0f) {
         if (getBlockAtPosition(pos + Vector2d(0, 1)) == nullptr) {
            temp->setFalling(true);
         }
      }

      temp->update();

      ++iter;
   }

}


std::shared_ptr<Block> Map::getBlockAtPosition(const Vector2d &position)
{
   std::shared_ptr<Block> result = nullptr;

   if (position.x < 0 || position.y < 0 || position.x >= m_Size.x - 1 || position.y > m_Size.y - 1) {
      return m_FullBlock;
   }

   std::list<std::shared_ptr<Block> >::iterator iter;

   for (iter = m_BlockList->begin(); iter != m_BlockList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      if (temp->getPosition() == position) result = temp;

      ++iter;
   }

   return result;
}


/**
 *
 */
void Map::createBlock(const Vector2d &position, int inColor)
{

   if (getBlockAtPosition(position) == nullptr) {

      std::shared_ptr<Block> block = std::make_shared<Block>(inColor);
      block->setMovable(true);
      block->setCanFall(true);
      block->setFalling(true);
      block->setPosition(position);

      m_BlockList->push_back(block);
   }
}
