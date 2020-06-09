#include "CRectangle.h"
#include <string>
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	if (getSecondX() - getFirstX() > getSecondY() - getFirstY())
	{
		length = getSecondX() - getFirstX(); width = getSecondY() - getFirstY();
	}
	else
	{
		width = getSecondX() - getFirstX(); length = getSecondY() - getFirstY();
	}
}

CRectangle::CRectangle()
{}


string CRectangle::GetType() const
{
	return "Rectangle";
}

bool CRectangle::IsFilled() const
{
	return FigGfxInfo.isFilled;
}

color CRectangle::GetColor() const
{
	if(FigGfxInfo.isFilled)//proplem here if the shape is non filled it will return black so i need this condition
		return FigGfxInfo.FillClr;
	return GOLD;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

int CRectangle::getFirstX() const {
	if (Corner1.x > Corner2.x)
		return Corner2.x;
	else
		return Corner1.x;
}

int CRectangle::getSecondX() const {
	if (Corner1.x > Corner2.x)
		return Corner1.x;
	else
		return Corner2.x;
}

int CRectangle::getFirstY() const {
	if (Corner1.y > Corner2.y)
		return Corner2.y;
	else
		return Corner1.y;
}

int CRectangle::getSecondY() const {
	if (Corner1.y > Corner2.y)
		return Corner1.y;
	else
		return Corner2.y;
}

bool CRectangle::inSegment(int a, int b) const{
	if (a>getFirstX() && a<=getSecondX() && b>getFirstY() && b<=getSecondY())
		return true;
	return false;
}

void CRectangle::PrintInfo(Output *pOut) const
{
	string str = "Selected figure is Rectangle. ID is " + to_string(ID) + ". Length = " + to_string(length) + ". Width = " + to_string(width);
	pOut->PrintMessage(str);
}

void CRectangle::Save(ofstream &out)
{
	out<<"RECT\t"<<getID()<<"\t"<<Corner1.x<<"\t"<<Corner1.y<<"\t"<<Corner2.x<<"\t"<<Corner2.y<<"\t"<<GetColorName(FigGfxInfo.DrawClr)<<"\t"<<GetColorName(GetColor())<<endl;
}

void CRectangle::Load(ifstream & in)
{
	string Dc,Fc;
	in>>ID>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y>>Dc>>Fc;

	FigGfxInfo.DrawClr=StringToColor(Dc);

	if(Fc=="NO_FILL")
		FigGfxInfo.isFilled=false;

	else 
	{
		FigGfxInfo.FillClr=StringToColor(Fc);
		FigGfxInfo.isFilled=true;
	}

	Selected=false;
	Choosed=false;
	
	if (getSecondX() - getFirstX() > getSecondY() - getFirstY())
	{
		length = getSecondX() - getFirstX(); width = getSecondY() - getFirstY();
	}
	else
	{
		width = getSecondX() - getFirstX(); length = getSecondY() - getFirstY();
	}
}


CFigure * CRectangle:: paste(Point p)
{
	CRectangle * rect = new  CRectangle(Corner1,Corner2,FigGfxInfo);

	Point cen;
	cen.x=(Corner1.x+Corner2.x)/2;
	cen.y=(Corner1.y+Corner2.y)/2;
	rect->Corner1.x=p.x-cen.x+Corner1.x;
	rect->Corner1.y=p.y-cen.y+Corner1.y;
	rect->Corner2.x=p.x-cen.x+Corner2.x;
	rect->Corner2.y=p.y-cen.y+Corner2.y;
	return rect;
}

CFigure * CRectangle::copy()
{
	CFigure* ptr=new  CRectangle(Corner1,Corner2,FigGfxInfo);
	return ptr;
}