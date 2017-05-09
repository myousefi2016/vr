
#ifndef VTKPVCLIENTSERVERCORERENDERING_EXPORT_H
#define VTKPVCLIENTSERVERCORERENDERING_EXPORT_H

#ifdef VTKPVCLIENTSERVERCORERENDERING_STATIC_DEFINE
#  define VTKPVCLIENTSERVERCORERENDERING_EXPORT
#  define VTKPVCLIENTSERVERCORERENDERING_NO_EXPORT
#else
#  ifndef VTKPVCLIENTSERVERCORERENDERING_EXPORT
#    ifdef vtkPVClientServerCoreRendering_EXPORTS
        /* We are building this library */
#      define VTKPVCLIENTSERVERCORERENDERING_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPVCLIENTSERVERCORERENDERING_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPVCLIENTSERVERCORERENDERING_NO_EXPORT
#    define VTKPVCLIENTSERVERCORERENDERING_NO_EXPORT 
#  endif
#endif

#ifndef VTKPVCLIENTSERVERCORERENDERING_DEPRECATED
#  define VTKPVCLIENTSERVERCORERENDERING_DEPRECATED __declspec(deprecated)
#  define VTKPVCLIENTSERVERCORERENDERING_DEPRECATED_EXPORT VTKPVCLIENTSERVERCORERENDERING_EXPORT __declspec(deprecated)
#  define VTKPVCLIENTSERVERCORERENDERING_DEPRECATED_NO_EXPORT VTKPVCLIENTSERVERCORERENDERING_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPVCLIENTSERVERCORERENDERING_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkDomainsChemistryModule.h"
#include "vtkPVClientServerCoreCoreModule.h"
#include "vtkPVVTKExtensionsDefaultModule.h"
#include "vtkPVVTKExtensionsRenderingModule.h"
#include "vtkRenderingLabelModule.h"
#include "vtkRenderingVolumeOpenGL2Module.h"
#include "vtkViewsContext2DModule.h"
#include "vtkViewsCoreModule.h"

#endif
