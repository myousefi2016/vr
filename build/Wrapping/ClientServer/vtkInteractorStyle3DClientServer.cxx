// ClientServer wrapper for vtkInteractorStyle3D object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkInteractorStyle3D.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkInteractorStyle3DClientServerNewCommand(void* /*ctx*/)
{
  return vtkInteractorStyle3D::New();
}


int VTK_EXPORT vtkInteractorStyle3DCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkInteractorStyle3D *op = vtkInteractorStyle3D::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkInteractorStyle3D.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkInteractorStyle3D  *temp20;
      {
      temp20 = (op)->New();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetClassName",method) && msg.GetNumberOfArguments(0) == 2)
    {
    const char    *temp20;
      {
      temp20 = (op)->GetClassName();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("IsA",method) && msg.GetNumberOfArguments(0) == 3)
    {
    char    *temp0;
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0))
      {
      temp20 = (op)->IsA(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("NewInstance",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkInteractorStyle3D  *temp20;
      {
      temp20 = (op)->NewInstance();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SafeDownCast",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkObject  *temp0;
    vtkInteractorStyle3D  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("OnMouseMove",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnMouseMove();
      return 1;
      }
    }
  if (!strcmp("OnLeftButtonDown",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnLeftButtonDown();
      return 1;
      }
    }
  if (!strcmp("OnLeftButtonUp",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnLeftButtonUp();
      return 1;
      }
    }
  if (!strcmp("OnRightButtonDown",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnRightButtonDown();
      return 1;
      }
    }
  if (!strcmp("OnRightButtonUp",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnRightButtonUp();
      return 1;
      }
    }
  if (!strcmp("OnMiddleButtonDown",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnMiddleButtonDown();
      return 1;
      }
    }
  if (!strcmp("OnMiddleButtonUp",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnMiddleButtonUp();
      return 1;
      }
    }
  if (!strcmp("OnPinch",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnPinch();
      return 1;
      }
    }
  if (!strcmp("OnPan",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->OnPan();
      return 1;
      }
    }
  if (!strcmp("Rotate",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Rotate();
      return 1;
      }
    }
  if (!strcmp("Dolly",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Dolly();
      return 1;
      }
    }
  if (!strcmp("Clip",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Clip();
      return 1;
      }
    }
  if (!strcmp("StartClip",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->StartClip();
      return 1;
      }
    }
  if (!strcmp("EndClip",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->EndClip();
      return 1;
      }
    }
  if (!strcmp("SetDollyMotionFactor",method) && msg.GetNumberOfArguments(0) == 3)
    {
    double   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetDollyMotionFactor(temp0);
      return 1;
      }
    }
  if (!strcmp("GetDollyMotionFactor",method) && msg.GetNumberOfArguments(0) == 2)
    {
    double   temp20;
      {
      temp20 = (op)->GetDollyMotionFactor();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetDistance",method) && msg.GetNumberOfArguments(0) == 4)
    {
    vtkCamera  *temp0;
    double   temp1;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkCamera") &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetDistance(temp0,temp1);
      return 1;
      }
    }

  {
    const char* commandName = "vtkInteractorStyle";
    if (arlu->HasCommandFunction(commandName) &&
        arlu->CallCommandFunction(commandName, op, method, msg, resultStream)) { return 1; }
  }
  if(resultStream.GetNumberOfMessages() > 0 &&
     resultStream.GetCommand(0) == vtkClientServerStream::Error &&
     resultStream.GetNumberOfArguments(0) > 1)
    {
    /* A superclass wrapper prepared a special message. */
    return 0;
    }
  vtkOStrStreamWrapper vtkmsg;
  vtkmsg << "Object type: vtkInteractorStyle3D, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkInteractorStyle3D_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkInteractorStyle3D", vtkInteractorStyle3DClientServerNewCommand);
    csi->AddCommandFunction("vtkInteractorStyle3D", vtkInteractorStyle3DCommand);
    }
}
