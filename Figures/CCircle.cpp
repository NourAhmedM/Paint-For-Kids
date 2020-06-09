#include "CCircle.h"
#include <cmath>
#include <string>
#include <fstream>


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P1;
	point = P2;
	radius = sqrt( pow(point.x - center.x,2) + pow(point.y - center.y, 2));
	
}

CCircle::CCircle()
{}

string CCircle::GetType() const
{
	return "Circle";
}

bool CCircle::IsFilled() const
{
	return FigGfxInfo.isFilled;
}

color CCircle::GetColor() const
{
	if(FigGfxInfo.isFilled)//proplem here if the shape is non filled it will return black so i need this condition
	return FigGfxInfo.FillClr;
	return GOLD;
}

void CCircle::Draw(Output* pOut) const
{	
	pOut->DrawCirc(center, point, FigGfxInfo, Selected);
}

double CCircle::calcDistFromCenter(Point p) const {
	return sqrt( pow(p.x - center.x,2) + pow(p.y - center.y, 2));
}

bool CCircle::inSegment(int a, int b) const {
	Point p;
	p.x = a; p.y = b;
	if (calcDistFromCenter(p) <= radius)
		return true;
	return false;
}

void CCircle::PrintInfo(Output *pOut) const
{
	string str = "Selected figure is circle. ID is " + to_string(ID) + ". Center is (" + to_string(center.x) + ", " + to_string(center.y) + "). Radius is " + to_string(radius);
	pOut->PrintMessage(str);
}

CFigure * CCircle:: paste(Point p )
{
	CCircle* circ=new  CCircle(center,point,FigGfxInfo);
	circ->center.x=p.x;
	circ->center.y=p.y;
	circ->point.x=p.x+radius;
	circ->point.y=p.y;
	return circ;
}

void CCircle::Save(ofstream & out )
{
	out<<"CIRCLE\t"<<getID()<<"\t"<<center.x<<"\t"<<center.y<<"\t"<<radius<<"\t"<<GetColorName(FigGfxInfo.DrawClr)<<"\t"<<GetColorName(GetColor())<<endl;
}

void CCircle::Load(ifstream &in)
{
	string Dc,Fc;

	in>>ID>>center.x>>center.y>>radius>>Dc>>Fc;

	FigGfxInfo.DrawClr=StringToColor(Dc);

	if(Fc=="NO_FILL")
		FigGfxInfo.isFilled=false;

	else 
	{
		FigGfxInfo.FillClr=StringToColor(Fc);
		FigGfxInfo.isFilled=true;
	}

	point.x=center.x;
	point.y=center.y+radius;

	Selected=false;
	Choosed=false;
}

CFigure * CCircle:: copy()
 {
	CFigure* cir=new CCircle(center,point,FigGfxInfo);
	return cir;
 }