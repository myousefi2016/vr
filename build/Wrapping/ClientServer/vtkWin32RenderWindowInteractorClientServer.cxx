// ClientServer wrapper for vtkWin32RenderWindowInteractor object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkWin32RenderWindowInteractor.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkWin32RenderWindowInteractorClientServerNewCommand(void* /*ctx*/)
{
  return vtkWin32RenderWindowInteractor::New();
}


int VTK_EXPORT vtkWin32RenderWindowInteractorCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkWin32RenderWindowInteractor *op = vtkWin32RenderWindowInteractor::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkWin32RenderWindowInteractor.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkWin32RenderWindowInteractor  *temp20;
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
    vtkWin32RenderWindowInteractor  *temp20;
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
    vtkWin32RenderWindowInteractor  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Initialize",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Initialize();
      return 1;
      }
    }
  if (!strcmp("Enable",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Enable();
      return 1;
      }
    }
  if (!strcmp("Disable",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Disable();
      return 1;
      }
    }
  if (!strcmp("SetInstallMessageProc",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetInstallMessageProc(temp0);
      return 1;
      }
    }
  if (!strcmp("GetInstallMessageProc",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetInstallMessageProc();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("InstallMessageProcOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->InstallMessageProcOn();
      return 1;
      }
    }
  if (!strcmp("InstallMessageProcOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->InstallMessageProcOff();
      return 1;
      }
    }
  if (!strcmp("TerminateApp",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->TerminateApp();
      return 1;
      }
    }
  if (!strcmp("ExitCallback",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->ExitCallback();
      return 1;
      }
    }

  {
    const char* commandName = "vtkRenderWindowInteractor";
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
  vtkmsg << "Object type: vtkWin32RenderWindowInteractor, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkWin32RenderWindowInteractor_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkWin32RenderWindowInteractor", vtkWin32RenderWindowInteractorClientServerNewCommand);
    csi->AddCommandFunction("vtkWin32RenderWindowInteractor", vtkWin32RenderWindowInteractorCommand);
    }
}
