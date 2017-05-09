
#ifndef VTKIOTRUCHAS_EXPORT_H
#define VTKIOTRUCHAS_EXPORT_H

#ifdef VTKIOTRUCHAS_STATIC_DEFINE
#  define VTKIOTRUCHAS_EXPORT
#  define VTKIOTRUCHAS_NO_EXPORT
#else
#  ifndef VTKIOTRUCHAS_EXPORT
#    ifdef vtkIOTRUCHAS_EXPORTS
        /* We are building this library */
#      define VTKIOTRUCHAS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOTRUCHAS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOTRUCHAS_NO_EXPORT
#    define VTKIOTRUCHAS_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOTRUCHAS_DEPRECATED
#  define VTKIOTRUCHAS_DEPRECATED __declspec(deprecated)
#  define VTKIOTRUCHAS_DEPRECATED_EXPORT VTKIOTRUCHAS_EXPORT __declspec(deprecated)
#  define VTKIOTRUCHAS_DEPRECATED_NO_EXPORT VTKIOTRUCHAS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOTRUCHAS_NO_DEPRECATED
#endif



#endif
