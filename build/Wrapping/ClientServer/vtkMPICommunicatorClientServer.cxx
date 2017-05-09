// ClientServer wrapper for vtkMPICommunicator object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkMPICommunicator.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkMPICommunicatorClientServerNewCommand(void* /*ctx*/)
{
  return vtkMPICommunicator::New();
}


int VTK_EXPORT vtkMPICommunicatorCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkMPICommunicator *op = vtkMPICommunicator::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkMPICommunicator.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
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
    vtkMPICommunicator  *temp20;
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
    vtkMPICommunicator  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkMPICommunicator  *temp20;
      {
      temp20 = (op)->New();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetWorldCommunicator",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkMPICommunicator  *temp20;
      {
      temp20 = (op)->GetWorldCommunicator();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Initialize",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkProcessGroup  *temp0;
    int      temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkProcessGroup"))
      {
      temp20 = (op)->Initialize(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SplitInitialize",method) && msg.GetNumberOfArguments(0) == 5)
    {
    vtkCommunicator  *temp0;
    int      temp1;
    int      temp2;
    int      temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkCommunicator") &&
      msg.GetArgument(0, 3, &temp1) &&
      msg.GetArgument(0, 4, &temp2))
      {
      temp20 = (op)->SplitInitialize(temp0,temp1,temp2);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Barrier",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->Barrier();
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
  if (!strcmp("GetMPIComm",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkMPICommunicatorOpaqueComm  *temp20;
      {
      temp20 = (op)->GetMPIComm();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("InitializeExternal",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkMPICommunicatorOpaqueComm  *temp0;
    int      temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkMPICommunicatorOpaqueComm"))
      {
      temp20 = (op)->InitializeExternal(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Free",method) && msg.GetNumberOfArguments(0) == 3)
    {
    char    *temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->Free(temp0);
      return 1;
      }
    }
  if (!strcmp("SetUseSsend",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetUseSsend(temp0);
      return 1;
      }
    }
  if (!strcmp("GetUseSsendMinValue",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetUseSsendMinValue();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetUseSsendMaxValue",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetUseSsendMaxValue();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetUseSsend",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetUseSsend();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("UseSsendOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseSsendOn();
      return 1;
      }
    }
  if (!strcmp("UseSsendOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseSsendOff();
      return 1;
      }
    }
  if (!strcmp("CopyFrom",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkMPICommunicator  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkMPICommunicator"))
      {
      op->CopyFrom(temp0);
      return 1;
      }
    }

  {
    const char* commandName = "vtkCommunicator";
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
  vtkmsg << "Object type: vtkMPICommunicator, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkMPICommunicator_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkMPICommunicator", vtkMPICommunicatorClientServerNewCommand);
    csi->AddCommandFunction("vtkMPICommunicator", vtkMPICommunicatorCommand);
    }
}
