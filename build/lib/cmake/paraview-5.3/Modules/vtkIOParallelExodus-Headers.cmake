set(vtkIOParallelExodus_HEADERS_LOADED 1)
set(vtkIOParallelExodus_HEADERS "vtkPExodusIIReader;vtkPExodusIIWriter;vtkIOParallelExodusObjectFactory")

foreach(header ${vtkIOParallelExodus_HEADERS})
  set(vtkIOParallelExodus_HEADER_${header}_EXISTS 1)
endforeach()


set(vtkIOParallelExodus_HEADER_vtkIOParallelExodusObjectFactory_WRAP_EXCLUDE 1)

set(vtkIOParallelExodus_HEADER_vtkIOParallelExodusObjectFactory_WRAP_EXCLUDE_PYTHON 1)

