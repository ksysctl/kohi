/*
 * Kohi (coffee in japanese) is a library that provides some similar functions
 * to the library of Borland, conio.
 *
 * Copyright (C) 2008 Moisés Brenes, http://mbrenes.blogspot.com
 *  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Any non-GPL usage of this software or parts of this software is strictly
 * forbidden.
 */
 
/* @ shakka
 * language : c
 * author   : Moisés Brenes - March 12, 2006
 * modify   : Moisés Brenes - November 28, 2008
 *
 * blog > mbrenes.blogspot.com
 * web  > radamanthys.homelinux.org
 * mail > moises.brenes@gmail.com
 */

#include "kohi.h"

int main()
{
/* This initializes some properties
   of the console 
 */
	textbackground(BLUE);
	textcolor(YELLOW);
	clrscr();
	
	gotoxy(10,10); printf("Kohi library\n");
	gotoxy(10,11); printf(">> This text will be erased.");
	gotoxy(10,12); printf(">>");
	getch();
	
	gotoxy(10,11); clrline();
	getch();
	
/* This reset properties
   of the console
 */	
	textbackground(RESET_COLOR);
	textcolor(RESET_COLOR);
	clrscr();	
	
return 0;
}
