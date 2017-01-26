//---------------------------------------------------------------------
//
// Class: AsciiDraw
//
//
// Purpose: This class adds a little more control over our simple little DOS standard output.
//			It provides a few classes to "mimic" simple graphics, and allow a little more 
//			interesting project output. 
//
//
//---------------------------------------------------------------------
#pragma once

#include <windows.h>
#include <math.h>
#include <iostream>

using namespace std;



const char DULC	= char(201);		//double Upper Left Corner
const char DURC	= char(187);		//double Upper Right Corner
const char DBLC	= char(200);		//double Bottom Left Corner
const char DBRC	= char(188);		//double Bottom Right Corner
const char DHTB	= char(205);		//double Horizontal Top Bar
const char DVB	= char(186);		//double Verticle Size Bar
const char DT	= char(206);		//Double T Junction
const char DTD	= char(203);		//Double T Down
const char DTU	= char(202);		//Double T Up
const char DTR	= char(204);		//Double T Right
const char DTL  = char(185);		//Double T Left
const char SULC	= char(218);		//Single Upper Left Corner
const char SURC	= char(191);		//Single upper Right Corner
const char SBLC	= char(192);		//Single Bottom Left Corner
const char SBRC	= char(217);		//Single Bottom Right Corner
const char SVB	= char(179);		//Single Verticle Bar
const char SHB	= char(196);		//Single Horizontal Bar
const char ST	= char(197);		//Single T Junction
const char STD  = char(194);		//Single T Points Down
const char STU  = char(193);		//Single T Points Up
const char STR  = char(195);		//Single T Points Right
const char STL  = char(180);		//Single T Points Left

//Colors by pre-defined constants
////////////////////////////////////////////////////////////////////////////////
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define AQUA			3
#define RED				4
#define PURPLE			5
#define YELLOW			6
#define WHITE			7
#define GRAY			8
#define BRIGHT_BLUE		9
#define BRIGHT_GREEN	10
#define BRIGHT_AQUA		11
#define BRIGHT_RED		12
#define BRIGHT_PURPLE	13
#define BRIGHT_YELLOW	14
#define BRIGHT_WHITE	15

class AsciiDraw
{
private:
	int		BinToDecimal(char *);
	void	SetColors();
	COORD	BaseXY;
	COORD	CurrXY;
	int		ForeColor;
	int		BackColor;
public:
			AsciiDraw(void);
	COORD	GetXY();
	int		GetX();
	int		GetY();
	COORD	GetBaseXY();
	int		GetBaseX();
	int		GetBaseY();

	void	SetBaseXY(int,int);
	void	SetBaseXY(COORD);
	void	SetXY(int,int);
	void	SetXY(COORD);
	void	SetX(int);
	void	SetY(int);

	void	SetBackgroundColor(char *);		
	void	SetBackgroundColor(int);		
	void	SetColors(char *);					
	void	SetColors(int,int);		
	void	SetForegroundColor(char *);
	void	SetForegroundColor(int);

	void	PrintRotator(int ,int ,int ,int);
};

