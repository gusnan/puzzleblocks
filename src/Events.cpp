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

#include "Events.h"

#define REMOVE(a) if (a != nullptr) { a.reset(); a = nullptr; }

/**
 *
 */
Events &Events::instance()
{
   static Events instance;
   return instance;
}


/**
 *
 */
Events::Events(const Events &inEvents) : eventEnterGame(nullptr), eventQuitGame(nullptr)
{
}



/**
 *
 */
Events::~Events()
{
   doneEvents();
}


/**
 *
 */
Events &Events::operator=(const Events &inEvents)
{
   return *this;
}


/**
 *
 */
Events::Events() : eventEnterGame(nullptr), eventQuitGame(nullptr)
{
   initEvents();
}


/**
 *
 */
void Events::initEvents()
{
   LOG("Init Events");

   eventEnterGame = std::make_shared<UserEvent>();
   eventQuitGame = std::make_shared<UserEvent>();
}


/**
 *
 */
void Events::doneEvents()
{
   LOG("Done Events");

   REMOVE(eventEnterGame);
   
   REMOVE(eventQuitGame);
}
