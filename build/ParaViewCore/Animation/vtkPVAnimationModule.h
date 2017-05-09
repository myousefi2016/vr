
#ifndef VTKPVANIMATION_EXPORT_H
#define VTKPVANIMATION_EXPORT_H

#ifdef VTKPVANIMATION_STATIC_DEFINE
#  define VTKPVANIMATION_EXPORT
#  define VTKPVANIMATION_NO_EXPORT
#else
#  ifndef VTKPVANIMATION_EXPORT
#    ifdef vtkPVAnimation_EXPORTS
        /* We are building this library */
#      define VTKPVANIMATION_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPVANIMATION_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPVANIMATION_NO_EXPORT
#    define VTKPVANIMATION_NO_EXPORT 
#  endif
#endif

#ifndef VTKPVANIMATION_DEPRECATED
#  define VTKPVANIMATION_DEPRECATED __declspec(deprecated)
#  define VTKPVANIMATION_DEPRECATED_EXPORT VTKPVANIMATION_EXPORT __declspec(deprecated)
#  define VTKPVANIMATION_DEPRECATED_NO_EXPORT VTKPVANIMATION_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPVANIMATION_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkPVServerManagerCoreModule.h"
#include "vtkPVVTKExtensionsDefaultModule.h"

#endif
