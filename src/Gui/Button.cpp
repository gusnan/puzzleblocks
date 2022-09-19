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

namespace MainMenu {

/**
 *
 */
Button::Button(const Rect &rect, const std::string &text) : GusGui::Button(rect, text)
{
}


/**
 *
 */
Button::~Button()
{
   LOG("Button destructor");
}


/**
 *
 */

void Button::draw(const Vector2d& pos, float alpha)
{
   // Gray for standard button
   Primitives::rectFill(getRect() + pos, colorLightGray);
   if (getMouseOver()) {

      // red when hovered
      Primitives::rectFill(getRect() + pos, colorRed);
      if (getDown()) {
         // and white when pressed
         Primitives::rectFill(getRect() + pos, colorWhite);
      }
   }
}



// namespace MainMenu
};
