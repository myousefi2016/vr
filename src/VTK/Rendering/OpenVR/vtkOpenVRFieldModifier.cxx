/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRFieldModifier.cxx

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkOpenVRFieldModifier.h"

#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenVRRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkOpenVROverlay.h"

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
#include "vtkOpenVRInteractorStyleInputData.h"
#include "vtkOpenVRCamera.h"

vtkStandardNewMacro(vtkOpenVRFieldModifier);


//----------------------------------------------------------------------------
vtkOpenVRFieldModifier::vtkOpenVRFieldModifier()
{
	this->SelectedField = vtkField::None;

	// Test (proof of concept):
	this->TestSource = NULL;
	this->TestActor = NULL; 
	this->TestMapper = vtkPolyDataMapper::New();
	this->TestRenderer = NULL;

	CurrentSourceType = vtkSourceType::None;
	this->SetSourceType(vtkSourceType::Sphere);	//Default
	
	if (this->TestMapper && this->TestSource)
	{
		this->TestMapper->SetInputConnection(this->TestSource->GetOutputPort());
	}
}

//----------------------------------------------------------------------------
vtkOpenVRFieldModifier::~vtkOpenVRFieldModifier()
{
	if (this->TestSource)
	{
		this->TestSource->Delete();
		this->TestSource = NULL;
	}
	if (this->TestActor)
	{
		this->TestActor->Delete();
		this->TestActor = NULL;
	}
	if (this->TestMapper)
	{
		this->TestMapper->Delete();
		this->TestMapper = NULL;
	}
	if (this->TestRenderer)
	{
		this->TestRenderer->Delete();
		this->TestRenderer = NULL;
	}
}

//----------------------------------------------------------------------------
void vtkOpenVRFieldModifier::ModifyProperty(vtkObject * obj, vtkField field, char** value)
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

vtkSourceType vtkOpenVRFieldModifier::GetCurrentSourceType()
{
	return this->CurrentSourceType;
}

int vtkOpenVRFieldModifier::GetMaxSourceType()
{
	return int(vtkSourceType::None);
}

void vtkOpenVRFieldModifier::InitTest()
{
	// Create and place in coordinates.
	TestActor = vtkActor::New();
	TestActor->DragableOff();
	TestActor->SetMapper(TestMapper);
	TestActor->GetProperty()->SetAmbient(1.0);
	TestActor->GetProperty()->SetDiffuse(0.0);
}

void vtkOpenVRFieldModifier::ShowTest(vtkOpenVRRenderWindowInteractor *rwi)
{
	vtkOpenVRRenderer *ren = NULL;
	if (rwi)
	{
		int pointer = rwi->GetPointerIndex();
		ren = vtkOpenVRRenderer::SafeDownCast(rwi->FindPokedRenderer(
			rwi->GetEventPositions(pointer)[0], rwi->GetEventPositions(pointer)[1]));
	}
	else return;
	
	// Check if it is already active
	if (!TestActor) this->InitTest();

	// Check if used different renderer to previous visualization
	if (ren != TestRenderer)
	{
		if (TestRenderer != NULL && TestActor)
			TestRenderer->RemoveActor(TestActor);

		if (ren) ren->AddActor(TestActor);
		else vtkWarningMacro(<< "no current renderer on the interactor style.");

		this->TestRenderer = ren;
	}
	
	if (rwi) rwi->Render();
}

void vtkOpenVRFieldModifier::HideTest()
{
	if (TestRenderer != NULL && TestActor)
	{
		TestRenderer->RemoveActor(TestActor);
		this->TestRenderer = NULL;
	}
}

void vtkOpenVRFieldModifier::SetSelectedField(vtkField field)
{
	this->SelectedField = field;
}

vtkField vtkOpenVRFieldModifier::GetSelectedField()
{
	return this->SelectedField;
}

vtkObject * vtkOpenVRFieldModifier::GetfieldOwnerAsObject()
{
	// Specifeis also if the field owner is an algorithm (sources)
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

void vtkOpenVRFieldModifier::IterateSourceType()
{
	//Default behaviour: iterates over all the defined SourceTypes (except 'None').
	vtkSourceType newST = vtkSourceType((int(this->GetCurrentSourceType()) + 1)
																			% this->GetMaxSourceType());
	this->SetSourceType(newST);
}

void vtkOpenVRFieldModifier::SetSourceType(vtkSourceType s)
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
void vtkOpenVRFieldModifier::PrintSelf(ostream& os, vtkIndent indent)
{
	this->Superclass::PrintSelf(os,indent);
}
