/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRInteractorStyleSwipeDial.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRInteractorStyleSwipeDial.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include <vector>
#include <deque>
#include <utility>	//std::pair
#include <iterator>
#include "vtkOpenVRRenderWindowInteractor.h"


vtkStandardNewMacro(vtkOpenVRInteractorStyleSwipeDial);


//PIMPL to use STL (ref: VTKUsersGuide, 303)
typedef std::pair<double, double> AngleRadius;
typedef std::deque<AngleRadius> AngleRadiusBase;
class vtkDequeAngleRadius:
	public AngleRadiusBase {};
		


	

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::vtkOpenVRInteractorStyleSwipeDial()
{
	this->AngleRadiusRecord = new vtkDequeAngleRadius;

	
}

//----------------------------------------------------------------------------
vtkOpenVRInteractorStyleSwipeDial::~vtkOpenVRInteractorStyleSwipeDial()
{
	delete this->AngleRadiusRecord;


}

/*
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::OnSwipe()	//adapted from vtkInteractorStyle3D::OnMouseMove()
{
	//NOTE May be useful on the future: vr::VREvent_ButtonTouch

	//Do I need another function where to set state == VTKIS_SWIPE ? I think so.
	switch(this->State)
	{
		//case VTKIS_ ...
	}

}

void vtkOpenVRInteractorStyleSwipeDial::OnLongTap()
{
	int x = this->Interactor->GetEventPosition()[0];
	int y = this->Interactor->GetEventPosition()[1];
	this->FindPokedRenderer(x, y);
	if (this->CurrentRenderer == NULL)
	{
		return;
	}
}
*/


//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::TrackFinger()
{
	//current renderer
	if (this->Interactor)
	{
		int pointer = this->Interactor->GetPointerIndex();
		this->FindPokedRenderer(this->Interactor->GetEventPositions(pointer)[0],
		                        this->Interactor->GetEventPositions(pointer)[1]);
	}

	//Touchpad position (-1,1)
	vtkOpenVRRenderWindowInteractor *rwi = 
		static_cast<vtkOpenVRRenderWindowInteractor *>(this->Interactor);
	float *tpos = rwi->GetTouchPadPosition();

	//Update record: Add new values and remove old values if maximum is reached:
	if(this->AngleRadiusRecord->size() == MAX_REC)
	{
		this->AngleRadiusRecord->pop_front();
	}
	this->AngleRadiusRecord->push_back(AngleRadius(tpos[0], tpos[1]));

	// Find out direction of swipe
	switch(this->GetSwipeDirection())
	{
	case -1:	//Anti-clockwise
		this->DecValue();
		break;
	case 1:		//Clockwise
		this->IncValue();
		break;
	default:
		break;
	}
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetAngle(int pos)
{
	return this->AngleRadiusRecord->at(pos).first;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetRadius(int pos)
{
	return this->AngleRadiusRecord->at(pos).second;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetDiffAngle()
{
	//Difference between first-last?
	//Sum all of them and get average? (used to get swiping speed)


	/*double angle = 0.0;
	std::deque<AngleRadius>::iterator it = AngleRadiusRecord->begin();
	for (it; it != AngleRadiusRecord->end(); ++it)
	{
		angle += it->
	}*/
	return -1.;
}

//----------------------------------------------------------------------------
double vtkOpenVRInteractorStyleSwipeDial::GetAvgRadius()
{
	double radius = 0.0;
	std::deque<AngleRadius>::iterator it = AngleRadiusRecord->begin();
	for (it; it != AngleRadiusRecord->end(); ++it)
	{
		radius += it->second;
	}
	radius /= AngleRadiusRecord->size();
	return radius;
}

//----------------------------------------------------------------------------
int vtkOpenVRInteractorStyleSwipeDial::GetSwipeDirection()
{
	int dir = 0;
	std::deque<AngleRadius>::iterator it1 = AngleRadiusRecord->begin();
	std::deque<AngleRadius>::iterator it2 = ++(AngleRadiusRecord->begin());
	for (it1, it2; it2 != AngleRadiusRecord->end(); ++it1, ++it2)
	{
		if (it1->first - it2->first < -1e4) dir++;
		else if(it2->first - it1->first < -1e4) dir--;
		//else, too close to consider movement.
	}

	//Normalize to {-1, 0, 1}
	if(dir != 0) dir /= abs(dir);
	return dir;
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::DecValue()
{
	double AvgRadius = this->GetAvgRadius();
	double DiffAngle = this->GetDiffAngle();
	
	//Modification can be fine or rough, depending on avg radius and diff angle.
	//Think about an algorithm.
}
//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::IncValue()
{
	double AvgRadius = this->GetAvgRadius();
	double DiffAngle = this->GetDiffAngle();

	//TODO FOLLOW HERE!! 

	//Modification can be fine or rough, depending on avg radius and diff angle.
	//Think about an algorithm.
}

//----------------------------------------------------------------------------
void vtkOpenVRInteractorStyleSwipeDial::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}


