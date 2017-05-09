
#ifndef VTKPVSERVERMANAGERRENDERING_EXPORT_H
#define VTKPVSERVERMANAGERRENDERING_EXPORT_H

#ifdef VTKPVSERVERMANAGERRENDERING_STATIC_DEFINE
#  define VTKPVSERVERMANAGERRENDERING_EXPORT
#  define VTKPVSERVERMANAGERRENDERING_NO_EXPORT
#else
#  ifndef VTKPVSERVERMANAGERRENDERING_EXPORT
#    ifdef vtkPVServerManagerRendering_EXPORTS
        /* We are building this library */
#      define VTKPVSERVERMANAGERRENDERING_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPVSERVERMANAGERRENDERING_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPVSERVERMANAGERRENDERING_NO_EXPORT
#    define VTKPVSERVERMANAGERRENDERING_NO_EXPORT 
#  endif
#endif

#ifndef VTKPVSERVERMANAGERRENDERING_DEPRECATED
#  define VTKPVSERVERMANAGERRENDERING_DEPRECATED __declspec(deprecated)
#  define VTKPVSERVERMANAGERRENDERING_DEPRECATED_EXPORT VTKPVSERVERMANAGERRENDERING_EXPORT __declspec(deprecated)
#  define VTKPVSERVERMANAGERRENDERING_DEPRECATED_NO_EXPORT VTKPVSERVERMANAGERRENDERING_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPVSERVERMANAGERRENDERING_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkPVServerImplementationRenderingModule.h"
#include "vtkPVServerManagerCoreModule.h"
#include "vtkPVServerManagerCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkPVServerManagerRendering_INCLUDE)
# include vtkPVServerManagerRendering_INCLUDE
#endif
#if defined(vtkPVServerManagerRendering_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkPVServerManagerRendering)
#endif

#endif
