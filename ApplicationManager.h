#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int ID;

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType&) ;//Creates an action and executes it
	void ReSet(); // Gets all the figure again by grouping deleted list with figlist
	void SaveAll(ofstream &);	//saves all figures
	void DeleteAll();			//deletes all figures
	void setID(int Fcount);		//sets the ID value in AppManager
	void DeleteSelectedFigure();			//Removes a figure from the list and updates it
		
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int getFigCount() const;				//WHY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	CFigure* GetRandomFigure(ActionType) const; // it chooses the RandomFig and calculate the number of it
	int  RandomFigureCount(ActionType act,CFigure*Rand); //Gets The Number of The Random Figure
	
	void setSelectedFig(CFigure *);
	CFigure * getSelectedFig() const;
	int getSelectedFigInd() const;

	void SetClipboard(CFigure*);
	CFigure * GetClipboard()const;

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif