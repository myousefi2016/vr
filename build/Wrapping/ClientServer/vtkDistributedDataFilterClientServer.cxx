// ClientServer wrapper for vtkDistributedDataFilter object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkDistributedDataFilter.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkDistributedDataFilterClientServerNewCommand(void* /*ctx*/)
{
  return vtkDistributedDataFilter::New();
}


int VTK_EXPORT vtkDistributedDataFilterCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkDistributedDataFilter *op = vtkDistributedDataFilter::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkDistributedDataFilter.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkDistributedDataFilter  *temp20;
      {
      temp20 = (op)->New();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetController",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkMultiProcessController  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkMultiProcessController"))
      {
      op->SetController(temp0);
      return 1;
      }
    }
  if (!strcmp("GetController",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkMultiProcessController  *temp20;
      {
      temp20 = (op)->GetController();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetKdtree",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkPKdTree  *temp20;
      {
      temp20 = (op)->GetKdtree();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("RetainKdtreeOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->RetainKdtreeOn();
      return 1;
      }
    }
  if (!strcmp("RetainKdtreeOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->RetainKdtreeOff();
      return 1;
      }
    }
  if (!strcmp("GetRetainKdtree",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetRetainKdtree();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetRetainKdtree",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetRetainKdtree(temp0);
      return 1;
      }
    }
  if (!strcmp("IncludeAllIntersectingCellsOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->IncludeAllIntersectingCellsOn();
      return 1;
      }
    }
  if (!strcmp("IncludeAllIntersectingCellsOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->IncludeAllIntersectingCellsOff();
      return 1;
      }
    }
  if (!strcmp("GetIncludeAllIntersectingCells",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetIncludeAllIntersectingCells();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetIncludeAllIntersectingCells",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetIncludeAllIntersectingCells(temp0);
      return 1;
      }
    }
  if (!strcmp("ClipCellsOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->ClipCellsOn();
      return 1;
      }
    }
  if (!strcmp("ClipCellsOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->ClipCellsOff();
      return 1;
      }
    }
  if (!strcmp("GetClipCells",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetClipCells();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetClipCells",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetClipCells(temp0);
      return 1;
      }
    }
  if (!strcmp("SetBoundaryMode",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetBoundaryMode(temp0);
      return 1;
      }
    }
  if (!strcmp("SetBoundaryModeToAssignToOneRegion",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetBoundaryModeToAssignToOneRegion();
      return 1;
      }
    }
  if (!strcmp("SetBoundaryModeToAssignToAllIntersectingRegions",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetBoundaryModeToAssignToAllIntersectingRegions();
      return 1;
      }
    }
  if (!strcmp("SetBoundaryModeToSplitBoundaryCells",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetBoundaryModeToSplitBoundaryCells();
      return 1;
      }
    }
  if (!strcmp("GetBoundaryMode",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetBoundaryMode();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("UseMinimalMemoryOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseMinimalMemoryOn();
      return 1;
      }
    }
  if (!strcmp("UseMinimalMemoryOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseMinimalMemoryOff();
      return 1;
      }
    }
  if (!strcmp("GetUseMinimalMemory",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetUseMinimalMemory();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetUseMinimalMemory",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetUseMinimalMemory(temp0);
      return 1;
      }
    }
  if (!strcmp("TimingOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->TimingOn();
      return 1;
      }
    }
  if (!strcmp("TimingOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->TimingOff();
      return 1;
      }
    }
  if (!strcmp("SetTiming",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetTiming(temp0);
      return 1;
      }
    }
  if (!strcmp("GetTiming",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetTiming();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetCuts",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkBSPCuts  *temp20;
      {
      temp20 = (op)->GetCuts();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetCuts",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkBSPCuts  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkBSPCuts"))
      {
      op->SetCuts(temp0);
      return 1;
      }
    }
  if (!strcmp("SetUserRegionAssignments",method) && msg.GetNumberOfArguments(0) == 4)
    {
    vtkClientServerStreamDataArg<int    > temp0(msg, 0, 2);
    int      temp1;
    if(temp0 &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetUserRegionAssignments(temp0,temp1);
      return 1;
      }
    }

  {
    const char* commandName = "vtkDataObjectAlgorithm";
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
  vtkmsg << "Object type: vtkDistributedDataFilter, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkDistributedDataFilter_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkDistributedDataFilter", vtkDistributedDataFilterClientServerNewCommand);
    csi->AddCommandFunction("vtkDistributedDataFilter", vtkDistributedDataFilterCommand);
    }
}
