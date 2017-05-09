set(vtkTestingRendering_HEADERS_LOADED 1)
set(vtkTestingRendering_HEADERS "vtkRegressionTestImage;vtkTesting;vtkTestingInteractor;vtkTestingObjectFactory")

foreach(header ${vtkTestingRendering_HEADERS})
  set(vtkTestingRendering_HEADER_${header}_EXISTS 1)
endforeach()


set(vtkTestingRendering_HEADER_vtkRegressionTestImage_WRAP_EXCLUDE 1)


