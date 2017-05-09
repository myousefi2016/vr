set(vtkIOMPIParallel_HEADERS_LOADED 1)
set(vtkIOMPIParallel_HEADERS "vtkIOMPIParallelObjectFactory")

foreach(header ${vtkIOMPIParallel_HEADERS})
  set(vtkIOMPIParallel_HEADER_${header}_EXISTS 1)
endforeach()


set(vtkIOMPIParallel_HEADER_vtkIOMPIParallelObjectFactory_WRAP_EXCLUDE 1)

set(vtkIOMPIParallel_HEADER_vtkIOMPIParallelObjectFactory_WRAP_EXCLUDE_PYTHON 1)

