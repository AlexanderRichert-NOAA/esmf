// $Id: ESMC_Array.h,v 1.45 2006/05/19 02:23:06 theurich Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2003, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the GPL.

// ESMC DELayout include file for C++

// (all lines below between the !BOP and !EOP markers will be included in
//  the automated document processing.)
//-------------------------------------------------------------------------
// these lines prevent this file from being read more than once if it
// ends up being included multiple times

#ifndef ESMC_Array_H
#define ESMC_newArray_H

//-------------------------------------------------------------------------
//BOP
// !CLASS: ESMC_Array - Array
//
// !DESCRIPTION:
//
// The code in this file defines the C++ {\tt Array} members and method
// signatures (prototypes).  The companion file {\tt ESMC\_Array.C}
// contains the full code (bodies) for the {\tt Array} methods.
//
///EOP
//-------------------------------------------------------------------------

#include "ESMF_Pthread.h"

#include "ESMC_Base.h"
#include "ESMC_VM.h"
#include "ESMC_DELayout.h"
#include "ESMC_DistGrid.h"
#include "ESMC_ArraySpec.h"
#include "ESMC_LocalArray.h"
#include "ESMC_RHandle.h"


class ESMC_Array;

// class definition
class ESMC_Array : public ESMC_Base {    // inherits from ESMC_Base class
  private:
    // global information
    ESMC_DataType type;
    ESMC_DataKind kind;
    int rank;
    ESMC_IndexFlag indexflag;
    //todo: the LocalArray pointers should be shared between PETs in the same
    //todo: VAS as to allow shared memory operations. Even the LocalArray
    //todo: pointers for Arrays instances on other VAS' may be good to keep
    //todo: in order to allow one-sided access to their data...
    // for now only keep PET-local LocalArray pointers here
    // PET-local information
    ESMC_LocalArray **larrayList;
    void **larrayBaseAddrList;
    int *exclusiveLBound;
    int *exclusiveUBound;
    int *computationalLBound;
    int *computationalUBound;
    int *totalLBound;
    int *totalUBound;
    int tensorCount;
    int *lbounds;
    int *ubounds;
    int *staggerLoc;
    int *vectorDim;
    int *dimmap;
    int *inverseDimmap;
    int *contiguousFlag;
    // lower level objects
    ESMC_DistGrid *distgrid;
    ESMC_DELayout *delayout;
    // cached values from LocalArray
    // cached values from DistGrid
    int dimCount;
    // cached values from DELayout
    int deCount;
    int localDeCount;
    int *localDeList;
    
  public:
    // Construct and Destruct
    int ESMC_ArrayConstruct(ESMC_DataType type, ESMC_DataKind kind, int rank,
      ESMC_LocalArray **larrayList,
      ESMC_DistGrid *distgrid, int *exclusiveLBound, int *exclusiveUBound, 
      int *computationalLBound, int *computationalUBound, 
      int *totalLBound, int *totalUBound, int tensorCount,
      int *lboundsArray, int *uboundsArray, int *staggerLoc, int *vectorDim,
      int *dimmapArray, int *inverseDimmapArray, ESMC_IndexFlag indexflagArg);
    int ESMC_ArrayDestruct(void);
    // Get, Set
    int ESMC_ArraySet(char *name){
      return ESMC_BaseSetName(name, "Array");
    }
    char *ESMC_ArrayGet(void){
      return ESMC_BaseGetName();
    }
    int ESMC_ArrayGet(ESMC_DataType *type, ESMC_DataKind *kind, int *rank,
      ESMC_LocalArray **localArrayList, int localArrayListCount,
      ESMC_DistGrid **distgridArg, ESMC_DELayout **delayoutArg,
      ESMC_IndexFlag *indexflag, ESMC_InterfaceInt *dimmapArg,
      ESMC_InterfaceInt *inverseDimmapArg,
      ESMC_InterfaceInt *exclusiveLBoundArg,
      ESMC_InterfaceInt *exclusiveUBoundArg,
      ESMC_InterfaceInt *computationalLBoundArg,
      ESMC_InterfaceInt *computationalUBoundArg,
      ESMC_InterfaceInt *totalLBoundArg, ESMC_InterfaceInt *totalUBoundArg,
      ESMC_InterfaceInt *computationalLWidthArg,
      ESMC_InterfaceInt *computationalUWidthArg,
      ESMC_InterfaceInt *totalLWidthArg, ESMC_InterfaceInt *totalUWidthArg);
    int ESMC_ArrayGetLinearIndexExclusive(int localDe, int *index);
    // IO and validation
    int ESMC_ArrayPrint(void);
    // serialize/deserialize
    int ESMC_ArraySerialize(char *buffer, int *length, int *offset) const;
    int ESMC_ArrayDeserialize(char *buffer, int *offset);
    
    // comm methods
    int ESMC_ArrayScatter(void *farray, ESMC_DataType type, ESMC_DataKind kind,
      int rank, int *counts, int *patch, int rootPet, ESMC_VM *vm);
    
    // external friend functions
    friend int ESMC_ArraySparseMatMulStore(ESMC_Array *srcArray, 
      ESMC_Array *dstArray, double *factorList, int factorListCount,
      ESMC_InterfaceInt *factorIndexList, int rootPet, 
      ESMC_RouteHandle **routehandle);
    friend int ESMC_ArraySparseMatMul(ESMC_Array *srcArray, 
      ESMC_Array *dstArray, ESMC_RouteHandle **routehandle);
    
};  // end class ESMC_Array


// external methods:  

ESMC_Array *ESMC_ArrayCreate(ESMC_ArraySpec *arrayspec, ESMC_DistGrid *distgrid,
  ESMC_InterfaceInt *dimmap, ESMC_InterfaceInt *computationalLWidthArg,
  ESMC_InterfaceInt *computationalUWidthArg, ESMC_InterfaceInt *totalLWidthArg,
  ESMC_InterfaceInt *totalUWidthArg, ESMC_IndexFlag *indexflag, int *staggerLoc,
  int *vectorDim, ESMC_InterfaceInt *lboundsArg, ESMC_InterfaceInt *uboundsArg,
  int *rc);

ESMC_Array *ESMC_ArrayCreate(ESMC_LocalArray **larrayList, int larrayCount, 
  ESMC_DistGrid *distgrid, ESMC_InterfaceInt *dimmap,
  ESMC_InterfaceInt *computationalLWidthArg,
  ESMC_InterfaceInt *computationalUWidthArg, ESMC_InterfaceInt *totalLWidthArg,
  ESMC_InterfaceInt *totalUWidthArg, ESMC_IndexFlag *indexflag, int *staggerLoc,
  int *vectorDim, ESMC_InterfaceInt *lboundsArg, ESMC_InterfaceInt *uboundsArg,
  int *rc);

int ESMC_ArrayDestroy(ESMC_Array **array);

int ESMC_ArraySparseMatMulRelease(ESMC_RouteHandle *routehandle);


//-------------------------------------------------------------------------
// The following code is for a first newArray prototype which I used
// to check out some communication ideas: DE-nonblocking paradigm!
//-------------------------------------------------------------------------

class ESMC_newArray;

typedef struct{
  int commhandleCount;
  vmk_commhandle **vmk_commh;
  int pthidCount;
  pthread_t pthid[10];
  void *buffer;
}ESMC_newArrayCommHandle;

typedef struct{
  ESMC_newArray *array;     // pointer to calling ESMC_newArray object
  ESMC_VM *vm;              // pointer to current VM
  int de;                   // DE for DE-based non-blocking operation
  int rootPET;              // root
  void *result;             // result memory location
  ESMC_DataKind dtk;        // data type kind
  ESMC_Operation op;        // operation flag
}ESMC_newArrayThreadArg;


// class definition
class ESMC_newArray : public ESMC_Base {    // inherits from ESMC_Base class
  private:
    int rank;                 // rank of newArray
    ESMC_DataType type;       // type of newArray (for F90)
    ESMC_DataKind kind;       // kind of newArray (for F90)
    int **globalDataLBound;   // dataBox for this DE [de][dim]
    int **globalDataUBound;   // dataBox for this DE [de][dim]
    int **localFullLBound;    // fullBox (data + halo) for this DE [de][dim]
    int **localFullUBound;    // fullBox (data + halo) for this DE [de][dim]
    int **globalFullLBound;   // fullBox (data + halo) for this DE [de][dim]
    int **globalFullUBound;   // fullBox (data + halo) for this DE [de][dim]
    int **dataOffset;         // offset dataBox vs. fullBox for DE [de][dim]
    ESMC_DELayout *delayout;        // DELayout on which newArray is defined
    ESMC_LocalArray **localArrays;  // array of LocalArray pointers [localDe]
    ESMC_newArrayCommHandle *commhArray;  // array of commhandles [localDe]
    ESMC_newArrayThreadArg *thargArray;   // array of thread args [localDe]
    ESMC_newArrayThreadArg thargRoot;     // root's thread args
    
    // cached VM information
    int localVAS;             // VAS in which localPET operates
                      // don't cache localPET because that might change
    // cached DELayout information
    int deCount;              // total number of DEs
    int localDeCount;         // number of DEs that map onto localVAS
    int *localDeList;         // list of local DEs
    int *deVASList;           // list of VASs for all DEs
    
  public:
    // Construct and Destruct
    int ESMC_newArrayConstruct(  
      ESMC_LocalArray *larray,  // pointer to ESMC_LocalArray object
      int *haloWidth,           // halo width
      ESMC_DELayout *delayout,  // DELayout
      int rootPET,              // root
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayDestruct(void);

    // Get info
    int ESMC_newArrayGet(int *rank, ESMC_DELayout **delayout, 
      ESMC_LocalArray **localArrays, int len_localArrays,
      int *globalFullLBound, int *len_globalFullLBound,
      int *globalFullUBound, int *len_globalFullUBound,
      int *globalDataLBound, int *len_globalDataLBound,
      int *globalDataUBound, int *len_globalDataUBound,
      int *localDataLBound, int *len_localDataLBound,
      int *localDataUBound, int *len_localDataUBound);
   
    // IO and validation
    int ESMC_newArrayPrint(void);
    
    // Communication
    int ESMC_newArrayScatter(
      ESMC_LocalArray *larray,  // pointer to ESMC_LocalArray object
      int rootPET,              // root
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things
    
    int ESMC_newArrayScatter(
      ESMC_LocalArray *larray,  // pointer to ESMC_LocalArray object
      int rootPET,              // root
      ESMC_newArrayCommHandle *commh, // commu handle for non-blocking mode
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayScatter(
      ESMC_LocalArray *larray,  // pointer to ESMC_LocalArray object
      int rootPET,              // root
      int de,                   // DE for DE-based non-blocking scatter
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayScalarReduce(
      void *result,             // result value (scalar)
      ESMC_DataKind dtk,        // data type kind
      ESMC_Operation op,        // reduce operation
      int rootPET,              // root
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayScalarReduce(
      void *result,             // result value (scalar)
      ESMC_DataKind dtk,        // data type kind
      ESMC_Operation op,        // reduce operation
      int rootPET,              // root
      ESMC_newArrayCommHandle *commh, // commu handle for non-blocking mode
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayScalarReduce(
      void *result,             // result value (scalar)
      ESMC_DataKind dtk,        // data type kind
      ESMC_Operation op,        // reduce operation
      int rootPET,              // root
      int de,                   // DE for DE-based non-blocking reduce
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayWait(
      int rootPET,              // root
      ESMC_newArrayCommHandle *commh, // commu handle specifying non-block op.
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things

    int ESMC_newArrayWait(
      int de,                   // DE for which to wait
      ESMC_VM *vm=NULL);        // optional VM argument to speed up things
    
    // friend functions that provide thread support for non-blocking comms
    friend void *ESMC_newArrayScatterThread(void *);
    friend void *ESMC_newArrayScalarReduceThread(void *);

};  // end class ESMC_newArray

// external methods:  

ESMC_newArray *ESMC_newArrayCreate(ESMC_LocalArray *larray, int *haloWidth, 
  int deCount, int rootPET, int *rc);

int ESMC_newArrayDestroy(ESMC_newArray **array);



#endif  // ESMC_Array_H

