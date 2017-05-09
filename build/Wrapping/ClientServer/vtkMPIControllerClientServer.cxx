// ClientServer wrapper for vtkMPIController object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkMPIController.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkMPIControllerClientServerNewCommand(void* /*ctx*/)
{
  return vtkMPIController::New();
}


int VTK_EXPORT vtkMPIControllerCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkMPIController *op = vtkMPIController::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkMPIController.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkMPIController  *temp20;
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
    vtkMPIController  *temp20;
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
    vtkMPIController  *temp20;
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
  if (!strcmp("Finalize",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Finalize();
      return 1;
      }
    }
  if (!strcmp("Finalize",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->Finalize(temp0);
      return 1;
      }
    }
  if (!strcmp("SingleMethodExecute",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SingleMethodExecute();
      return 1;
      }
    }
  if (!strcmp("MultipleMethodExecute",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->MultipleMethodExecute();
      return 1;
      }
    }
  if (!strcmp("CreateOutputWindow",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->CreateOutputWindow();
      return 1;
      }
    }
  if (!strcmp("ErrorString",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    char    *temp20;
    if(msg.GetArgument(0, 2, &temp0))
      {
      temp20 = (op)->ErrorString(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetCommunicator",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkMPICommunicator  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkMPICommunicator"))
      {
      op->SetCommunicator(temp0);
      return 1;
      }
    }
  if (!strcmp("CreateSubController",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkProcessGroup  *temp0;
    vtkMPIController  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkProcessGroup"))
      {
      temp20 = (op)->CreateSubController(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("PartitionController",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    vtkMPIController  *temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      temp20 = (op)->PartitionController(temp0,temp1);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Iprobe",method) && msg.GetNumberOfArguments(0) == 6)
    {
    int      temp0;
    int      temp1;
    vtkClientServerStreamDataArg<int    > temp2(msg, 0, 4);
    vtkClientServerStreamDataArg<int    > temp3(msg, 0, 5);
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      temp2 &&
      temp3)
      {
      temp20 = (op)->Iprobe(temp0,temp1,temp2,temp3);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Iprobe",method) && msg.GetNumberOfArguments(0) == 8)
    {
    int      temp0;
    int      temp1;
    vtkClientServerStreamDataArg<int    > temp2(msg, 0, 4);
    vtkClientServerStreamDataArg<int    > temp3(msg, 0, 5);
    vtkClientServerStreamDataArg<int    > temp4(msg, 0, 6);
    vtkClientServerStreamDataArg<int    > temp5(msg, 0, 7);
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      temp2 &&
      temp3 &&
      temp4 &&
      temp5)
      {
      temp20 = (op)->Iprobe(temp0,temp1,temp2,temp3,temp4,temp5);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Iprobe",method) && msg.GetNumberOfArguments(0) == 8)
    {
    int      temp0;
    int      temp1;
    vtkClientServerStreamDataArg<int    > temp2(msg, 0, 4);
    vtkClientServerStreamDataArg<int    > temp3(msg, 0, 5);
    vtkClientServerStreamDataArg<unsigned long   > temp4(msg, 0, 6);
    vtkClientServerStreamDataArg<int    > temp5(msg, 0, 7);
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      temp2 &&
      temp3 &&
      temp4 &&
      temp5)
      {
      temp20 = (op)->Iprobe(temp0,temp1,temp2,temp3,temp4,temp5);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Iprobe",method) && msg.GetNumberOfArguments(0) == 8)
    {
    int      temp0;
    int      temp1;
    vtkClientServerStreamDataArg<int    > temp2(msg, 0, 4);
    vtkClientServerStreamDataArg<int    > temp3(msg, 0, 5);
    char    *temp4;
    vtkClientServerStreamDataArg<int    > temp5(msg, 0, 7);
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      temp2 &&
      temp3 &&
      msg.GetArgument(0, 6, &temp4) &&
      temp5)
      {
      temp20 = (op)->Iprobe(temp0,temp1,temp2,temp3,temp4,temp5);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Iprobe",method) && msg.GetNumberOfArguments(0) == 8)
    {
    int      temp0;
    int      temp1;
    vtkClientServerStreamDataArg<int    > temp2(msg, 0, 4);
    vtkClientServerStreamDataArg<int    > temp3(msg, 0, 5);
    vtkClientServerStreamDataArg<float  > temp4(msg, 0, 6);
    vtkClientServerStreamDataArg<int    > temp5(msg, 0, 7);
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      temp2 &&
      temp3 &&
      temp4 &&
      temp5)
      {
      temp20 = (op)->Iprobe(temp0,temp1,temp2,temp3,temp4,temp5);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Iprobe",method) && msg.GetNumberOfArguments(0) == 8)
    {
    int      temp0;
    int      temp1;
    vtkClientServerStreamDataArg<int    > temp2(msg, 0, 4);
    vtkClientServerStreamDataArg<int    > temp3(msg, 0, 5);
    vtkClientServerStreamDataArg<double > temp4(msg, 0, 6);
    vtkClientServerStreamDataArg<int    > temp5(msg, 0, 7);
    int      temp20;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      temp2 &&
      temp3 &&
      temp4 &&
      temp5)
      {
      temp20 = (op)->Iprobe(temp0,temp1,temp2,temp3,temp4,temp5);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetProcessorName",method) && msg.GetNumberOfArguments(0) == 2)
    {
    const char    *temp20;
      {
      temp20 = (op)->GetProcessorName();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetUseSsendForRMI",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetUseSsendForRMI(temp0);
      return 1;
      }
    }
  if (!strcmp("GetUseSsendForRMI",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetUseSsendForRMI();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }

  {
    const char* commandName = "vtkMultiProcessController";
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
  vtkmsg << "Object type: vtkMPIController, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkMPIController_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkMPIController", vtkMPIControllerClientServerNewCommand);
    csi->AddCommandFunction("vtkMPIController", vtkMPIControllerCommand);
    }
}
