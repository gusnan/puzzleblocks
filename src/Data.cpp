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

using std::stringstream;

using namespace Gus;

using namespace LogLib;
using namespace ExceptionLib;
using namespace GraphicsLib;
using namespace EventLib;

#include "Data.h"

#define REMOVE(a) if (a != nullptr) { a.reset(); a = nullptr; }

/**
 *
 */
Data &Data::instance()
{
   static Data instance;
   return instance;
}


/**
 *
 */
Data::Data(const Data &inData) : mouseBitmap(inData.mouseBitmap->makeCopy()), font(nullptr)
{
}



/**
 *
 */
Data::~Data()
{
   doneData();
}


/**
 *
 */
Data &Data::operator=(const Data &inData)
{
   this->mouseBitmap = inData.mouseBitmap->makeCopy();

   font = nullptr;

   return *this;
}


/**
 *
 */
Data::Data() : mouseBitmap(nullptr), font(nullptr)
{
   initData();
}


/**
 *
 */
void Data::initData()
{
   LOG("Init data");

   mouseBitmap = std::make_shared<Bitmap>("mouse.png");

   font = std::make_shared<Font>("FreeSans.ttf", 12, true);

   eventEnterGame = std::make_shared<UserEvent>();
}

std::shared_ptr<UserEvent> Data::getEventEnterGame()
{
   return eventEnterGame;
}


/**
 *
 */
void Data::doneData()
{
   LOG("Done Data");
   // Delete mouse after we remove mouse functionality in Mouse::doneMouse.
   // if (m_MouseBitmap != nullptr) delete m_MouseBitmap;
   REMOVE(mouseBitmap);

   REMOVE(font);

   REMOVE(eventEnterGame);
}