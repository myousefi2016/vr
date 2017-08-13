/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRFieldModifier.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRFieldModifier
 * @brief   Used as a generic actors' property changer API. Primarily
 * intended to be used in combination with interactor styles which allow
 * to input data.
 * @see vtkOpenVRInteractorStyleTapDial
*/

#ifndef vtkOpenVRFieldModifier_h
#define vtkOpenVRFieldModifier_h

#include "vtkObject.h"
#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkSetGet.h"	//For export macro

class vtkPolyDataAlgorithm;
class vtkPolyDataMapper;
class vtkActor;
class vtkRenderer;
class vtkOpenVRRenderWindowInteractor;
class vtkSphereSource;
class vtkCylinderSource;
class vtkCubeSource;



/**
 * @enum vtkField
 * @brief Strongly-typed enum class used to reference uniquely all the
 * property fields found in actors. Can be extended with as many fields
 * as wished.
 * 
 * Note that those fields store different data types, so each one of
 * them must be specified the way of modifying them from a text input.
 * 
 * Default version only is intended as a demo, and implements few
 * properties from some sources (sphere, Cylinder, Cube) and actors,
 * props and 3D props.
 * 
 * @see vtkProperty vtkActor vtkProp vtkProp3D
 */
// Field Types
enum class vtkField
{
//vtkProp
	Visibility,
//vtkProp3D
	Scale,
//vtkActor
	Opacity,
//vtkSphereSource
	Radius,
	ThetaResolution,
	PhiResolution,
//vtkCylinderSource
	Height,
	//Radius, already added on Sphere
//vtkCubeSource
	XLength,
	YLength,
	ZLength,
//Default
	None	// 'None' ALWAYS last.
};


// Source Types
enum class vtkSourceType
{
	Sphere,
	Cylinder,
	Cube,
	None	// 'None' ALWAYS last. Used also as Size() property of the enum.
};
/*
// Pipeline Entity
enum class vtkPipelineEntity
{
	Algorithm,
	DataObject,
	None
};
*/

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRFieldModifier : public vtkObject
{
public:
  static vtkOpenVRFieldModifier *New();
  vtkTypeMacro(vtkOpenVRFieldModifier, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

	// A vtkObject is sent. Internally, it must be downcasted to 
	// the most general class which has the field to modify.
	// Double pointer in 'value' is intended to allow passing multiple
	// values (such as x-y-z coords, colour, ...).
  virtual void ModifyProperty(vtkObject *obj, vtkField field, char** value);

	vtkGetMacro(TestSource, vtkPolyDataAlgorithm*);
	vtkGetMacro(TestActor, vtkActor*);
	vtkSourceType GetCurrentSourceType();
	int GetMaxSourceType();
	void SetSourceType(vtkSourceType s);
	void SetSelectedField(vtkField field);
	vtkField GetSelectedField();
	vtkObject* GetfieldOwnerAsObject();

	// Cycles over all the available source types.
	virtual void IterateSourceType();

	// Test (proof of concept):
	virtual void InitTest();
	virtual void ShowTest(vtkOpenVRRenderWindowInteractor *rwi);
	virtual void HideTest();

protected:
  vtkOpenVRFieldModifier();
  ~vtkOpenVRFieldModifier();

	// Test (proof of concept):
	vtkPolyDataAlgorithm *TestSource;
  vtkPolyDataMapper *TestMapper;
  vtkActor *TestActor;
  vtkRenderer *TestRenderer;

	vtkSourceType CurrentSourceType;
	vtkField SelectedField;	//Field to be modified next.

private:
  vtkOpenVRFieldModifier(const vtkOpenVRFieldModifier&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRFieldModifier&) VTK_DELETE_FUNCTION;
};

#endif
