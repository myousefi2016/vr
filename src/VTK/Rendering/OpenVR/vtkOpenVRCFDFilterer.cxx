/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRCFDFilterer.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRCFDFilterer.h"



#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"
#include <valarray>
#include "vtkRenderWindowInteractor3D.h"

#include "vtkRenderer.h"
#include "vtkTextSource.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"

#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRRenderer.h"
#include "vtkInteractorStyle3D.h"
#include "vtkOpenVRInteractorStyleInputData.h"
#include "vtkOpenVRCamera.h"

#include "vtkOpenFOAMReader.h"
#include "vtkMultiBlockDataSetAlgorithm.h"
#include "vtkDataSetMapper.h"
#include "vtkShrinkPolyData.h"


vtkStandardNewMacro(vtkOpenVRCFDFilterer);

void vtkOpenVRCFDFilterer::Shrink(double value)
{


}

//----------------------------------------------------------------------------
vtkOpenVRCFDFilterer::vtkOpenVRCFDFilterer()
{
	this->CFDReader = vtkOpenFOAMReader::New();
	this->CFDSource = vtkMultiBlockDataSetAlgorithm::New();
//	this->CFDShrink = vtkShrinkPolyData::New();
	this->CFDMapper = vtkDataSetMapper::New();
	this->CFDActor = vtkActor::New();
	this->CFDRenderer = NULL;

	//Create pipeline manually: Source -> Shrink -> Mapper -> Actor
	this->CFDReader->CanReadFile("C:\\Users\\vr\\Desktop\\Antonis Data\\CYLINDER\\cyl-incomp-DES-M1-span30-550K-100s\\foam.foam");
	this->CFDReader->SetFileName("C:\\Users\\vr\\Desktop\\Antonis Data\\CYLINDER\\cyl-incomp-DES-M1-span30-550K-100s\\foam.foam");
	this->CFDReader->Update();
	this->CFDSource->SetInputConnection(this->CFDReader->GetOutputPort());
//	this->CFDShrink->SetInputConnection(this->CFDSource->GetOutputPort());
//	this->CFDMapper->SetInputConnection(this->CFDShrink->GetOutputPort());
	this->CFDMapper->SetInputConnection(this->CFDSource->GetOutputPort());
	this->CFDActor->SetMapper(this->CFDMapper);

	//alt 2:
	/*this->CFDReader->CanReadFile("C:\\Users\\vr\\Desktop\\Antonis Data\\CYLINDER\\cyl-incomp-DES-M1-span30-550K-100s\\foam.foam");
	this->CFDReader->SetFileName("C:\\Users\\vr\\Desktop\\Antonis Data\\CYLINDER\\cyl-incomp-DES-M1-span30-550K-100s\\foam.foam");
	this->CFDReader->Update();
	this->CFDMapper->SetInputConnection(this->CFDReader->GetOutputPort());
	this->CFDActor->SetMapper(this->CFDMapper);*/
}

//----------------------------------------------------------------------------
vtkOpenVRCFDFilterer::~vtkOpenVRCFDFilterer()
{
	if (this->CFDReader) this->CFDReader->Delete();
	if (this->CFDSource) this->CFDSource->Delete();
//	if (this->CFDShrink) this->CFDShrink->Delete();
	if (this->CFDMapper) this->CFDMapper->Delete();
	if (this->CFDActor) this->CFDActor->Delete();
}


//----------------------------------------------------------------------------
void vtkOpenVRCFDFilterer::Attach(vtkOpenVRRenderWindowInteractor *rwi)
{
	//Current renderer
	vtkOpenVRRenderer *ren = NULL;
	if (rwi)
	{
		int pointer = rwi->GetPointerIndex();
		//This will return the current renderer:
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0],
																																 rwi->GetEventPositions(pointer)[1]));
	}

	//check if it is already active
	/*if (!this->CFDActor)
	{
		this->Init();
	}*/

	//check if used different renderer to previous visualization
	if (ren != this->CFDRenderer)
	{
		if (this->CFDRenderer != NULL && this->CFDActor)
		{
			this->CFDRenderer->RemoveActor(this->CFDActor);
		}
		if (ren != 0)
		{
			ren->AddActor(this->CFDActor);
		}
		else
		{
			vtkWarningMacro(<< "no current renderer on the interactor style.");
		}
		this->CFDRenderer = ren;
	}

	//this->Move(rwi);
}

void vtkOpenVRCFDFilterer::InitCFD()
{
}

void vtkOpenVRCFDFilterer::ShowCFD(vtkOpenVRRenderWindowInteractor * rwi)
{
	//Current renderer
	vtkOpenVRRenderer *ren = NULL;
	vtkInteractorStyle3D *ist = NULL;
	vtkOpenVRCamera *cam = NULL;
	int pointer;
	if (rwi)
	{
		int pointer = rwi->GetPointerIndex();		//pointer = rwi->GetPointerIndexLastTouchpad();
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(rwi->GetEventPositions(pointer)[0],
																																 rwi->GetEventPositions(pointer)[1]));
		ist = vtkOpenVRInteractorStyleInputData::SafeDownCast(rwi->GetInteractorStyle());
		cam = vtkOpenVRCamera::SafeDownCast(ren->GetActiveCamera());
	}
	else return;

	//check if it is already active
	if (!CFDActor)
	{
		this->InitCFD();
	}

	//check if used different renderer to previous visualization
	if (ren != CFDRenderer)
	{
		if (CFDRenderer != NULL && CFDActor)
		{
			CFDRenderer->RemoveActor(CFDActor);
		}
		if (ren)
		{
			ren->AddActor(CFDActor);
		}
		else
		{
			vtkWarningMacro(<< "no current renderer on the interactor style.");
		}
		this->CFDRenderer = ren;
	}


	if (rwi)
	{
		rwi->Render();
	}
}









/*
//----------------------------------------------------------------------------
void vtkOpenVRPropertyModifier::ModifyProperty(vtkObject * obj, vtkField field, char* value)
{	//Add new parameter: vtkObjectType (which is a new enum class).
	//This will remove problems on downcasting:
	//instead of vtkSphereSource, we can select vtkAlgorithm or vtkPolyDataAlgorithm
	//¿?To do so, create a method, selectDownCast(...) ¿?
	//BRIGHT IDEA: Use an "union" to store all the different types as pointers!!!
//	vtkProp *downProp;
	vtkActor *downActor;
	vtkSphereSource *downSphere;
	vtkProp3D *downProp3D;

	switch(field)
	{
	case vtkField::Visibility:
		downSphere = vtkSphereSource::SafeDownCast(obj);
		if (downSphere != NULL)
		{
			vtkStdString str = vtkVariant(value).ToString();
			if (str.compare("true"))
			{
				downSphere->LatLongTessellationOn();
			}
			else if (str.compare("false"))
			{
				downSphere->LatLongTessellationOff();
			}
		}
		break;
	case vtkField::Opacity:
		downActor = vtkActor::SafeDownCast(obj);
		if (downActor != NULL)
		{
			downActor->GetProperty()->SetOpacity(vtkVariant(value).ToDouble());
		}
		break;
	case vtkField::Scale:
		downProp3D = vtkProp3D::SafeDownCast(obj);
		if(downProp3D != NULL)
		{
			downProp3D->SetScale(vtkVariant(value).ToDouble());
		}
		break;
	case vtkField::Radius:
		downSphere = vtkSphereSource::SafeDownCast(obj);
		if (downSphere != NULL)
		{
			downSphere->SetRadius(vtkVariant(value).ToDouble());
		}
		break;
	// Add cases as desired. Remenber to add the vtkProp in the enum class!
	default:
		vtkErrorMacro(<< "vtkField not recognized.");
	}
}
*/


//----------------------------------------------------------------------------
void vtkOpenVRCFDFilterer::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
	
/*
//----------------------------------------------------------------------------
void vtkInteractorStyle::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);

	os << indent << "Auto Adjust Camera Clipping Range "
		<< (this->AutoAdjustCameraClippingRange ? "On\n" : "Off\n");

	os << indent << "Pick Color: (" << this->PickColor[0] << ", "
		<< this->PickColor[1] << ", "
		<< this->PickColor[2] << ")\n";

	os << indent << "CurrentRenderer: " << this->CurrentRenderer << "\n";
	if (this->PickedRenderer)
	{
		os << indent << "Picked Renderer: " << this->PickedRenderer << "\n";
	}
	else
	{
		os << indent << "Picked Renderer: (none)\n";
	}
	if (this->CurrentProp)
	{
		os << indent << "Current Prop: " << this->CurrentProp << "\n";
	}
	else
	{
		os << indent << "Current Actor: (none)\n";
	}

	os << indent << "Interactor: " << this->Interactor << "\n";
	os << indent << "Prop Picked: " <<
		(this->PropPicked ? "Yes\n" : "No\n");

	os << indent << "State: " << this->State << endl;
	os << indent << "UseTimers: " << this->UseTimers << endl;
	os << indent << "HandleObservers: " << this->HandleObservers << endl;
	os << indent << "MouseWheelMotionFactor: " << this->MouseWheelMotionFactor << endl;

	os << indent << "Timer Duration: " << this->TimerDuration << endl;

	os << indent << "TDxStyle: ";
	if (this->TDxStyle == 0)
	{
		os << "(none)" << endl;
	}
	else
	{
		this->TDxStyle->PrintSelf(os, indent.GetNextIndent());
	}
}



//----------------------------------------------------------------------------
void vtkRenderWindowInteractor::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os, indent);

	os << indent << "InteractorStyle:    " << this->InteractorStyle << "\n";
	os << indent << "RenderWindow:    " << this->RenderWindow << "\n";
	if (this->Picker)
	{
		os << indent << "Picker: " << this->Picker << "\n";
	}
	else
	{
		os << indent << "Picker: (none)\n";
	}
	if (this->ObserverMediator)
	{
		os << indent << "Observer Mediator: " << this->ObserverMediator << "\n";
	}
	else
	{
		os << indent << "Observer Mediator: (none)\n";
	}
	os << indent << "LightFollowCamera: " << (this->LightFollowCamera ? "On\n" : "Off\n");
	os << indent << "DesiredUpdateRate: " << this->DesiredUpdateRate << "\n";
	os << indent << "StillUpdateRate: " << this->StillUpdateRate << "\n";
	os << indent << "Initialized: " << this->Initialized << "\n";
	os << indent << "Enabled: " << this->Enabled << "\n";
	os << indent << "EnableRender: " << this->EnableRender << "\n";
	os << indent << "EventPosition: " << "( " << this->EventPosition[0] <<
		", " << this->EventPosition[1] << " )\n";
	os << indent << "LastEventPosition: " << "( " << this->LastEventPosition[0]
		<< ", " << this->LastEventPosition[1] << " )\n";
	os << indent << "EventSize: " << "( " << this->EventSize[0] <<
		", " << this->EventSize[1] << " )\n";
	os << indent << "Viewport Size: " << "( " << this->Size[0] <<
		", " << this->Size[1] << " )\n";
	os << indent << "Number of Fly Frames: " << this->NumberOfFlyFrames << "\n";
	os << indent << "Dolly: " << this->Dolly << "\n";
	os << indent << "ControlKey: " << this->ControlKey << "\n";
	os << indent << "AltKey: " << this->AltKey << "\n";
	os << indent << "ShiftKey: " << this->ShiftKey << "\n";
	os << indent << "KeyCode: " << this->KeyCode << "\n";
	os << indent << "KeySym: " << (this->KeySym ? this->KeySym : "(null)")
		<< "\n";
	os << indent << "RepeatCount: " << this->RepeatCount << "\n";
	os << indent << "Timer Duration: " << this->TimerDuration << "\n";
	os << indent << "TimerEventId: " << this->TimerEventId << "\n";
	os << indent << "TimerEventType: " << this->TimerEventType << "\n";
	os << indent << "TimerEventDuration: " << this->TimerEventDuration << "\n";
	os << indent << "TimerEventPlatformId: " << this->TimerEventPlatformId << "\n";
	os << indent << "UseTDx: " << this->UseTDx << endl;
	os << indent << "Recognize Gestures: " << this->RecognizeGestures << endl;
}
*/