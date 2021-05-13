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

using std::stringstream;

using namespace Gus;

using namespace LogLib;
using namespace ExceptionLib;
using namespace GraphicsLib;
using namespace EventLib;

#include "EventHandler/EventHandlerMainMenu.h"

#include "Program.h"

#include "GameMode/GameMode.h"
#include "GameMode/GameModeGame.h"
#include "GameMode/GameModeMainMenu.h"
#include "GameMode/GameModeHandler.h"



Program &Program::instance()
{
   static Program instance;

   return instance;
}

Program::Program(const Program &inProgram) : m_Quit(inProgram.m_Quit)
{
}

Program::~Program()
{
   doneProgram();
}

Program &Program::operator=(const Program &inProgram)
{
   this->setQuit(inProgram.m_Quit);

   return *this;
}

Program::Program() : m_Quit(false), m_MouseBitmap(nullptr)
{
   try {
      // init the log - this function takes a string (the log file filename) as
      // indata, if none is inserted, "log.txt" is assumed. If you give the
      // empty string "" as filename for the log, no log will be used.
      //
      // The second indata is a boolean to determine to print the log to
      // std::cout or not in addition to to the file.
      LogHandler::initLog("log.txt", true);

      // init system stuff
      System::initSystem();

      // allegro version
      stringstream st;
      st << "Allegro version: " << System::getAllegroVersionString();
      STLOG(st);

      // Init the graphics stuff
      GraphicsHandler::initGraphicsHandler();

      // set up a screen with resolution of 640x480, and not fullscreen
      GraphicsHandler::setGraphicsMode(Vector2d(720, 360), false);

      // set a window title
      GraphicsHandler::setWindowTitle("PuzzleBlocks");

      Primitives::initPrimitives();

      EventSystem::initEventSystem();

      GameModeHandler::initGameModes();

      GameModeHandler::switchGameMode(GameModeHandler::gameModeMainMenu);

      m_MouseBitmap = new Bitmap("mouse.png");

      Mouse::setMouseBitmap(m_MouseBitmap);

   }
   catch (Exception &e)
   {
      throw e;
   }
}

bool Program::getQuit()
{
   return m_Quit;
}

void Program::setQuit(bool iQuit) {
   m_Quit = iQuit;
}


void Program::doneProgram()
{
   delete m_MouseBitmap;

   GameModeHandler::doneGameModes();

   // Done with the event system
   // EventSystem::doneEventSystem();

   Primitives::donePrimitives();

   GraphicsHandler::doneGraphicsHandler();

   // Remove mouse stuff
   Mouse::doneMouse();

   // done with system stuff
   System::doneSystem();

   LOG("All done.");

   // done with the Log
   LogHandler::doneLog();
}

void Program::mainLoop()
{
   // the main loop
   do {
      // Update the timer
      Timer::updateFrame();

      // Handle events (see the class just above this main
      EventSystem::handleEvents();

      // Clear the screen every sync
      GraphicsHandler::clearScreen();

      //System::getMouse()->draw();

      GameModeHandler::draw();

      // Update the screen
      GraphicsHandler::updateScreen();
   } while(!m_Quit);

}
