
#ifndef VTKPUGIXML_EXPORT_H
#define VTKPUGIXML_EXPORT_H

#ifdef VTKPUGIXML_STATIC_DEFINE
#  define VTKPUGIXML_EXPORT
#  define VTKPUGIXML_NO_EXPORT
#else
#  ifndef VTKPUGIXML_EXPORT
#    ifdef vtkpugixml_EXPORTS
        /* We are building this library */
#      define VTKPUGIXML_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKPUGIXML_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKPUGIXML_NO_EXPORT
#    define VTKPUGIXML_NO_EXPORT 
#  endif
#endif

#ifndef VTKPUGIXML_DEPRECATED
#  define VTKPUGIXML_DEPRECATED __declspec(deprecated)
#  define VTKPUGIXML_DEPRECATED_EXPORT VTKPUGIXML_EXPORT __declspec(deprecated)
#  define VTKPUGIXML_DEPRECATED_NO_EXPORT VTKPUGIXML_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKPUGIXML_NO_DEPRECATED
#endif



#endif
