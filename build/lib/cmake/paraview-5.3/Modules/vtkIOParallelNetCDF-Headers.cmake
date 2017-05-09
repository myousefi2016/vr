set(vtkIOParallelNetCDF_HEADERS_LOADED 1)
set(vtkIOParallelNetCDF_HEADERS "vtkPNetCDFPOPReader")

foreach(header ${vtkIOParallelNetCDF_HEADERS})
  set(vtkIOParallelNetCDF_HEADER_${header}_EXISTS 1)
endforeach()




