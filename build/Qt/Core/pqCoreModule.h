
#ifndef PQCORE_EXPORT_H
#define PQCORE_EXPORT_H

#ifdef PQCORE_STATIC_DEFINE
#  define PQCORE_EXPORT
#  define PQCORE_NO_EXPORT
#else
#  ifndef PQCORE_EXPORT
#    ifdef pqCore_EXPORTS
        /* We are building this library */
#      define PQCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQCORE_NO_EXPORT
#    define PQCORE_NO_EXPORT 
#  endif
#endif

#ifndef PQCORE_DEPRECATED
#  define PQCORE_DEPRECATED __declspec(deprecated)
#  define PQCORE_DEPRECATED_EXPORT PQCORE_EXPORT __declspec(deprecated)
#  define PQCORE_DEPRECATED_NO_EXPORT PQCORE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define PQCORE_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "pqWidgetsModule.h"
#include "vtkGUISupportQtModule.h"

#endif
