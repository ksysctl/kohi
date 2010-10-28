/*
 * Kohi (coffee in japanese) is a library that provides some similar functions
 * to the library of Borland, conio.
 *
 * Copyright (C) 2008 Moisés Brenes, http://blog.mbrenes.com
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
 
/* @ gin
 * language : c
 * author   : Moisés Brenes - March 12, 2006
 * modify   : Moisés Brenes - November 28, 2008
 *
 * blog > blog.mbrenes.com
 */

#include "kohi.h"

int __background = RESET_COLOR;	/* default background color */
int __color = RESET_COLOR;		/* default text color */

/* This sets the background color for the terminal
 */
void textbackground(const int background_)
{
	__fpurge(stdin);
	__background = background_;

	if (((background_ >= 0) && (background_ <= 7)) || ((background_ >= 10) && (background_ <= 17)))
	{
		if ((background_ >= 10) && (background_ <= 17))
			__background = (background_ - 10);
	}
	else
	{
		__background = RESET_COLOR;
	}

	if ((__color >= 0) && (__color <= 7))
	{
		printf("\033[0;3%d;4%dm",__color,__background);
	}
	else
	{
		if ((__color >= 10) && (__color <= 17))
			printf("\033[1;3%d;4%dm",(__color - 10),__background);
		else
			printf("\033[0;3%d;4%dm",RESET_COLOR,__background);
	}
}

/* This sets the text color for the terminal
 */
void textcolor(const int color_)
{
	__fpurge(stdin);
	__color = color_;

	if ((__color >= 0) && (__color <= 7))
	{
		printf("\033[0;3%d;4%dm",__color,__background);
	}
	else
	{
		if ((__color >= 10) && (__color <= 17))
		{
			printf("\033[1;3%d;4%dm",(__color - 10),__background);
		}
		else
		{
			printf("\033[0;3%d;4%dm",RESET_COLOR,__background);
		}
	}
}

/* This sets the position of a character on the screen
 */
void gotoxy(int x_, int y_)
{
	if (x_ < 0)
		x_ = 0;

	if (y_ < 0)
		y_ = 0;
	
	__fpurge(stdin);
	printf("\033[%d;%df", y_, x_);
}

/* This clears the console
 */
void clrscr()
{
	__fpurge(stdin);
	printf("\033[2J\033[1;1H");
}

/* This erases the characters from the current line
 */
void clrline()
{
	__fpurge(stdin);
	printf("\033[K");
}

/* This gets a character from keyboard, does not echo to screen.
 */
char getch()
{
struct termios SET_STORED;
struct termios SET_NEW;
char c;

	tcgetattr(0, &SET_STORED);
	SET_NEW = SET_STORED;

	SET_NEW.c_lflag     = ~(ECHO|ICANON);
	SET_NEW.c_cc[VTIME] = 0;
	SET_NEW.c_cc[VMIN]  = 1;

	tcsetattr(0, TCSANOW, &SET_NEW);
	__fpurge(stdin);
	c = getchar();
	tcsetattr(0, TCSANOW, &SET_STORED);

return c;
}

/* This gets a character from keyboard, does echo to screen.
 */
char getche()
{
struct termios SET_STORED;
struct termios SET_NEW;
char c;

	tcgetattr(0, &SET_STORED);
	SET_NEW = SET_STORED;

	SET_NEW.c_lflag     = ~(ICANON);
	SET_NEW.c_cc[VTIME] = 0;
	SET_NEW.c_cc[VMIN]  = 1;

	tcsetattr(0, TCSANOW, &SET_NEW);
	__fpurge(stdin);
	c = getchar();
	tcsetattr(0, TCSANOW, &SET_STORED);

return c;
}
