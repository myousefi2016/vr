// ClientServer wrapper for vtkPairwiseExtractHistogram2D object
//
#define VTK_WRAPPING_CXX
#define VTK_STREAMS_FWD_ONLY
#include "vtkPairwiseExtractHistogram2D.h"
#include "vtkSystemIncludes.h"
#include "vtkClientServerInterpreter.h"
#include "vtkClientServerStream.h"


vtkObjectBase *vtkPairwiseExtractHistogram2DClientServerNewCommand(void* /*ctx*/)
{
  return vtkPairwiseExtractHistogram2D::New();
}


int VTK_EXPORT vtkPairwiseExtractHistogram2DCommand(vtkClientServerInterpreter *arlu, vtkObjectBase *ob, const char *method, const vtkClientServerStream& msg, vtkClientServerStream& resultStream, void* /*ctx*/)
{
  vtkPairwiseExtractHistogram2D *op = vtkPairwiseExtractHistogram2D::SafeDownCast(ob);
  if(!op)
    {
    vtkOStrStreamWrapper vtkmsg;
    vtkmsg << "Cannot cast " << ob->GetClassName() << " object to vtkPairwiseExtractHistogram2D.  "
           << "This probably means the class specifies the incorrect superclass in vtkTypeMacro.";
    resultStream.Reset();
    resultStream << vtkClientServerStream::Error
                 << vtkmsg.str() << 0 << vtkClientServerStream::End;
    return 0;
    }
  (void)arlu;
  if (!strcmp("New",method) && msg.GetNumberOfArguments(0) == 2)
    {
    vtkPairwiseExtractHistogram2D  *temp20;
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
    vtkPairwiseExtractHistogram2D  *temp20;
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
    vtkPairwiseExtractHistogram2D  *temp20;
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
  if (!strcmp("SetCustomColumnRangeIndex",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    if(msg.GetArgument(0, 2, &temp0))
      {
      op->SetCustomColumnRangeIndex(temp0);
      return 1;
      }
    }
  if (!strcmp("SetCustomColumnRangeByIndex",method) && msg.GetNumberOfArguments(0) == 4)
    {
    double   temp0;
    double   temp1;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1))
      {
      op->SetCustomColumnRangeByIndex(temp0,temp1);
      return 1;
      }
    }
  if (!strcmp("SetCustomColumnRange",method) && msg.GetNumberOfArguments(0) == 5)
    {
    int      temp0;
    double   temp1;
    double   temp2;
    if(msg.GetArgument(0, 2, &temp0) &&
      msg.GetArgument(0, 3, &temp1) &&
      msg.GetArgument(0, 4, &temp2))
      {
      op->SetCustomColumnRange(temp0,temp1,temp2);
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
  if (!strcmp("GetMaximumBinCount",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    double   temp20;
    if(msg.GetArgument(0, 2, &temp0))
      {
      temp20 = (op)->GetMaximumBinCount(temp0);
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
  if (!strcmp("GetOutputHistogramImage",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    vtkImageData  *temp20;
    if(msg.GetArgument(0, 2, &temp0))
      {
      temp20 = (op)->GetOutputHistogramImage(temp0);
      resultStream.Reset();
      resultStream << vtkClientServerStream::Reply << (vtkObjectBase *)temp20 << vtkClientServerStream::End;
      return 1;
      }
    }
  if (!strcmp("GetHistogramFilter",method) && msg.GetNumberOfArguments(0) == 3)
    {
    int      temp0;
    vtkExtractHistogram2D  *temp20;
    if(msg.GetArgument(0, 2, &temp0))
      {
      temp20 = (op)->GetHistogramFilter(temp0);
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
  vtkmsg << "Object type: vtkPairwiseExtractHistogram2D, could not find requested method: \""
         << method << "\"\nor the method was called with incorrect arguments.\n";
  resultStream.Reset();
  resultStream << vtkClientServerStream::Error
               << vtkmsg.str() << vtkClientServerStream::End;
  vtkmsg.rdbuf()->freeze(0);
  return 0;
}


//-------------------------------------------------------------------------auto
void VTK_EXPORT vtkPairwiseExtractHistogram2D_Init(vtkClientServerInterpreter* csi)
{
  static vtkClientServerInterpreter* last = NULL;
  if(last != csi)
    {
    last = csi;
    csi->AddNewInstanceFunction("vtkPairwiseExtractHistogram2D", vtkPairwiseExtractHistogram2DClientServerNewCommand);
    csi->AddCommandFunction("vtkPairwiseExtractHistogram2D", vtkPairwiseExtractHistogram2DCommand);
    }
}
