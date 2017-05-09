set(vtkParallelMPI_HEADERS_LOADED 1)
set(vtkParallelMPI_HEADERS "vtkMPICommunicator;vtkMPIController;vtkMPIUtilities;vtkMPI")

foreach(header ${vtkParallelMPI_HEADERS})
  set(vtkParallelMPI_HEADER_${header}_EXISTS 1)
endforeach()


set(vtkParallelMPI_HEADER_vtkMPIUtilities_WRAP_EXCLUDE 1)
set(vtkParallelMPI_HEADER_vtkMPI_WRAP_EXCLUDE 1)

set(vtkParallelMPI_HEADER_vtkMPIUtilities_WRAP_EXCLUDE_PYTHON 1)
set(vtkParallelMPI_HEADER_vtkMPI_WRAP_EXCLUDE_PYTHON 1)

