/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRCFDFilterer.h

Copyright (c) Ventura Romero Mendo
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenVRCFDFilterer
 * @brief   Intended to be a starting point class for future MsC projects.
 * It shows an idea (just suggestion, may be better solutions) of how can 
 * be structured the code and how can be filters applied to CFD data.
 * The idea consists on loading the data from the source code (not ParaView's
 * GUI) using the OpenFoam reader, and then storing the filters applied to 
 * the initial data.
*/

#ifndef vtkOpenVRCFDFilterer_h
#define vtkOpenVRCFDFilterer_h

#include "vtkObject.h"
#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkSetGet.h"	//For export macro

/*
class vtkObject;
class vtkSphereSource;	//For dummy test
class vtkPolyDataMapper;
class vtkActor;
class vtkRenderer;
class vtkOpenVRRenderWindowInteractor;
*/
class vtkOpenFOAMReader;
class vtkMultiBlockDataSetAlgorithm;
class vtkShrinkPolyData;
class vtkDataSetMapper;
class vtkActor;
class vtkRenderer;
class vtkOpenVRRenderWindowInteractor;

class  VTKRENDERINGOPENVR_EXPORT vtkOpenVRCFDFilterer : public vtkObject
{
public:
  static vtkOpenVRCFDFilterer *New();
  vtkTypeMacro(vtkOpenVRCFDFilterer, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

	/*
	// A vtkObject is sent. internally, it must be downcasted to 
	// the most general class which has the field to modify
  virtual void ModifyProperty(vtkObject *obj, vtkField field, char* value);

  vtkGetMacro(TestSource, vtkSphereSource*);
	*/

//	virtual void Init();
	virtual void Attach(vtkOpenVRRenderWindowInteractor *rwi);
//	virtual void Move(vtkOpenVRRenderWindowInteractor *rwi);
//	virtual void Detach();

	virtual void InitCFD();
	virtual void ShowCFD(vtkOpenVRRenderWindowInteractor *rwi);
//	virtual void HideCFD();

	virtual void Shrink(double value);

protected:
	vtkOpenVRCFDFilterer();
  ~vtkOpenVRCFDFilterer();


	vtkOpenFOAMReader *CFDReader;
	vtkMultiBlockDataSetAlgorithm *CFDSource;
//	vtkShrinkPolyData *CFDShrink;
	vtkDataSetMapper *CFDMapper;
	vtkActor *CFDActor;
	vtkRenderer *CFDRenderer;

private:
	vtkOpenVRCFDFilterer(const vtkOpenVRCFDFilterer&) VTK_DELETE_FUNCTION;  // Not implemented.
  void operator=(const vtkOpenVRCFDFilterer&) VTK_DELETE_FUNCTION;  // Not implemented.
};

#endif
