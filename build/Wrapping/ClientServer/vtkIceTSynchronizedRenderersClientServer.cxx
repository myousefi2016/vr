// ClientServer wrapper for vtkIceTSynchronizedRenderers object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkIceTSynchronizedRenderers.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkIceTSynchronizedRenderersClientServerNewCommand(void* /*ctx*/)
{
  return vtkIceTSynchronizedRenderers::New();
}


int VTK_EXPORT vtkIceTSynchronizedRenderersCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkIceTSynchronizedRenderers *op = vtkIceTSynchronizedRenderers::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkIceTSynchronizedRenderers.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkIceTSynchronizedRenderers  *temp20;
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
    vtkIceTSynchronizedRenderers  *temp20;
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
    vtkIceTSynchronizedRenderers  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetIdentifier",method) && msg.GetNumberOfArguments(0) == 3)
    {
    unsigned int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetIdentifier(temp0);
      return 1;
      }
    }
  if (!strcmp("GetIdentifier",method) && msg.GetNumberOfArguments(0) == 2)
    {
    unsigned int      temp20;
      {
      temp20 = (op)->GetIdentifier();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetRenderer",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkRenderer  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkRenderer"))
      {
      op->SetRenderer(temp0);
      return 1;
      }
    }
  if (!strcmp("SetTileDimensions",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetTileDimensions(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetTileMullions",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetTileMullions(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetDataReplicatedOnAllProcesses",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetDataReplicatedOnAllProcesses(temp0);
      return 1;
      }
    }
  if (!strcmp("SetPartitionOrdering",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkPartitionOrderingInterface  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkPartitionOrderingInterface"))
      {
      op->SetPartitionOrdering(temp0);
      return 1;
      }
    }
  if (!strcmp("SetUseOrderedCompositing",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetUseOrderedCompositing(temp0);
      return 1;
      }
    }
  if (!strcmp("SetImageReductionFactor",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetImageReductionFactor(temp0);
      return 1;
      }
    }
  if (!strcmp("GetImageReductionFactor",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetImageReductionFactor();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetParallelController",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkMultiProcessController  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkMultiProcessController"))
      {
      op->SetParallelController(temp0);
      return 1;
      }
    }
  if (!strcmp("SetImageProcessingPass",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkImageProcessingPass  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkImageProcessingPass"))
      {
      op->SetImageProcessingPass(temp0);
      return 1;
      }
    }
  if (!strcmp("GetImageProcessingPass",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkImageProcessingPass  *temp20;
      {
      temp20 = (op)->GetImageProcessingPass();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetUseDepthBuffer",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetUseDepthBuffer(temp0);
      return 1;
      }
    }
  if (!strcmp("SetRenderEmptyImages",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetRenderEmptyImages(temp0);
      return 1;
      }
    }
  if (!strcmp("SetRenderPass",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkRenderPass  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkRenderPass"))
      {
      op->SetRenderPass(temp0);
      return 1;
      }
    }
  if (!strcmp("GetRenderPass",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkRenderPass  *temp20;
      {
      temp20 = (op)->GetRenderPass();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetIceTCompositePass",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkIceTCompositePass  *temp20;
      {
      temp20 = (op)->GetIceTCompositePass();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }

  {
    const char* commandName = "vtkSynchronizedRenderers";
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
  vtkmsg << "Object type: vtkIceTSynchronizedRenderers, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkIceTSynchronizedRenderers_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkIceTSynchronizedRenderers", vtkIceTSynchronizedRenderersClientServerNewCommand);
    csi->AddCommandFunction("vtkIceTSynchronizedRenderers", vtkIceTSynchronizedRenderersCommand);
    }
}
