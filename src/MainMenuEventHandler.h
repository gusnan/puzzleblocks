/**
 *
 *	This file is part of PuzzeBlocks
 *	Copyright (C) 2020 Andreas Rönnquist
 *
 *	PuzzeBlocks is free software: you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as published
 *	by the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	PuzzeBlocks is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with PuzzeBlocks.
 *	If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __HEADER_EXAMPLE_EVENTHANDLER_
#define __HEADER_EXAMPLE_EVENTHANDLER_

/**
 * This is an Eventhandler that takes care of the keyboard events, mouse motion
 *	events, and the Quit events. (This event is pushed when you press the close
 * window button for example)
 */
class MainMenuEventHandler : public EventHandler
{
public:

   /**
    * Handle keyboard presses and releases
    */
   virtual bool handleKeyboard(KeyEvent &keyEvent);

};


#endif /*__HEADER_EXAMPLE_EVENTHANDLER_*/
