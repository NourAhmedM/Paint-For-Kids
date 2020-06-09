#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

color StringToColor(string S);
string GetColorName(color c);

//Base class for all figures
class CFigure
{
protected:

	int ID;			//ID count
	bool Selected;		//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	GfxInfo Trash;		//Figure graphis of copied figure
	bool Choosed;		//to check in type mode if it is choosed remove it from screen

public:

	CFigure(GfxInfo FigureGfxInfo);
	CFigure();


	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	int getID() const;
	void setID(int);

	virtual color GetColor() const = 0;//gets the fill clr in case of tri-rect-circ and draw clr in case of line
	
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	virtual bool inSegment(int , int) const = 0;//returns pointer to the figure
	
	virtual CFigure * paste(Point ) = 0;
	
	virtual CFigure * copy() = 0;
	
	virtual string GetType() const = 0;
	
	virtual bool IsFilled() const = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar

	bool IsChoosed() const ;
	
	void SetChoosed(bool s=true);
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
};

#endif