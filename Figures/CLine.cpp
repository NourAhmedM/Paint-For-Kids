#include "CLine.h"
#include <cmath>
#include <string>
#include <fstream>


CLine::CLine(Point st, Point en, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo){

	start = st;
	end = en;
	length = sqrt(pow((end.x-start.x), 2) + pow((end.y - start.y), 2));

}

CLine::CLine()
{}

void CLine::Draw(Output *op) const{
	op->DrawLine(start, end, FigGfxInfo, Selected);
}

Point CLine::getStart() const { return start; }

Point CLine::getEnd() const { return end;}

double CLine::CalcStartDistance(Point p) const{
	return sqrt( pow(start.x-p.x, 2) + pow(start.y - p.y, 2));
}

double CLine::CalcEndDistance(Point p) const{
	return sqrt(pow((end.x-p.x), 2) + pow((end.y - p.y), 2));
}

string CLine::GetType() const
{
	return "Line";
}

bool CLine::IsFilled() const
{
	return true;
}

color CLine::GetColor() const
{
	return FigGfxInfo.DrawClr;
}

bool CLine::inSegment(int a, int b) const{
	Point p;
	p.x = a; p.y = b;
	if (CalcStartDistance(p) + CalcEndDistance(p) >= length && CalcStartDistance(p) + CalcEndDistance(p) <= length + 1)
		return true;
	return false;
}

void CLine::Save(ofstream & out)
{
	out <<"LINE\t"<<getID()<<"\t"<<start.x<<"\t"<<start.y<<"\t"<<end.x<<"\t"<<end.y<<"\t"<<GetColorName(GetColor())<<endl;
}

void CLine::Load(ifstream & in)
{
	string S;
	in>>ID>>start.x>>start.y>>end.x>>end.y>>S;

	FigGfxInfo.DrawClr=StringToColor(S);

	Selected=false;
	Choosed=false;

	length = sqrt(pow((end.x-start.x), 2) + pow((end.y - start.y), 2));
}

void CLine::PrintInfo(Output *pOut) const
{
	string str = "Selected figure is Line. ID is " + to_string(ID) + ". Start point is (" + to_string(start.x) + ", " + to_string(start.y) + "), end point is (" + to_string(end.x) + ", " + to_string(end.y) + ")";
	pOut->PrintMessage(str);
}

CFigure * CLine:: paste(Point p )
{
	CLine* li=new CLine(start,end,FigGfxInfo);
	Point cen;

	cen.x=(start.x+end.x)/2;
	cen.y=(start.y+end.y)/2;
	li->start.x=p.x-cen.x+start.x;
	li->start.y=p.y-cen.y+start.y;
	li->end.x=p.x-cen.x+end.x;
	li->end.y=p.y-cen.y+end.y;


	return li;
}

CFigure * CLine:: copy()
{
	CFigure* ptr=new CLine(start,end,FigGfxInfo);
	return ptr;
}