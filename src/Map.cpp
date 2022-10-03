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
#include <memory>
#include <iterator>
#include <algorithm>

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
Map::Map() : m_MapSize(),
             m_BlockList(nullptr),
             m_FullBlock(nullptr),
             m_HighlightPosition(),
             m_ViewBlock(nullptr)
{
   LOG("Map::Map()");
   m_Active = true;
   m_Rect = Rect();
   m_Visible = true;
   m_MouseOver = false;

   initMap();
}

/**
 *
 */
Map::Map(const Rect &inRect, const Vector2d &inSize) : GuiObject(inRect), 
                                                       m_MapSize(inSize),
                                                       m_BlockList(nullptr),
                                                       m_FullBlock(nullptr),
                                                       m_HighlightPosition(),
                                                       m_ViewBlock(nullptr)
{
   LOG("Map::Map(rect, vector2d)");
   initMap();

   m_Active = true;
   m_Rect = inRect;
   m_MouseOver = false;
   m_Visible = true;
}


/**
 *
 */
Map::Map(const Map &source) : GuiObject(source.m_Rect),
                              m_MapSize(source.m_MapSize),
                              m_BlockList(nullptr),
                              m_FullBlock(nullptr),
                              m_HighlightPosition(),
                              m_ViewBlock(nullptr)
{
   LOG("Map copy constructor");

   m_Active = source.m_Active;
   m_Rect = source.m_Rect;
   m_MouseOver = source.m_MouseOver;
   m_Visible = source.m_Visible;
}


/**
 *
 */
Map &Map::operator=(const Map &inData)
{
   //this->mouseBitmap = inData.mouseBitmap->makeCopy();
   LOG("Map copy");

   if (this != &inData) {

      m_Rect = inData.m_Rect;

      m_MapSize = inData.m_MapSize;

      m_Active = inData.m_Active;

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

   GraphicsHandler::instance().setClipRect(getRect());

   for (int co1 = 0; co1 < m_MapSize.x; co1++)
   for (int co2 = 0; co2 < m_MapSize.y; co2++) {
      // Primitives::rect(Rect(Vector2d(co1 * 32, co2 * 32) + getPosition(), Vector2d(32, 32)), colorGreen);
      // m_MapData[co2 * m_SizeX + co1]->draw(co1 * 20, co2 * 20);
   }

   std::list<std::shared_ptr<Block> >::iterator iter;

   for (iter = m_BlockList->begin(); iter != m_BlockList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      if (temp->getPosition().y > 0) {

         temp->draw();
      }
      ++iter;
   }

   GraphicsHandler::instance().noClip();

   // if (m_HighlightPosition.y != 0) {
   Primitives::rect(Rect(Vector2d(m_HighlightPosition.x * 32, m_HighlightPosition.y * 32) + getPosition() - Vector2d(0, 32),
                  Vector2d(32, 32)),
                  colorWhite);
   // }


   if (m_ViewBlock != nullptr) {
      Vector2d tempPos = m_ViewBlock->getPosition();

      m_ViewBlock->setPosition(Vector2d(25, 5));
      m_ViewBlock->draw(false);

      m_ViewBlock->setPosition(tempPos);
   }

   // Primitives::rectFill(Rect(getPosition(), Vector2d(320, 32)), colorBlack);

   Primitives::rect(getRect(), colorRed);
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

   m_FullBlock->setPosition(Vector2d(-1, -1));

   /*
   for (int co = 0; co < 10; co++) {
      std::shared_ptr<Block> tempBlock = std::make_shared<Block>();
      tempBlock->setPosition(Vector2d(co, 10));
      tempBlock->setMovable(false);

      m_BlockList->push_back(tempBlock);
   }
   */


/*
   createBlock(Vector2d(0, 2), 0);
   createBlock(Vector2d(1, 2), 0);
   createBlock(Vector2d(1, 1), 1);
   createBlock(Vector2d(3, 2), 2);
   createBlock(Vector2d(8, 7), 3);
   createBlock(Vector2d(8, 5), 4);



   createBlock(Vector2d(6, 0), 4);
   createBlock(Vector2d(7, 4), 4);
   */

   std::random_device device;

   std::default_random_engine generator(device());
   std::uniform_int_distribution<int> distribution(0, 3);

   int q = 0;

   for (int co1 = 0; co1 < 8; co1++)
   for (int co2 = 0; co2 < 8; co2++) {

      createBlock(Vector2d(co1 + 1, co2 + 1), distribution(generator)); // (q % 3));

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
   // GusGui::GuiObject::update();

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

   for (int co = 0; co < m_MapSize.x; co++) {

      if (getBlockAtPosition(Vector2d(co, 0)) == nullptr) {
         std::random_device device;

         std::default_random_engine generator(device());
         std::uniform_int_distribution<int> distribution(0, 3);

         createBlock(Vector2d(co, 0), distribution(generator));
      }
   }

}


std::shared_ptr<Block> Map::getBlockAtPosition(const Vector2d &position, int minYposition)
{
   std::shared_ptr<Block> result = nullptr;

   if (position.x < 0 || position.y < minYposition || position.x >= m_MapSize.x || position.y > m_MapSize.y) {
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
      block->setFalling(false);
      block->setPosition(position);

      block->setMapPosition(getPosition());

      m_BlockList->push_back(block);
   }
}


/**
 *
 */
void Map::onMouseMove(const Vector2d &pos)
{
   GuiObject::onMouseMove(pos);

   // LOG("onMouseMove");
   if (m_MouseOver) {
      Vector2d newpos= pos - getPosition();

      // std::stringstream st;


      int x = newpos.x / 32;
      int y = newpos.y / 32;

      /*
      st << "NewPos: " << newpos << " and: (" << x << ", " << y << ")";

      STLOG(st);
      */

      m_HighlightPosition = Vector2d(x, y + 1);

      m_ViewBlock = getBlockAtPosition(m_HighlightPosition);

      /*
      st.str("");

      st << viewBlock;

      STLOG(st);
      */

      // Primitives::rect(Rect(x * 32, y * 32, 32, 32), colorWhite);

   }
}


/**
 *
 */
void Map::removeBlock(const Vector2d &pos)
{
   std::shared_ptr<Block> temp = getBlockAtPosition(pos);

   if (temp != nullptr) {

      auto iter = std::find_if(m_BlockList->begin(), m_BlockList->end(),
                        [&](auto &s){ return (s == temp); }
      );

      if (iter != m_BlockList->end()) {
         m_BlockList->erase(iter);
      }

      temp.reset();
   }
}


/**
 *
 */
std::shared_ptr<Block> Map::getFullblock()
{
   return m_FullBlock;
}


/**
 *
 */
void addPositionToList(Map *map, std::list<std::shared_ptr<Block> > *posList, std::shared_ptr<Block> block, int *result)
{
   if (block == nullptr) return;

   std::list<std::shared_ptr<Block> >::iterator iter;

   if (block == map->getFullblock()) return;

   for (iter = posList->begin(); iter != posList->end(); ) {

      std::shared_ptr<Block> temp = (*iter);

      if (temp == block) {

         // the block is already in the list, nothing more to do.
         return;
      }
      ++iter;
   }

   Vector2d position = block->getPosition();

   if (posList) {
      posList->push_back(block);
      (*result)++;
   }

   int x = position.x;
   int y = position.y;

   int bcolor = block->getColor();

   if (map) {

      std::shared_ptr<Block> tempBlock = map->getBlockAtPosition(Vector2d(x + 1, y), 1);

      if (tempBlock != nullptr) {
         if (tempBlock->getColor() == bcolor) {
            addPositionToList(map, posList, map->getBlockAtPosition(Vector2d(x + 1, y), 1), result);
         }
      }

      tempBlock = map->getBlockAtPosition(Vector2d(x , y + 1));

      if (tempBlock != nullptr) {
         if (tempBlock->getColor() == bcolor) {
            addPositionToList(map, posList, map->getBlockAtPosition(Vector2d(x, y + 1), 1), result);
         }
      }
      tempBlock = map->getBlockAtPosition(Vector2d(x - 1, y));

      if (tempBlock != nullptr) {
         if (tempBlock->getColor() == bcolor) {
            addPositionToList(map, posList, map->getBlockAtPosition(Vector2d(x - 1, y), 1), result);
         }
      }
      tempBlock = map->getBlockAtPosition(Vector2d(x, y - 1));

      if (tempBlock != nullptr) {
         if (tempBlock->getColor() == bcolor) {
            addPositionToList(map, posList, map->getBlockAtPosition(Vector2d(x, y - 1), 1), result);
         }
      }
   }
}

/**
 *
 */
bool Map::onLeftMouseButtonPressed(const Vector2d& pos)
{
   Vector2d tempPosition;

   if (m_MouseOver) {
      Vector2d newpos= pos - getPosition();

      int x = newpos.x / 32;
      int y = newpos.y / 32;

      y++;

      tempPosition = Vector2d(x, y);

      std::shared_ptr<Block> block = getBlockAtPosition(tempPosition);

      std::list<std::shared_ptr<Block> > *posList = new std::list<std::shared_ptr<Block> >();

      int howmany = 0;

      if (block != nullptr) {
         addPositionToList(this, posList, block, &howmany);
      }

      if (howmany > 1) {

         std::list<std::shared_ptr<Block> >::iterator iter;

         for (iter = posList->begin(); iter != posList->end(); ) {

            std::shared_ptr<Block> temp = (*iter);

            Vector2d pos = temp->getPosition();

            removeBlock(pos);

            ++iter;
         }
      }

      delete posList;

      return true;

   }
   return false;
}