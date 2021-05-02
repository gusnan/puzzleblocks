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

#ifndef __HEADER_EVENTHANDLER_MAIN_MENU
#define __HEADER_EVENTHANDLER_MAIN_MENU

/**
 * This is an Eventhandler that takes care of the keyboard events, mouse motion
 *	events, and the Quit events. (This event is pushed when you press the close
 * window button for example)
 */
class EventHandlerMainMenu : public EventHandler /*, std::enable_shared_from_this<EventHandler>*/
{
public:

   EventHandlerMainMenu();
   virtual ~EventHandlerMainMenu();

   /**
    * Handle keyboard presses and releases
    */
   virtual bool handleKeyboard(KeyEvent &keyEvent);

};


#endif /*__HEADER_EVENTHANDLER_MAIN_MENU*/
