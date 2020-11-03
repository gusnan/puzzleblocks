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


#include "MainMenuEventHandler.h"

#include "Program.h"


/**
 * Handle keyboard presses and releases
 */
bool MainMenuEventHandler::handleKeyboard(KeyEvent &keyEvent) {

   // Is it the Escape Button that is pressed? - then quit
   if (keyEvent.getType() == KeyEventPressed) {
      if (keyEvent.getValue() == Key::Escape) {
         Program::quit = true;
         return true;
      }

      if (keyEvent.getValue() == Key::R) {
			std::cout << "R." << std::endl;
		}
   }
   return false;
}

