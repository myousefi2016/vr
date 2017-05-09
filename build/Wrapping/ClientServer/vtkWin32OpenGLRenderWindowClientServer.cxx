// ClientServer wrapper for vtkWin32OpenGLRenderWindow object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkWin32OpenGLRenderWindow.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkWin32OpenGLRenderWindowClientServerNewCommand(void* /*ctx*/)
{
  return vtkWin32OpenGLRenderWindow::New();
}


int VTK_EXPORT vtkWin32OpenGLRenderWindowCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkWin32OpenGLRenderWindow *op = vtkWin32OpenGLRenderWindow::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkWin32OpenGLRenderWindow.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkWin32OpenGLRenderWindow  *temp20;
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
    vtkWin32OpenGLRenderWindow  *temp20;
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
    vtkWin32OpenGLRenderWindow  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Start",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Start();
      return 1;
      }
    }
  if (!strcmp("Frame",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Frame();
      return 1;
      }
    }
  if (!strcmp("WindowInitialize",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->WindowInitialize();
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
  if (!strcmp("Finalize",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Finalize();
      return 1;
      }
    }
  if (!strcmp("SetFullScreen",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetFullScreen(temp0);
      return 1;
      }
    }
  if (!strcmp("WindowRemap",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->WindowRemap();
      return 1;
      }
    }
  if (!strcmp("PrefFullScreen",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->PrefFullScreen();
      return 1;
      }
    }
  if (!strcmp("SetSize",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetSize(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetSize",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int    temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->SetSize(temp0);
      return 1;
      }
    }
  if (!strcmp("GetSize",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetSize();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetPosition",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetPosition(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetPosition",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int    temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->SetPosition(temp0);
      return 1;
      }
    }
  if (!strcmp("GetScreenSize",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetScreenSize();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetPosition",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetPosition();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetWindowName",method) && msg.GetNumberOfArguments(0) == 3)
    {
    char    *temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetWindowName(temp0);
      return 1;
      }
    }
  if (!strcmp("SetWindowInfo",method) && msg.GetNumberOfArguments(0) == 3)
    {
    char    *temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetWindowInfo(temp0);
      return 1;
      }
    }
  if (!strcmp("SetNextWindowInfo",method) && msg.GetNumberOfArguments(0) == 3)
    {
    char    *temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetNextWindowInfo(temp0);
      return 1;
      }
    }
  if (!strcmp("SetParentInfo",method) && msg.GetNumberOfArguments(0) == 3)
    {
    char    *temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetParentInfo(temp0);
      return 1;
      }
    }
  if (!strcmp("InitializeFromCurrentContext",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->InitializeFromCurrentContext();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetStereoCapableWindow",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetStereoCapableWindow(temp0);
      return 1;
      }
    }
  if (!strcmp("MakeCurrent",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->MakeCurrent();
      return 1;
      }
    }
  if (!strcmp("IsCurrent",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->IsCurrent();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("ReportCapabilities",method) && msg.GetNumberOfArguments(0) == 2)
    {
    const char    *temp20;
      {
      temp20 = (op)->ReportCapabilities();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("IsDirect",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->IsDirect();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetEventPending",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetEventPending();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Clean",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Clean();
      return 1;
      }
    }
  if (!strcmp("HideCursor",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->HideCursor();
      return 1;
      }
    }
  if (!strcmp("ShowCursor",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->ShowCursor();
      return 1;
      }
    }
  if (!strcmp("SetCursorPosition",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetCursorPosition(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetCurrentCursor",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetCurrentCursor(temp0);
      return 1;
      }
    }
  if (!strcmp("DetectDPI",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->DetectDPI();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetOffScreenRendering",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetOffScreenRendering(temp0);
      return 1;
      }
    }
  if (!strcmp("PushContext",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->PushContext();
      return 1;
      }
    }
  if (!strcmp("PopContext",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->PopContext();
      return 1;
      }
    }

  {
    const char* commandName = "vtkOpenGLRenderWindow";
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
  vtkmsg << "Object type: vtkWin32OpenGLRenderWindow, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkWin32OpenGLRenderWindow_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkWin32OpenGLRenderWindow", vtkWin32OpenGLRenderWindowClientServerNewCommand);
    csi->AddCommandFunction("vtkWin32OpenGLRenderWindow", vtkWin32OpenGLRenderWindowCommand);
    }
}
