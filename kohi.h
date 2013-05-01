/*
 * Kohi (coffee in japanese) is a library that provides some similar functions
 * to the library of Borland, conio.
 *
 * Copyright (C) 2008 Moisés Brenes
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
 
/* @ gin - gin.github.com
 * language : c
 * author   : Moisés Brenes - March 12, 2006
 * modify   : Moisés Brenes - November 28, 2008
 *
 */

#ifndef __KOHI_H
	#define __KOHI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdio.h>
#include <stdio_ext.h>
#include <fcntl.h>
#include <termios.h>

#define BLACK         0
#define RED           1
#define GREEN         2
#define BROWN         3
#define BLUE          4
#define MAGENTA       5
#define CYAN          6
#define LIGHTGRAY     7
#define RESET_COLOR   9
#define DARKGRAY     10
#define LIGHTRED     11
#define LIGHTGREEN   12
#define YELLOW       13
#define LIGHTBLUE    14
#define LIGHTMAGENTA 15
#define LIGHTCYAN    16
#define WHITE        17

void textbackground(const int);
void textcolor(const int);
void gotoxy(const int, const int);
void clrscr();
void clrline();
char getch();
char getche();

#ifdef  __cplusplus
}
#endif

#endif /* kohi.h */
