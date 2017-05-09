
#ifndef VTKPVCATALYST_EXPORT_H
#define VTKPVCATALYST_EXPORT_H

#ifdef VTKPVCATALYST_STATIC_DEFINE
#  define VTKPVCATALYST_EXPORT
#  define VTKPVCATALYST_NO_EXPORT
#else
#  ifndef VTKPVCATALYST_EXPORT
#    ifdef vtkPVCatalyst_EXPORTS
        /* We are building this library */
#      define VTKPVCATALYST_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPVCATALYST_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPVCATALYST_NO_EXPORT
#    define VTKPVCATALYST_NO_EXPORT 
#  endif
#endif

#ifndef VTKPVCATALYST_DEPRECATED
#  define VTKPVCATALYST_DEPRECATED __declspec(deprecated)
#  define VTKPVCATALYST_DEPRECATED_EXPORT VTKPVCATALYST_EXPORT __declspec(deprecated)
#  define VTKPVCATALYST_DEPRECATED_NO_EXPORT VTKPVCATALYST_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPVCATALYST_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkPVServerManagerApplicationModule.h"

#endif
