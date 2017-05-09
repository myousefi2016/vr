
#ifndef PQWIDGETS_EXPORT_H
#define PQWIDGETS_EXPORT_H

#ifdef PQWIDGETS_STATIC_DEFINE
#  define PQWIDGETS_EXPORT
#  define PQWIDGETS_NO_EXPORT
#else
#  ifndef PQWIDGETS_EXPORT
#    ifdef pqWidgets_EXPORTS
        /* We are building this library */
#      define PQWIDGETS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQWIDGETS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQWIDGETS_NO_EXPORT
#    define PQWIDGETS_NO_EXPORT 
#  endif
#endif

#ifndef PQWIDGETS_DEPRECATED
#  define PQWIDGETS_DEPRECATED __declspec(deprecated)
#  define PQWIDGETS_DEPRECATED_EXPORT PQWIDGETS_EXPORT __declspec(deprecated)
#  define PQWIDGETS_DEPRECATED_NO_EXPORT PQWIDGETS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define PQWIDGETS_NO_DEPRECATED
#endif

#ifndef PARAVIEW_USE_QTHELP
#  define PARAVIEW_USE_QTHELP
#endif


/* AutoInit dependencies.  */
#include "vtkGUISupportQtModule.h"
#include "vtkPVServerManagerCoreModule.h"

#endif
