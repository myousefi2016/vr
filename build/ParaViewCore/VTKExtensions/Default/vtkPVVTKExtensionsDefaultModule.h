
#ifndef VTKPVVTKEXTENSIONSDEFAULT_EXPORT_H
#define VTKPVVTKEXTENSIONSDEFAULT_EXPORT_H

#ifdef VTKPVVTKEXTENSIONSDEFAULT_STATIC_DEFINE
#  define VTKPVVTKEXTENSIONSDEFAULT_EXPORT
#  define VTKPVVTKEXTENSIONSDEFAULT_NO_EXPORT
#else
#  ifndef VTKPVVTKEXTENSIONSDEFAULT_EXPORT
#    ifdef vtkPVVTKExtensionsDefault_EXPORTS
        /* We are building this library */
#      define VTKPVVTKEXTENSIONSDEFAULT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPVVTKEXTENSIONSDEFAULT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPVVTKEXTENSIONSDEFAULT_NO_EXPORT
#    define VTKPVVTKEXTENSIONSDEFAULT_NO_EXPORT 
#  endif
#endif

#ifndef VTKPVVTKEXTENSIONSDEFAULT_DEPRECATED
#  define VTKPVVTKEXTENSIONSDEFAULT_DEPRECATED __declspec(deprecated)
#  define VTKPVVTKEXTENSIONSDEFAULT_DEPRECATED_EXPORT VTKPVVTKEXTENSIONSDEFAULT_EXPORT __declspec(deprecated)
#  define VTKPVVTKEXTENSIONSDEFAULT_DEPRECATED_NO_EXPORT VTKPVVTKEXTENSIONSDEFAULT_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPVVTKEXTENSIONSDEFAULT_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkFiltersParallelFlowPathsModule.h"
#include "vtkFiltersParallelStatisticsModule.h"
#include "vtkIOImportModule.h"
#include "vtkIOMPIImageModule.h"
#include "vtkIOParallelModule.h"
#include "vtkIOParallelExodusModule.h"
#include "vtkInteractionWidgetsModule.h"
#include "vtkPVVTKExtensionsCoreModule.h"
#include "vtkPVVTKExtensionsRenderingModule.h"

#endif
