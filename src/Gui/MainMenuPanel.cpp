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

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <memory>

#include "GusGame/GusGame.h"

#include "GusGame/EventLib.h"
#include "GusGame/EventSystem.h"

using namespace Gus;

using namespace LogLib;
using namespace ExceptionLib;
using namespace GraphicsLib;
using namespace EventLib;

#include "GusGui/GusGui.h"

using namespace GusGui;

#include "Button.h"
#include "MainMenuPanel.h"

#include "../Data.h"
#include "../Events.h"

/**
 *
 */
MainMenuPanel::MainMenuPanel() : Panel(Rect(10, 10, 400, 200), "Text"),
                                 m_NewGameButton(nullptr),
                                 m_QuitButton(nullptr),
                                 m_TempButton(nullptr)
{
   LOG("MainMenuPanel constructor");

   m_NewGameButton = std::make_shared<MainMenu::Button>(Rect(10, 10, 250, 49), "New Game");
   m_NewGameButton->setPressEvent(Events::instance().eventNewGame);
   addGuiObject(m_NewGameButton);

   m_QuitButton = std::make_shared<MainMenu::Button>(Rect(10, 80, 250, 49), "Quit");
   m_QuitButton->setPressEvent(Events::instance().eventQuitGame);
   addGuiObject(m_QuitButton);

   m_TempButton = std::make_shared<MainMenu::Button>(Rect(10,150, 250, 49), "Test");
   addGuiObject(m_TempButton);
}


/**
 *
 */
MainMenuPanel::~MainMenuPanel()
{
   LOG("MainMenuPanel destructor");
}


/**
 *
 */
void MainMenuPanel::draw(const Vector2d &pos, float opacity)
{
   // Draw a white outline on the panel
   Rect newRect = getRect() + pos;

   Primitives::rect(newRect, colorWhite);

   // Make the Panel class which we inherit from draw the gui objects
   Panel::draw(pos, opacity);
}
