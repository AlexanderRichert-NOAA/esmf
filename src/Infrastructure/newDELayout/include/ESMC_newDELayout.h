// $Id: ESMC_newDELayout.h,v 1.2 2004/03/03 19:45:53 theurich Exp $
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

#ifndef ESMC_newDELayout_H
#define ESMC_newDELayout_H

//-------------------------------------------------------------------------
//BOP
// !CLASS: ESMC_newDELayout - DELayout
//
// !DESCRIPTION:
//
// The code in this file defines the C++ {\tt newDELayout} members and method
// signatures (prototypes).  The companion file {\tt ESMC\_newDELayout.C}
// contains the full code (bodies) for the {\tt newDELayout} methods.
//
///EOP
//-------------------------------------------------------------------------

#include <ESMC_Base.h>  
#include <ESMC_VM.h>  

// normal connection weight
const int ESMF_CWGHT_NORMAL = 50;


class ESMC_newDELayout;


// DE type used internally in the ESMC_newDELayout class
typedef struct{
  int deid;         // DE's external id number (in case not base zero)
  int petid;        // Id of the PET associated with this DE
  int nconnect;     // number of connections from this DE
  int *connect_de;  // connected DEs 
  int *connect_w;   // connection weight
  int *coord;       // coordinates of this DE in the layout
}de_type;
  

// class definition
class ESMC_newDELayout : public ESMC_Base {    // inherits from ESMC_Base class
  private:
    int ndes;       // number of DEs
    de_type *des;   // list that holds all of this layout's DE info
    int nmydes;     // number of DEs associated with instantiating PET
    int *mydes;     // list that holds all of the des indices for this instance
    int ndim;       // dimensionality of this layout
    ESMC_Logical plugged; // plugged/unplugged state of the layout
  public:
    // Construct and Destruct
    int ESMC_newDELayoutConstruct1D(ESMC_VM &vm, int nDEs, int *DEtoPET,  
      int len, ESMC_Logical cyclic);
    int ESMC_newDELayoutConstructND(ESMC_VM &vm, int *nDEs, int nndim, 
      int *DEtoPET, int len, ESMC_Logical cyclic);
    int ESMC_newDELayoutDestruct(void);
    // Unplug and Plug
    int ESMC_newDELayoutUnplug(void);
    int ESMC_newDELayoutPlug(ESMC_VM &vm);
    // Get info
    int ESMC_newDELayoutGet(int *nDEs, int *ndim, int *nmyDEs, int *myDEs, 
      int len);
    int ESMC_newDELayoutGetDE(int DEid, int *DEcoord, int len_coord, 
      int *DEcde, int len_cde, int *DEcw, int len_cw, int *nDEc);
    int ESMC_newDELayoutMyDE(int DE, ESMC_Logical *value);
    int ESMC_newDELayoutPlugged(ESMC_Logical *value);
    // IO
    int ESMC_newDELayoutPrint(void);
    // Communication
    int ESMC_newDELayoutCopy(ESMC_VM &vm, void **srcdata, void **destdata, 
      int len, int srcDE, int destDE);
    int ESMC_newDELayoutScatter(ESMC_VM &vm, void **srcdata, void **destdata, 
      int len, int rootDE);
    int ESMC_newDELayoutGather(ESMC_VM &vm, void **srcdata, void **destdata, 
      int len, int rootDE);
    int ESMC_newDELayoutAllReduce(ESMC_VM &vm, int *array, int *result, int len,
      ESMC_newOp op);
  private:
    int ESMC_newDELayout::ESMC_newDELayoutFindDEtoPET(int npets);
    int ESMC_newDELayout::ESMC_newDELayoutFillLocal(int mypet);        
};  // end class ESMC_newDELayout


// external methods:  

ESMC_newDELayout *ESMC_newDELayoutCreate(ESMC_VM &vm, int *nDEs, int ndim, 
  int *DEtoPET, int len, ESMC_Logical *cyclic, int *rc);

int ESMC_newDELayoutDestroy(ESMC_newDELayout *layout);
  
void **ESMC_newDELayoutDataCreate(int n, int *rc);
int ESMC_newDELayoutDataAdd(void **ptr, void *a, int index);
int ESMC_newDELayoutDataDestroy(void **ptr);

#endif  // ESMC_newDELayout_H
