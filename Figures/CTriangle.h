#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point V1;	
	Point V2;
	Point V3;

public:

	CTriangle(Point , Point,Point , GfxInfo FigureGfxInfo );
	CTriangle();
	
	virtual color GetColor() const;//gets the fill clr in case of tri-rect-circ and draw clr in case of line
	
	virtual void Draw(Output* pOut) const;		//Draw the figure
	
	virtual bool inSegment(int , int) const;//returns pointer to the figure
	
	virtual CFigure * paste(Point );
	
	virtual CFigure * copy();
	
	virtual string GetType() const;
	
	virtual bool IsFilled() const;

	virtual void Save(ofstream &OutFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const;	//print all figure info on the status bar

};


#endif