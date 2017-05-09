
#ifndef VTKPVSERVERMANAGERCORE_EXPORT_H
#define VTKPVSERVERMANAGERCORE_EXPORT_H

#ifdef VTKPVSERVERMANAGERCORE_STATIC_DEFINE
#  define VTKPVSERVERMANAGERCORE_EXPORT
#  define VTKPVSERVERMANAGERCORE_NO_EXPORT
#else
#  ifndef VTKPVSERVERMANAGERCORE_EXPORT
#    ifdef vtkPVServerManagerCore_EXPORTS
        /* We are building this library */
#      define VTKPVSERVERMANAGERCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPVSERVERMANAGERCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPVSERVERMANAGERCORE_NO_EXPORT
#    define VTKPVSERVERMANAGERCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKPVSERVERMANAGERCORE_DEPRECATED
#  define VTKPVSERVERMANAGERCORE_DEPRECATED __declspec(deprecated)
#  define VTKPVSERVERMANAGERCORE_DEPRECATED_EXPORT VTKPVSERVERMANAGERCORE_EXPORT __declspec(deprecated)
#  define VTKPVSERVERMANAGERCORE_DEPRECATED_NO_EXPORT VTKPVSERVERMANAGERCORE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPVSERVERMANAGERCORE_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkPVServerImplementationCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkPVServerManagerCore_INCLUDE)
# include vtkPVServerManagerCore_INCLUDE
#endif
#if defined(vtkPVServerManagerCore_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkPVServerManagerCore)
#endif

#endif
