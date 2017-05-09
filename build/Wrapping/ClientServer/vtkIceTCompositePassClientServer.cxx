// ClientServer wrapper for vtkIceTCompositePass object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkIceTCompositePass.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkIceTCompositePassClientServerNewCommand(void* /*ctx*/)
{
  return vtkIceTCompositePass::New();
}


int VTK_EXPORT vtkIceTCompositePassCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkIceTCompositePass *op = vtkIceTCompositePass::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkIceTCompositePass.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkIceTCompositePass  *temp20;
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
    vtkIceTCompositePass  *temp20;
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
    vtkIceTCompositePass  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Render",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkRenderState  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkRenderState"))
      {
      op->Render(temp0);
      return 1;
      }
    }
  if (!strcmp("ReleaseGraphicsResources",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkWindow  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkWindow"))
      {
      op->ReleaseGraphicsResources(temp0);
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
  if (!strcmp("SetController",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkMultiProcessController  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkMultiProcessController"))
      {
      op->SetController(temp0);
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
  if (!strcmp("SetTileDimensions",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int    temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->SetTileDimensions(temp0);
      return 1;
      }
    }
  if (!strcmp("GetTileDimensions",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetTileDimensions();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
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
  if (!strcmp("SetTileMullions",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int    temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->SetTileMullions(temp0);
      return 1;
      }
    }
  if (!strcmp("GetTileMullions",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetTileMullions();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
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
  if (!strcmp("GetDataReplicatedOnAllProcesses",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->GetDataReplicatedOnAllProcesses();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("DataReplicatedOnAllProcessesOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->DataReplicatedOnAllProcessesOn();
      return 1;
      }
    }
  if (!strcmp("DataReplicatedOnAllProcessesOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->DataReplicatedOnAllProcessesOff();
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
  if (!strcmp("GetImageReductionFactorMinValue",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetImageReductionFactorMinValue();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetImageReductionFactorMaxValue",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetImageReductionFactorMaxValue();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
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
  if (!strcmp("GetPartitionOrdering",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkPartitionOrderingInterface  *temp20;
      {
      temp20 = (op)->GetPartitionOrdering();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
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
  if (!strcmp("GetRenderEmptyImages",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->GetRenderEmptyImages();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
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
  if (!strcmp("RenderEmptyImagesOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->RenderEmptyImagesOn();
      return 1;
      }
    }
  if (!strcmp("RenderEmptyImagesOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->RenderEmptyImagesOff();
      return 1;
      }
    }
  if (!strcmp("GetUseOrderedCompositing",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->GetUseOrderedCompositing();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
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
  if (!strcmp("UseOrderedCompositingOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseOrderedCompositingOn();
      return 1;
      }
    }
  if (!strcmp("UseOrderedCompositingOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseOrderedCompositingOff();
      return 1;
      }
    }
  if (!strcmp("GetDepthOnly",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->GetDepthOnly();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetDepthOnly",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetDepthOnly(temp0);
      return 1;
      }
    }
  if (!strcmp("GetFixBackground",method) && msg.GetNumberOfArguments(0) == 2)
    {
    bool   temp20;
      {
      temp20 = (op)->GetFixBackground();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetFixBackground",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetFixBackground(temp0);
      return 1;
      }
    }
  if (!strcmp("GetLastRenderedDepths",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkFloatArray  *temp20;
      {
      temp20 = (op)->GetLastRenderedDepths();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetEnableFloatValuePass",method) && msg.GetNumberOfArguments(0) == 3)
    {
    bool   temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetEnableFloatValuePass(temp0);
      return 1;
      }
    }
  if (!strcmp("GetLastRenderedRGBA32F",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkFloatArray  *temp20;
      {
      temp20 = (op)->GetLastRenderedRGBA32F();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("PushIceTDepthBufferToScreen",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkRenderState  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkRenderState"))
      {
      op->PushIceTDepthBufferToScreen(temp0);
      return 1;
      }
    }
  if (!strcmp("PushIceTColorBufferToScreen",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkRenderState  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkRenderState"))
      {
      op->PushIceTColorBufferToScreen(temp0);
      return 1;
      }
    }
  if (!strcmp("GetPhysicalViewport",method) && msg.GetNumberOfArguments(0) == 2)
    {
    double  *temp20;
      {
      temp20 = (op)->GetPhysicalViewport();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,4) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GLDraw",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkRenderState  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkRenderState"))
      {
      op->GLDraw(temp0);
      return 1;
      }
    }

  {
    const char* commandName = "vtkRenderPass";
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
  vtkmsg << "Object type: vtkIceTCompositePass, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkIceTCompositePass_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkIceTCompositePass", vtkIceTCompositePassClientServerNewCommand);
    csi->AddCommandFunction("vtkIceTCompositePass", vtkIceTCompositePassCommand);
    }
}
