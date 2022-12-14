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
#ifndef __HEADER_DATA_
#define __HEADER_DATA_

class Data
{
public:
   static Data &instance();

   std::shared_ptr<Bitmap> mouseBitmap;
   std::shared_ptr<Font> font;

   std::shared_ptr<Bitmap> blocksBitmap;

   std::shared_ptr<Bitmap> buttonStandard;
   std::shared_ptr<Bitmap> buttonPressed;

   std::shared_ptr<Bitmap> gem;

   void doneData();

protected:
   Data();
   virtual ~Data();

private:

   Data(const Data &inData);
   Data &operator=(const Data &inData);

   void initData();


};
 
#endif /*__HEADER_DATA_*/
 