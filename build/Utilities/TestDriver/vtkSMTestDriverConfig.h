/*=========================================================================

  Program:   ParaView
  Module:    vtkSMTestDriverConfig.h.in

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#define VTK_MPIRUN_EXE "C:/Program Files/Microsoft MPI/Bin/mpiexec.exe"
/* #undef VTK_MPI_PRENUMPROC_FLAGS */
#define VTK_MPI_NUMPROC_FLAG "-np"
/* #undef VTK_MPI_PREFLAGS */
/* #undef VTK_MPI_POSTFLAGS */
/* #undef VTK_MPI_SERVER_PREFLAGS */
/* #undef VTK_MPI_SERVER_POSTFLAGS */
/* #undef VTK_MPI_SERVER_TD_PREFLAGS */
/* #undef VTK_MPI_SERVER_TD_POSTFLAGS */
#define VTK_MPI_MAX_NUMPROCS 2
#define PARAVIEW_USE_MPI
/* #undef PV_TEST_INIT_COMMAND */
/* #undef PV_TEST_CLEAN_COMMAND */

// host name for the client used when running reverse connect test.
#define PV_TEST_CLIENT "localhost"

// ssh command to connect to remote machine, usually ssh -l kitware dash8
/* #undef PV_SSH_FLAGS */

// shell script to execute server, should contain proper port...
// This line won't be split into smaller arguments
/* #undef PV_SETUP_SCRIPT */

// if defined we use random port numbers for testing (needed for parallel
// tests).
#define PV_TEST_USE_RANDOM_PORTS
