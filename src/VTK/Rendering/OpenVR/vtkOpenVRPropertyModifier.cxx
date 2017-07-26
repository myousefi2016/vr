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
#include "vtkCylinderSource.h"
#include "vtkCubeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolyDataAlgorithm.h"

#include "vtkOpenVRRenderWindowInteractor.h"
#include "vtkOpenVRRenderer.h"
#include "vtkInteractorStyle3D.h"
#include "vtkOpenVRInteractorStyleInputData.h"
#include "vtkOpenVRCamera.h"

vtkStandardNewMacro(vtkOpenVRPropertyModifier);


//----------------------------------------------------------------------------
vtkOpenVRPropertyModifier::vtkOpenVRPropertyModifier()
{
	this->SelectedField = vtkField::None;

	//Dummy test
	this->TestSource = NULL;		// vtkPolyDataAlgorithm::New();		//this->TestSource = vtkSphereSource::New();
	this->TestActor = NULL; 
	this->TestMapper = vtkPolyDataMapper::New();
	this->TestRenderer = NULL;
	CurrentSourceType = vtkSourceType::None;

	this->SelectSourceType(vtkSourceType::Sphere);	//Default
	
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
void vtkOpenVRPropertyModifier::ModifyProperty(vtkObject * obj, vtkField field, char** value)
{
	vtkProp *downProp;
	vtkProp3D *downProp3D;
	vtkActor *downActor;
	vtkSphereSource *downSphere;
	vtkCylinderSource *downCylinder;
	vtkCubeSource *downCube;

	switch(field)
	{
	//vtkProp cases
	case vtkField::Visibility:
		if(obj->IsA("vtkProp"))
		{
			downProp = vtkProp::SafeDownCast(obj);

			vtkStdString str = vtkVariant(*value).ToString();
			if (str.compare("true") == 0)
			{
				downProp->SetVisibility(true);
			}
			else if (str.compare("false") == 0)
			{
				downProp->SetVisibility(false);
			}
		}
		break;
	//vtkProp3D cases
	case vtkField::Scale:
		if (obj->IsA("vtkProp3D"))
		{
			downProp3D = vtkProp3D::SafeDownCast(obj);
			downProp3D->SetScale(vtkVariant(*value).ToDouble());
		}
		break;
	//vtkActor cases
	case vtkField::Opacity:
		if (obj->IsA("vtkActor"))
		{
			downActor = vtkActor::SafeDownCast(obj);
			downActor->GetProperty()->SetOpacity(vtkVariant(*value).ToDouble());
		}
		break;
	//vtkSphereSource cases
	case vtkField::Radius:
		if (obj->IsA("vtkSphereSource"))
		{
			downSphere = vtkSphereSource::SafeDownCast(obj);
			downSphere->SetRadius(vtkVariant(*value).ToDouble());
		}
		else if (obj->IsA("vtkCylinderSource"))
		{
			downCylinder = vtkCylinderSource::SafeDownCast(obj);
			downCylinder->SetRadius(vtkVariant(*value).ToDouble());
		}
		break;
	case vtkField::ThetaResolution:
		if (obj->IsA("vtkSphereSource"))
		{
			downSphere = vtkSphereSource::SafeDownCast(obj);
			downSphere->SetThetaResolution(vtkVariant(*value).ToInt());
		}
		break;
	case vtkField::PhiResolution:
		if (obj->IsA("vtkSphereSource"))
		{
			downSphere = vtkSphereSource::SafeDownCast(obj);
			downSphere->SetPhiResolution(vtkVariant(*value).ToInt());
		}
		break;
	//vtkCylinderSource cases
	case vtkField::Height:
		if (obj->IsA("vtkCylinderSource"))
		{
			downCylinder = vtkCylinderSource::SafeDownCast(obj);
			downCylinder->SetHeight(vtkVariant(*value).ToDouble());
		}
		break;
	//vtkCubeSource cases
	case vtkField::XLength:
		if (obj->IsA("vtkCubeSource"))
		{
			downCube = vtkCubeSource::SafeDownCast(obj);
			downCube->SetXLength(vtkVariant(*value).ToDouble());
		}
		break;
	case vtkField::YLength:
		if (obj->IsA("vtkCubeSource"))
		{
			downCube = vtkCubeSource::SafeDownCast(obj);
			downCube->SetYLength(vtkVariant(*value).ToDouble());
		}
		break;
	case vtkField::ZLength:
		if (obj->IsA("vtkCubeSource"))
		{
			downCube = vtkCubeSource::SafeDownCast(obj);
			downCube->SetZLength(vtkVariant(*value).ToDouble());
		}
		break;
	// Add cases as desired. Remember to add the vtkProp in the enum class!
	default:
		vtkErrorMacro(<< "vtkField not recognized.");
	}
}

vtkSourceType vtkOpenVRPropertyModifier::GetCurrentSourceType()
{
	return this->CurrentSourceType;
}

int vtkOpenVRPropertyModifier::GetMaxSourceType()
{
	return int(vtkSourceType::None);
}

void vtkOpenVRPropertyModifier::InitTest()
{
	//create and place in coordinates.
	TestActor = vtkActor::New();
	TestActor->DragableOff();
	TestActor->SetMapper(TestMapper);
	TestActor->GetProperty()->SetAmbient(1.0);
	TestActor->GetProperty()->SetDiffuse(0.0);
}

void vtkOpenVRPropertyModifier::ShowTest(vtkOpenVRRenderWindowInteractor *rwi)
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
	if (!TestActor)
	{
		this->InitTest();
	}

	//check if used different renderer to previous visualization
	if (ren != TestRenderer)
	{
		if (TestRenderer != NULL && TestActor)
		{
			TestRenderer->RemoveActor(TestActor);
		}
		if (ren)
		{
			ren->AddActor(TestActor);
		}
		else
		{
			vtkWarningMacro(<< "no current renderer on the interactor style.");
		}
		this->TestRenderer = ren;
	}
	
	if (rwi)
	{
		rwi->Render();
	}
}

void vtkOpenVRPropertyModifier::HideTest()
{
	if (TestRenderer != NULL && TestActor)
	{
		TestRenderer->RemoveActor(TestActor);
		this->TestRenderer = NULL;
	}
}

void vtkOpenVRPropertyModifier::SetSelectedField(vtkField field)
{
	this->SelectedField = field;
}

vtkField vtkOpenVRPropertyModifier::GetSelectedField()
{
	return this->SelectedField;
}

vtkObject * vtkOpenVRPropertyModifier::GetfieldOwnerAsObject()
{
	// Specify also if the field owner is an algorithm (sources)
	// or a data object (props / actors)
	switch (this->SelectedField)
	{
		//Algorithms (sources):
	case vtkField::Radius:
	case vtkField::ThetaResolution:
	case vtkField::PhiResolution:
	case vtkField::Height:
	case vtkField::XLength:
	case vtkField::YLength:
	case vtkField::ZLength:
		return this->TestSource;
		//Data Objects (props / actors):
	case vtkField::Visibility:
	case vtkField::Scale:
	case vtkField::Opacity:
		return this->TestActor;
	case vtkField::None:
	default:
		vtkErrorMacro(<< "Unrecognised vtkField. No Pipeline entity can be inferred as owner.");
		return nullptr;
	}
}

void vtkOpenVRPropertyModifier::IterateSourceType()
{
	//Default behaviour: iterates over all the defined SourceTypes (except 'None').
	vtkSourceType newST = vtkSourceType((int(this->GetCurrentSourceType()) + 1) % this->GetMaxSourceType());
	this->SelectSourceType(newST);
}

void vtkOpenVRPropertyModifier::SelectSourceType(vtkSourceType s)
{
	if (this->CurrentSourceType != s)
	{

		if (this->TestSource) this->TestSource->Delete();

		this->CurrentSourceType = s;
		switch (s)
		{
		case vtkSourceType::Sphere: this->TestSource = vtkSphereSource::New(); break;
		case vtkSourceType::Cylinder: this->TestSource = vtkCylinderSource::New(); break;
		case vtkSourceType::Cube: this->TestSource = vtkCubeSource::New(); break;
		default:
			vtkErrorMacro("Unrecognised SourceType");
			this->CurrentSourceType = vtkSourceType::None;
			break;
		}
		if (this->TestMapper && this->TestSource) this->TestMapper->SetInputConnection(this->TestSource->GetOutputPort());
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