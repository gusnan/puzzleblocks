/**
 *
 *	This file is part of PuzzleBlocks
 *	Copyright (C) 2020-2022 Andreas Rönnquist
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
#include <vector>

#include "GusGame/GusGame.h"

using namespace Gus;

using namespace LogLib;
using namespace ExceptionLib;
using namespace GraphicsLib;
using namespace EventLib;

#include "GusGui/GusGui.h"

using namespace GusGui;

#include "../Gui/Button.h"
#include "../Gui/MainMenuPanel.h"

#include "EventHandlerGame.h"
#include "EventHandlerMainMenu.h"

#include "../GameMode/GameMode.h"
#include "../GameMode/GameModeGame.h"
#include "../GameMode/GameModeMainMenu.h"
#include "../GameMode/GameModeHandler.h"



#include "Program.h"

#include "../Data.h"
#include "../Events.h"


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

   // Is it Ctrl+Alt+X that is pressed? - then quit
   if (keyEvent.getType() == KeyEventPressed) {
      if ((keyEvent.getValue() == Key::X) && (keyEvent.getCtrlPressed()) && (keyEvent.getAltPressed())) {
         Program::instance().setQuit();
         return true;
      }

      if (keyEvent.getValue() == Key::R) {
         std::cout << "R." << std::endl;
         return true;
      }

      if (keyEvent.getValue() == Key::K) {
         GameModeHandler::switchGameMode(GameModeHandler::gameModeGame);
         return true;
      }
   }
   return false;
}


/**
 *
 */
bool EventHandlerMainMenu::handleUserEvent(UserEvent &inUserEvent)
{
   LOG("User event..");

   if (inUserEvent == *Events::instance().eventNewGame) {
      GameModeHandler::switchGameMode(GameModeHandler::gameModeGame);
      return true;
   } else if (inUserEvent == *Events::instance().eventQuitGame) {
      Program::instance().setQuit();
      return true;
   }
   return GuiEventHandler::handleUserEvent(inUserEvent);
}


