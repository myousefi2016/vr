set(vtkPVCatalyst_HEADERS_LOADED 1)
set(vtkPVCatalyst_HEADERS "CAdaptorAPI;vtkCPAdaptorAPI;vtkCPCxxHelper;vtkCPDataDescription;vtkCPInputDataDescription;vtkCPPipeline;vtkCPProcessor")

foreach(header ${vtkPVCatalyst_HEADERS})
  set(vtkPVCatalyst_HEADER_${header}_EXISTS 1)
endforeach()

set(vtkPVCatalyst_HEADER_vtkCPAdaptorAPI_ABSTRACT 1)
set(vtkPVCatalyst_HEADER_vtkCPPipeline_ABSTRACT 1)

set(vtkPVCatalyst_HEADER_CAdaptorAPI_WRAP_EXCLUDE 1)
set(vtkPVCatalyst_HEADER_vtkCPCxxHelper_WRAP_EXCLUDE 1)


