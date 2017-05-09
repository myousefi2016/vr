
#ifndef PQCOMPONENTS_EXPORT_H
#define PQCOMPONENTS_EXPORT_H

#ifdef PQCOMPONENTS_STATIC_DEFINE
#  define PQCOMPONENTS_EXPORT
#  define PQCOMPONENTS_NO_EXPORT
#else
#  ifndef PQCOMPONENTS_EXPORT
#    ifdef pqComponents_EXPORTS
        /* We are building this library */
#      define PQCOMPONENTS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQCOMPONENTS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQCOMPONENTS_NO_EXPORT
#    define PQCOMPONENTS_NO_EXPORT 
#  endif
#endif

#ifndef PQCOMPONENTS_DEPRECATED
#  define PQCOMPONENTS_DEPRECATED __declspec(deprecated)
#  define PQCOMPONENTS_DEPRECATED_EXPORT PQCOMPONENTS_EXPORT __declspec(deprecated)
#  define PQCOMPONENTS_DEPRECATED_NO_EXPORT PQCOMPONENTS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define PQCOMPONENTS_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "pqCoreModule.h"

#endif
