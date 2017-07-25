/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRPropertyModifier.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRPropertyModifier
 * @brief   Used as a generic actors' property changer API. Primarily
 * intended to be used in combination with interactor styles which allow
 * to input data.
 * @see vtkOpenVRInteractorStyleTapDial
*/

#ifndef vtkOpenVRPropertyModifier_h
#define vtkOpenVRPropertyModifier_h

#include "vtkObject.h"
#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkSetGet.h"	//For export macro

class vtkObject;
class vtkPolyDataMapper;
class vtkActor;
class vtkRenderer;
class vtkOpenVRRenderWindowInteractor;

class vtkPolyDataAlgorithm;
class vtkSphereSource;	//For dummy test
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
 * properties from a Sphere.
 * 
 * Currently only valid to set monovalue properties (i.e. not color)
 * 
 * @see vtkProperty vtkActor
 */
enum class vtkField
{
	Scale,
	Opacity,
	Visibility,
	Radius
};



enum class vtkSource
{
	Sphere,
	Cylinder,
	Cube
};


/*
//union GenericSource;
union GenericSource {
	vtkSphereSource *Sphere;
	vtkCylinderSource *Cylinder;
	vtkCubeSource *Cube;
	//vtkPolyDataAlgorithm *Def;
	//GenericSource() {};
};
*/




class VTKRENDERINGOPENVR_EXPORT vtkOpenVRPropertyModifier : public vtkObject
{
public:
  static vtkOpenVRPropertyModifier *New();
  vtkTypeMacro(vtkOpenVRPropertyModifier, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

	// A vtkObject is sent. internally, it must be downcasted to 
	// the most general class which has the field to modify
  virtual void ModifyProperty(vtkObject *obj, vtkField field, char* value);

	vtkGetMacro(TestSource, vtkPolyDataAlgorithm*);		//vtkGetMacro(TestSource, vtkSphereSource*);
	vtkGetMacro(TestActor, vtkActor*);

	//test:
	virtual void InitTest();
	virtual void ShowTest(vtkOpenVRRenderWindowInteractor *rwi);
	virtual void HideTest();

	//Union try
	void SetGenericSource(vtkSource s);
	void SelectSourceDownCast(vtkSource s);


protected:
  vtkOpenVRPropertyModifier();
  ~vtkOpenVRPropertyModifier();

  //Dummy test Actor/Source
	vtkPolyDataAlgorithm *TestSource;		//vtkSphereSource *TestSource;

  vtkPolyDataMapper *TestMapper;
  vtkActor *TestActor;
  vtkRenderer *TestRenderer;


	//vtkSource currentTest

	//Union try
	//Tries to substitute TestSource.
	//GenericSource gs;



private:
  vtkOpenVRPropertyModifier(const vtkOpenVRPropertyModifier&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRPropertyModifier&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
