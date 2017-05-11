/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkMyElevationFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkMyElevationFilter - generate scalars along a specified direction
// .SECTION Description
// vtkMyElevationFilter is a filter to generate scalar values from a
// dataset.  The scalar values lie within a user specified range, and
// are generated by computing a projection of each dataset point onto
// a line. The line can be oriented arbitrarily. A typical example is
// to generate scalars based on elevation or height above a plane.

#ifndef vtkMyElevationFilter_h
#define vtkMyElevationFilter_h

#include "vtkElevationFilter.h"

class VTK_EXPORT vtkMyElevationFilter : public vtkElevationFilter
{
public:
  static vtkMyElevationFilter* New();
  vtkTypeMacro(vtkMyElevationFilter, vtkElevationFilter);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

protected:
  vtkMyElevationFilter();
  ~vtkMyElevationFilter();

private:
  vtkMyElevationFilter(const vtkMyElevationFilter&) VTK_DELETE_FUNCTION;
  void operator=(const vtkMyElevationFilter&) VTK_DELETE_FUNCTION;
};

#endif
