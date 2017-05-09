// ClientServer wrapper for vtkExtractHistogram2D object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkExtractHistogram2D.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkExtractHistogram2DClientServerNewCommand(void* /*ctx*/)
{
  return vtkExtractHistogram2D::New();
}


int VTK_EXPORT vtkExtractHistogram2DCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkExtractHistogram2D *op = vtkExtractHistogram2D::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkExtractHistogram2D.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkExtractHistogram2D  *temp20;
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
    vtkExtractHistogram2D  *temp20;
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
    vtkExtractHistogram2D  *temp20;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkObject"))
      {
      temp20 = (op)->SafeDownCast(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetNumberOfBins",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetNumberOfBins(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetNumberOfBins",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int    temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->SetNumberOfBins(temp0);
      return 1;
      }
    }
  if (!strcmp("GetNumberOfBins",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetNumberOfBins();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetComponentsToProcess",method) && msg.GetNumberOfArguments(0) == 4)
    {
    int      temp0;
    int      temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetComponentsToProcess(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetComponentsToProcess",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int    temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->SetComponentsToProcess(temp0);
      return 1;
      }
    }
  if (!strcmp("GetComponentsToProcess",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int     *temp20;
      {
      temp20 = (op)->GetComponentsToProcess();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,2) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetCustomHistogramExtents",method) && msg.GetNumberOfArguments(0) == 6)
    {
    double   temp0;
    double   temp1;
    double   temp2;
    double   temp3;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      msg.GetArgument(0, 4, &temp2) &&
      msg.GetArgument(0, 5, &temp3))
      {
      op->SetCustomHistogramExtents(temp0,temp1,temp2,temp3);
      return 1;
      }
    }
  if (!strcmp("SetCustomHistogramExtents",method) && msg.GetNumberOfArguments(0) == 3)
    {
    double temp0[4];
    if(msg.GetArgument(0, 2, temp0, 4))
      {
      op->SetCustomHistogramExtents(temp0);
      return 1;
      }
    }
  if (!strcmp("GetCustomHistogramExtents",method) && msg.GetNumberOfArguments(0) == 2)
    {
    double  *temp20;
      {
      temp20 = (op)->GetCustomHistogramExtents();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << vtkClientServerStream::InsertArray(temp20,4) << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetUseCustomHistogramExtents",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetUseCustomHistogramExtents(temp0);
      return 1;
      }
    }
  if (!strcmp("GetUseCustomHistogramExtents",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetUseCustomHistogramExtents();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("UseCustomHistogramExtentsOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseCustomHistogramExtentsOn();
      return 1;
      }
    }
  if (!strcmp("UseCustomHistogramExtentsOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->UseCustomHistogramExtentsOff();
      return 1;
      }
    }
  if (!strcmp("SetScalarType",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetScalarType(temp0);
      return 1;
      }
    }
  if (!strcmp("SetScalarTypeToUnsignedInt",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetScalarTypeToUnsignedInt();
      return 1;
      }
    }
  if (!strcmp("SetScalarTypeToUnsignedLong",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetScalarTypeToUnsignedLong();
      return 1;
      }
    }
  if (!strcmp("SetScalarTypeToUnsignedShort",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetScalarTypeToUnsignedShort();
      return 1;
      }
    }
  if (!strcmp("SetScalarTypeToUnsignedChar",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetScalarTypeToUnsignedChar();
      return 1;
      }
    }
  if (!strcmp("SetScalarTypeToFloat",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetScalarTypeToFloat();
      return 1;
      }
    }
  if (!strcmp("SetScalarTypeToDouble",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SetScalarTypeToDouble();
      return 1;
      }
    }
  if (!strcmp("GetScalarType",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetScalarType();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetMaximumBinCount",method) && msg.GetNumberOfArguments(0) == 2)
    {
    double   temp20;
      {
      temp20 = (op)->GetMaximumBinCount();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetBinWidth",method) && msg.GetNumberOfArguments(0) == 3)
    {
    double temp0[2];
    if(msg.GetArgument(0, 2, temp0, 2))
      {
      op->GetBinWidth(temp0);
      return 1;
      }
    }
  if (!strcmp("GetOutputHistogramImage",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkImageData  *temp20;
      {
      temp20 = (op)->GetOutputHistogramImage();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SetSwapColumns",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetSwapColumns(temp0);
      return 1;
      }
    }
  if (!strcmp("GetSwapColumns",method) && msg.GetNumberOfArguments(0) == 2)
    {
    int      temp20;
      {
      temp20 = (op)->GetSwapColumns();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("SwapColumnsOn",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SwapColumnsOn();
      return 1;
      }
    }
  if (!strcmp("SwapColumnsOff",method) && msg.GetNumberOfArguments(0) == 2)
    {
      {
      op->SwapColumnsOff();
      return 1;
      }
    }
  if (!strcmp("SetRowMask",method) && msg.GetNumberOfArguments(0) == 3)
    {
    vtkDataArray  *temp0;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkDataArray"))
      {
      op->SetRowMask(temp0);
      return 1;
      }
    }
  if (!strcmp("GetRowMask",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkDataArray  *temp20;
      {
      temp20 = (op)->GetRowMask();
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("Aggregate",method) && msg.GetNumberOfArguments(0) == 4)
    {
    vtkDataObjectCollection  *temp0;
    vtkMultiBlockDataSet  *temp1;
    if(vtkClientServerStreamGetArgumentObject(msg, 0, 2, &temp0, "vtkDataObjectCollection") &&
      vtkClientServerStreamGetArgumentObject(msg, 0, 3, &temp1, "vtkMultiBlockDataSet"))
      {
      op->Aggregate(temp0,temp1);
      return 1;
      }
    }

  {
    const char* commandName = "vtkStatisticsAlgorithm";
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
  vtkmsg << "Object type: vtkExtractHistogram2D, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkExtractHistogram2D_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkExtractHistogram2D", vtkExtractHistogram2DClientServerNewCommand);
    csi->AddCommandFunction("vtkExtractHistogram2D", vtkExtractHistogram2DCommand);
    }
}
