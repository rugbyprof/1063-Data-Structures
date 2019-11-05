#include "AsciiDraw.h"

AsciiDraw::AsciiDraw(void)
{
	ForeColor=8;
	BackColor=0;
	BaseXY.X=0;
	BaseXY.Y=0;
	CurrXY.Y=0;
	CurrXY.X=0;
}

//Private Methods///////////////////////////////////////////////////////////////

/** BinToDecimal
* 
* @param	char * Binary - String of 0's and 1's to be converted to Decimal.
* @return	int - Decimal equivalent.
*/
int AsciiDraw::BinToDecimal(char * Binary){
        double total=0;
        for(int i=0,p=7;i<8;i++,p--){
                if(Binary[i]=='1')
                total += 1.0*pow(2.0,p);
        }
        return (int)total;
}

/** SetColors
* 
* Sets the Foreground and Background colors of the dos window, using the data
* members ForeColor and BackColor.
*
* @param	void
* @return	void
*/
void AsciiDraw::SetColors()
{
    int Buffer; 							//Buffer to hold both colors
	Buffer = BackColor*16;					//Shift background left by 4 so 1001 would be 10010000
	Buffer =  Buffer + ForeColor;			//Add  BackGround with ForeGround color, so:
											//	1 0 0 1 0 0 0 0     (BRIGHT_BLUE background)
											//+ 0 0 0 0 1 1 1 0		(BRIGHT_YELLOW foreground)
											//---------------
											//  1 0 0 1 1 1 1 0		Combined foreground and background
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Buffer);
}

//Public Methods////////////////////////////////////////////////////////////////

//GETTERS///////////////////////////////////////////////////////////////////////

/** GetXY
* 
* Returns the current position of the cursor.
*
* @param	void
* @return	COORD
*/
COORD AsciiDraw::GetXY()
{
	return CurrXY;
}

/** GetX
* 
* Returns the current X coordinate.
*
* @param	void
* @return	int
*/
int AsciiDraw::GetX()
{
	return CurrXY.X;
}

/** GetY
* 
* Returns the current Y coordinate.
*
* @param	void
* @return	int
*/
int AsciiDraw::GetY()
{
	return CurrXY.Y;
}


//SETTERS///////////////////////////////////////////////////////////////////////
/** SetBaseXY
* 
* Sets the BaseXY of the current object. This is used to remember for example, the
* upper left corner of a box or something, so calculations can done based on this 
* location.
*
* @param	int X - new X coord
* @param	int Y - new Y coord
* @return	void
*/
void AsciiDraw::SetBaseXY(int x, int y)
{
	BaseXY.X = x;
	BaseXY.Y = y;
}

/** SetBaseXY
* 
* Sets the BaseXY of the current object. This is used to remember for example, the
* upper left corner of a box or something, so calculations can done based on this 
* location.
*
* @param	COORD P - new base XY position using P.X and P.Y
* @return	void
*/
void AsciiDraw::SetBaseXY(COORD P)
{
	BaseXY.X = P.X;
	BaseXY.Y = P.Y;
}

/** SetXY
* 
* Moves the cursor of the dos window to the specified X,Y where Top Left = 0,0 and
* X moves right and left and Y moves up and down.
*
* @param	int X - new X position
* @param	int Y - new Y position
* @return	void
*/
void AsciiDraw::SetXY(int x, int y)
{
	CurrXY.X = x;
	CurrXY.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurrXY);
}

/** SetXY
* 
* Moves the cursor of the dos window to the specified X,Y where Top Left = 0,0 and
* X moves right and left and Y moves up and down.
*
* @param	COORD P - new XY position using P.X and P.Y
* @return	void
*/
void AsciiDraw::SetX(int x)
{
	CurrXY.X = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurrXY);
}

/** SetXY
* 
* Moves the cursor of the dos window to the specified X,Y where Top Left = 0,0 and
* X moves right and left and Y moves up and down.
*
* @param	COORD P - new XY position using P.X and P.Y
* @return	void
*/
void AsciiDraw::SetY(int y)
{
	CurrXY.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurrXY);
}

/** SetXY
* 
* Moves the cursor of the dos window to the specified X,Y where Top Left = 0,0 and
* X moves right and left and Y moves up and down.
*
* @param	COORD P - new XY position using P.X and P.Y
* @return	void
*/
void AsciiDraw::SetXY(COORD P)
{
	CurrXY.X = P.X;
	CurrXY.Y = P.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CurrXY);
}

/** SetBackgroundColor
*
* Uses a binary string to set the Background colors where bits are numbered from right to left 1 - 4.
* 
* Setting:		 Bright Red Green Blue
* Bit:			  4    3    2    1
* Example: "1001" would make the background Bright Blue
* @param	char * binary
* @return	void
*/
void AsciiDraw::SetBackgroundColor(char * binary)
{
    BackColor = BinToDecimal(binary);
    SetColors();
}

/** SetBackgroundColor
*
* Uses an int value to change the Background color
*
* Example: 13 would make the background Light Purple
* @param	int color
* @return	void
*/
void AsciiDraw::SetBackgroundColor(int color)
{	
	BackColor = color;
	SetColors();
}

/** SetColors
*
* Uses a binary string to set the Background and Foreground colors where bits 
* are numbered from right to left 1 - 8.
*						Background			Foreground
* Setting:		Bright Red Green Blue Bright Red Green Blue
* Bit:			   8    7    6     5     4    3    2    1
* Example: "11101010" would make the background Bright Yellow and the foreground Bright Green.
* @param	char * binary
* @return	void
*/
void AsciiDraw::SetColors(char * binary)
{
	int ColorVal = BinToDecimal(binary);
	BackColor = ColorVal >> 4;
	ForeColor = ColorVal & 0xF;
    SetColors();
}

/** SetColors
*
* Uses integer values to set foreground and background colors.
* 0 = Black		8 = Gray
* 1 = Blue		9 = Light Blue
* 2 = Green		10 = Light Green
* 3 = Aqua		11 = Light Aqua
* 4 = Red		12 = Light Red
* 5 = Purple	13 = Light Purple
* 6 = Yellow	14 = Light Yellow
* 7 = White		15 = Bright White
* @param	int BackGround
* @param	int ForeGround
* @return	void
*/
void AsciiDraw::SetColors(int BackGround,int ForeGround)
{
	ForeColor = ForeGround;
	BackColor = BackGround;
	SetColors();
}

/** SetForegroundColor
*
* Uses a binary string to set the Foreground colors where bits are numbered from right to left 1 - 4.
* 
* Setting:		 Bright Red Green Blue
* Bit:			   4    3    2    1
* Example: "1001" would make the Foregound Bright Blue
* @param	char * binary
* @return	void
*/
void AsciiDraw::SetForegroundColor(char * binary)
{
	ForeColor = BinToDecimal(binary);
	cout<<ForeColor<<endl;
    SetColors();
}

/** SetForegroundColor
*
* Uses an int value to change the Background color
*
* Example: 13 would make the foreground Light Purple
* @param	int color
* @return	void
*/
void AsciiDraw::SetForegroundColor(int color)
{
	ForeColor = color;
    SetColors();
}

void AsciiDraw::PrintRotator(int times,int x,int y,int speed){
	for(int i=0;i<times;i++){
			SetXY(x,y);
			cout<<char(221);
			Sleep(speed);
			SetXY(x,y);
			cout<<char(220);
			Sleep(speed);
			SetXY(x,y);
			cout<<char(222);
			Sleep(speed);
			SetXY(x,y);
			cout<<char(223);
			Sleep(speed);
	}
}


//"cpp": "cd $dir && clear && echo '\n' && g++ -std=c++11 *.cpp -o runit && cd $dir && ./runit"
