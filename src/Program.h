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
#ifndef __HEADER_PROGRAM_
#define __HEADER_PROGRAM_


class Program
{
public:
   static Program &instance();

   bool getQuit();
   void setQuit(bool inQuit = true);

   void mainLoop();

protected:
   Program();

   virtual ~Program();

private:
   Program(const Program &inProgram);

   Program &operator=(const Program &inProgram);

   void doneProgram();

   bool m_Quit;

};


#endif /*__HEADER_PROGRAM_*/
