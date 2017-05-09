
#ifndef VTKFILTERSPARALLELFLOWPATHS_EXPORT_H
#define VTKFILTERSPARALLELFLOWPATHS_EXPORT_H

#ifdef VTKFILTERSPARALLELFLOWPATHS_STATIC_DEFINE
#  define VTKFILTERSPARALLELFLOWPATHS_EXPORT
#  define VTKFILTERSPARALLELFLOWPATHS_NO_EXPORT
#else
#  ifndef VTKFILTERSPARALLELFLOWPATHS_EXPORT
#    ifdef vtkFiltersParallelFlowPaths_EXPORTS
        /* We are building this library */
#      define VTKFILTERSPARALLELFLOWPATHS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSPARALLELFLOWPATHS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSPARALLELFLOWPATHS_NO_EXPORT
#    define VTKFILTERSPARALLELFLOWPATHS_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSPARALLELFLOWPATHS_DEPRECATED
#  define VTKFILTERSPARALLELFLOWPATHS_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSPARALLELFLOWPATHS_DEPRECATED_EXPORT VTKFILTERSPARALLELFLOWPATHS_EXPORT __declspec(deprecated)
#  define VTKFILTERSPARALLELFLOWPATHS_DEPRECATED_NO_EXPORT VTKFILTERSPARALLELFLOWPATHS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSPARALLELFLOWPATHS_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkFiltersFlowPathsModule.h"
#include "vtkFiltersFlowPathsModule.h"

/* AutoInit implementations.  */
#if defined(vtkFiltersParallelFlowPaths_INCLUDE)
# include vtkFiltersParallelFlowPaths_INCLUDE
#endif
#if defined(vtkFiltersParallelFlowPaths_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkFiltersParallelFlowPaths)
#endif

#endif
