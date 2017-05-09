set(vtkFiltersParallelMPI_HEADERS_LOADED 1)
set(vtkFiltersParallelMPI_HEADERS "vtkDistributedDataFilter;vtkPExtractGrid;vtkPExtractRectilinearGrid;vtkPExtractVOI;vtkStructuredImplicitConnectivity")

foreach(header ${vtkFiltersParallelMPI_HEADERS})
  set(vtkFiltersParallelMPI_HEADER_${header}_EXISTS 1)
endforeach()




