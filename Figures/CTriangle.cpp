#include "CTriangle.h"
#include <string>
#include <fstream>


//Functions needed in inSegment function
double sign (Point p1, Point p2, Point p3)
{
	return (p1.x-p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

int MaxOf2(Point p1, Point p2){
	if (p1.x > p2.x)
		return p1.x;
	return p2.x;
}

int MaxOF3(Point p1, Point p2, Point p3){
	if (p1.x >= MaxOf2(p2, p3))
		return p1.x;
	return MaxOf2(p2, p3);
}
//////////////////////////////////////////

CTriangle::CTriangle(Point P1, Point P2,Point P3,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{

	if (MaxOF3(P1, P2, P3) == P1.x){
		V3 = P1;
		if (MaxOf2(P2, P3) == P2.x)
		{V2 = P2; V1 = P3;}
		else
		{V2 = P3; V1 = P2;}
	}

	else if (MaxOF3(P1, P2, P3) == P2.x){
		V3 = P2;
		if (MaxOf2(P1, P3) == P1.x)
		{V2 = P1; V1 = P3;}
		else
		{V2 = P3; V1 = P1;}
	}

	else if (MaxOF3(P1, P2, P3) == P3.x){
		V3 = P3;
		if (MaxOf2(P2, P1) == P1.x)
		{V2 = P1; V1 = P2;}
		else
		{V2 = P2; V1 = P1;}
	}
}

CTriangle::CTriangle()
{}

string CTriangle::GetType() const
{
	return "Triangle";
}

bool CTriangle::IsFilled() const
{
	return FigGfxInfo.isFilled;
}

color CTriangle::GetColor() const
{
	if(FigGfxInfo.isFilled)//proplem here if the shape is non filled it will return black so i need this condition
		return FigGfxInfo.FillClr;
	return GOLD;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(V1, V2,V3,FigGfxInfo, Selected);
}

bool CTriangle::inSegment(int x, int y) const{
	Point p;
	p.x = x;
	p.y = y;
	bool b1, b2, b3;
	b1 = sign(p, V1, V2) < 0.0f;
	b2 = sign(p, V2, V3) < 0.0f;
	b3 = sign(p, V3, V1) < 0.0f;
	return ((b1 == b2) && (b2 == b3));
}

void CTriangle::PrintInfo(Output *pOut) const
{
	string str = "Selected figure is Triangle. ID is " + to_string(ID) + ". Vertex1 (" + to_string(V1.x) + ", " + to_string(V1.y) + "). Vertex2 (" + to_string(V2.x) + ", " + to_string(V2.y) + "). Vertex3 (" + to_string(V3.x) + ", " + to_string(V3.y) + ")";
	pOut->PrintMessage(str);
}

void CTriangle::Save(ofstream &out)
{
	out<<"TRIANG\t"<<getID()<<"\t"<<V1.x<<"\t"<<V1.y<<"\t"<<V2.x<<"\t"<<V2.y<<"\t"<<V3.x<<"\t"<<V3.y<<"\t"<<GetColorName(FigGfxInfo.DrawClr)<<"\t"<<GetColorName(GetColor())<<endl;
}

void CTriangle::Load(ifstream &in)
{
	string Dc,Fc;
	in>>ID>>V1.x>>V1.y>>V2.x>>V2.y>>V3.x>>V3.y>>Dc>>Fc;
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

}

CFigure *CTriangle:: paste(Point p)
{
	CTriangle *tri = new CTriangle(V1,V2,V3,FigGfxInfo);
	Point cen;
	cen.x=(V1.x+V2.x+V3.x)/3;
	cen.y=(V1.y+V2.y+V3.y)/3;
	tri->V1.x=p.x-cen.x+V1.x;
	tri->V2.x=p.x-cen.x+V2.x;
	tri->V3.x=p.x-cen.x+V3.x;
	tri->V1.y=p.y-cen.y+V1.y;
	tri->V2.y=p.y-cen.y+V2.y;
	tri->V3.y=p.y-cen.y+V3.y;

	return tri;
}

CFigure *CTriangle:: copy()
{
	CFigure *ptr=new CTriangle(V1,V2,V3,FigGfxInfo);
	return ptr;
}