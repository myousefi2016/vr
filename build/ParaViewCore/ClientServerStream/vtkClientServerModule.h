
#ifndef VTKCLIENTSERVER_EXPORT_H
#define VTKCLIENTSERVER_EXPORT_H

#ifdef VTKCLIENTSERVER_STATIC_DEFINE
#  define VTKCLIENTSERVER_EXPORT
#  define VTKCLIENTSERVER_NO_EXPORT
#else
#  ifndef VTKCLIENTSERVER_EXPORT
#    ifdef vtkClientServer_EXPORTS
        /* We are building this library */
#      define VTKCLIENTSERVER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCLIENTSERVER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCLIENTSERVER_NO_EXPORT
#    define VTKCLIENTSERVER_NO_EXPORT 
#  endif
#endif

#ifndef VTKCLIENTSERVER_DEPRECATED
#  define VTKCLIENTSERVER_DEPRECATED __declspec(deprecated)
#  define VTKCLIENTSERVER_DEPRECATED_EXPORT VTKCLIENTSERVER_EXPORT __declspec(deprecated)
#  define VTKCLIENTSERVER_DEPRECATED_NO_EXPORT VTKCLIENTSERVER_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKCLIENTSERVER_NO_DEPRECATED
#endif



#endif
