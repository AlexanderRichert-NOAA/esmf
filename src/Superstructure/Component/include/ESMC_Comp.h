// $Id: ESMC_Comp.h,v 1.2 2003/02/25 18:26:46 nscollins Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2003, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the GPL.

// ESMF Component C++ declaration include file
//
// (all lines below between the !BOP and !EOP markers will be included in 
//  the automated document processing.)
//-----------------------------------------------------------------------------
//
 // these lines prevent this file from being read more than once if it
 // ends up being included multiple times

#ifndef ESMC_Comp_H
#define ESMC_Comp_H

//-----------------------------------------------------------------------------

#include "ESMC_Layout.h"
#include "ESMC_State.h"

 // Put any constants or macros which apply to the whole component in this file.
 // Anything public or esmf-wide should be up higher at the top level
 // include files.

enum ESMC_CompType { ESMF_APPCOMP=1, ESMF_GRIDCOMP, ESMF_CPLCOMP, 
                     ESMF_COMPTYPE_UNKNOWN };
enum ESMC_ModelType { ESMF_ATM=1, ESMF_LAND, ESMF_OCEAN, ESMF_SEAICE, 
                      ESMF_RIVER, ESMF_MODEL_UNKNOWN };

//-----------------------------------------------------------------------------
//BOP
// !CLASS:  ESMC_Comp - one line general statement about this class
//
// !DESCRIPTION:
//
// The code in this file defines the C++ Component members and declares method 
// signatures (prototypes).  The companion file ESMC_Comp.C contains
// the definitions (full code bodies) for the Component methods.
//
// < insert a paragraph or two explaining what you'll find in this file >
//
//-----------------------------------------------------------------------------
// 
// !USES:
#include "ESMC_Base.h"  // all classes inherit from the ESMC Base class.
#include "ESMC_State.h"

#include "ESMC_FTable.h"  // function & data pointer table 

// !PUBLIC TYPES:
 class ESMC_CompConfig;
 class ESMC_Comp;

// !PRIVATE TYPES:

 // class configuration type
 class ESMC_CompConfig {
   private:
 //   < insert resource items here >
 };

 // class declaration type
 class ESMC_Comp : public ESMC_Base {    // inherits from ESMC_Base class

   private:
    void *fortranclass;
    ESMC_FTable localtable;   // table of functions & data ptrs
    
// !PUBLIC MEMBER FUNCTIONS:
//
  public:
    int ESMC_CompInit(void);
    int ESMC_CompRun(int timesteps);
    int ESMC_CompFinal(void);

 // optional configuration methods
    int ESMC_CompGetConfig(ESMC_CompConfig *config) const;
    int ESMC_CompSetConfig(const ESMC_CompConfig *config);

 // accessor methods for class members
    //int ESMC_CompGet<Value>(<value type> *value) const;
    //int ESMC_CompSet<Value>(<value type>  value);
    
 // misc routines
    int ESMC_CompTableCreate(void *table);

 // required methods inherited and overridden from the ESMC_Base class
    int ESMC_CompValidate(const char *options) const;
    int ESMC_CompPrint(const char *options) const;

 // secondary construct/destruct routines
    int ESMC_CompConstruct(char *name, ESMC_Layout *layout,
                                      enum ESMC_CompType ctype,
                                      enum ESMC_ModelType mtype,
                                      char *filepath);
    int ESMC_CompDestruct(void);

 // native C++ constructors/destructors
	ESMC_Comp(void);
	~ESMC_Comp(void);
  
 // < declare the rest of the public interface methods here >
  
// !PRIVATE MEMBER FUNCTIONS:
//
  private: 
//
 // < declare private interface methods here >
//
//EOP
//-----------------------------------------------------------------------------

 };   // end class ESMC_Comp

// Create and Destroy are declared as class helper functions (not methods)
// since they create and destroy an ESMC_Comp object itself. E.g. if Create
// were a method, the ESMC_Comp object on whose behalf it was being invoked
// would need to already exist!  These functions are supersets of C++ new
// and delete; they perform allocation/deallocation specialized to
// an ESMC_Comp object.

 ESMC_Comp *ESMC_CompCreate(char *name, ESMC_Layout *layout,
                                      enum ESMC_CompType ctype,
                                      enum ESMC_ModelType mtype,
                                      char *filepath, int *rc);
 int ESMC_CompDestroy(ESMC_Comp *comp);


// prototypes for fortran interface routines
extern "C" {
   void FTN(f_esmf_compcreate)(ESMC_Comp **compp, char *name, int *rc);
   void FTN(f_esmf_compdestroy)(ESMC_Comp **compp, char *name, int *rc);
   void FTN(f_esmf_compinit)(ESMC_Comp **compp, char *name, void *func, int *rc);
   void FTN(f_esmf_comprun)(ESMC_Comp **compp, char *name, int *rc);
   void FTN(f_esmf_compfinalize)(ESMC_Comp **compp, char *name, int *rc);
};

 #endif  // ESMC_Comp_H
