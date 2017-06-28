/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRPropertyModifier.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRPropertyModifier.h"

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

vtkStandardNewMacro(vtkOpenVRPropertyModifier);

//----------------------------------------------------------------------------
vtkOpenVRPropertyModifier::vtkOpenVRPropertyModifier()
{
	//Dummy test
	this->TestSource = vtkSphereSource::New();
	this->TestActor = NULL;
	this->TestMapper = vtkPolyDataMapper::New();
	this->TestRenderer = NULL;
	this->TestOn = false;

	if (this->TestMapper && this->TestSource)
	{
		this->TestMapper->SetInputConnection(this->TestSource->GetOutputPort());
	}
}

//----------------------------------------------------------------------------
vtkOpenVRPropertyModifier::~vtkOpenVRPropertyModifier()
{
	if (this->TestActor)
	{
		this->TestActor->Delete();
	}

	if (this->TestMapper)
	{
		this->TestMapper->Delete();
	}

	this->TestSource->Delete();
	this->TestSource = NULL;
}

//----------------------------------------------------------------------------
void vtkOpenVRPropertyModifier::ModifyProperty(vtkObject * obj, vtkField field, char* value)
{
	switch(field)
	{
	case vtkField::Visibility:
		vtkProp *downVisibility = vtkProp::SafeDownCast(obj);
		if (downVisibility != NULL)
		{
			downVisibility->SetVisibility(vtkVariant(value).ToInt());
		}
	case vtkField::Opacity:
		vtkActor *downOpacity = vtkActor::SafeDownCast(obj);
		if (downOpacity != NULL)
		{
			downOpacity->GetProperty()->SetOpacity(vtkVariant(value).ToDouble());
		}
		break;
	case vtkField::Scale:
		vtkProp3D *downScale = vtkProp3D::SafeDownCast(obj);
		if(downScale != NULL)
		{
			downScale->SetScale(vtkVariant(value).ToDouble());
		}
		break;
	case vtkField::Radius:
		vtkSphereSource *downRadius = vtkSphereSource::SafeDownCast(obj);
		if (downRadius != NULL)
		{
			downRadius->SetRadius(vtkVariant(value).ToDouble());
		}
		break;
	// Add cases as desired. Remenber to add the vtkProp in the enum class!
	default:
		vtkErrorMacro(<< "vtkField not recognized.");
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRPropertyModifier::PrintSelf(ostream& os, vtkIndent indent)
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