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
#ifndef __HEADER_BUTTON_MAINMENU_
#define __HEADER_BUTTON_MAINMENU_


namespace MainMenu {

/**
 *
 */
class Button : public GusGui::Button {
public:
   Button(const Rect &rect, const std::string &text);
   virtual ~Button();

   void draw(const Vector2d& pos, float alpha = 1.0);
protected:

};

// end of namespace MainMenu
};

#endif /*__HEADER_BUTTON_BUTTON_*/
