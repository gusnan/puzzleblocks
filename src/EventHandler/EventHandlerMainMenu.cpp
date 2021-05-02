/**
 *
 *	This file is part of PuzzleBlocks
 *	Copyright (C) 2020-2021 Andreas Rönnquist
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
using namespace ExceptionLib;
using namespace GraphicsLib;
using namespace EventLib;


#include "EventHandlerMainMenu.h"

#include "Program.h"

/**
 *
 */
EventHandlerMainMenu::EventHandlerMainMenu()
{
}


/**
 *
 */
EventHandlerMainMenu::~EventHandlerMainMenu()
{
   LOG("EventHandlerMainMenu Destructor");
}


/**
 * Handle keyboard presses and releases
 */
bool EventHandlerMainMenu::handleKeyboard(KeyEvent &keyEvent) {

   // Is it the Escape Button that is pressed? - then quit
   if (keyEvent.getType() == KeyEventPressed) {
      if (keyEvent.getValue() == Key::Escape) {
         Program::instance()->setQuit();
         return true;
      }

      if (keyEvent.getValue() == Key::R) {
         std::cout << "R." << std::endl;
         return true;
      }
   }
   return false;
}

