#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Choosed=false;
	ID=0;
}

CFigure::CFigure()
{}


void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::setID(int id)
{ ID = (id>0)? id:0; }

int CFigure::getID() const
{ return ID; }

void CFigure::SetChoosed(bool s)
{ Choosed=s; }

bool CFigure::IsChoosed() const 
{ return Choosed; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}