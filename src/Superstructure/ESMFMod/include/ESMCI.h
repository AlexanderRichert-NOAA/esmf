// $Id: ESMCI.h,v 1.19 2008/06/26 02:10:15 rosalind Exp $
//
// Earth System Modeling Framework
// Copyright 2002-2008, University Corporation for Atmospheric Research,
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics
// Laboratory, University of Michigan, National Centers for Environmental
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory,
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.
//

// main include file which includes all others

// these lines prevent this file from being read more than once if it
// ends up being included multiple times

#ifndef ESMCI_H
#define ESMCI_H


// common macros and constants, #defines
#include "ESMC_Start.h"

// attribute class, base class, I/O, and error
#include "ESMC_Attribute.h"
#include "ESMC_Base.h"
#include "ESMC_IOSpec.h"
#include "ESMC_LogErr.h"

// optional arguments in ESMC interfaces
#include "ESMCI_Arg.h"

// time manager
#include "ESMC_Fraction.h"
#include "ESMCI_BaseTime.h"
#include "ESMCI_Calendar.h"
#include "ESMCI_TimeInterval.h"
#include "ESMCI_Time.h"
#include "ESMCI_Alarm.h"
#include "ESMCI_Clock.h"

// local array, datamap
#include "ESMCI_ArraySpec.h"
#include "ESMC_LocalArray.h"
#include "ESMC_InternArrayDataMap.h"

// vm and layout
#include "ESMC_VMKernel.h"
#include "ESMC_VM.h"

// array, igrid, field, bundle, comms
#include "ESMC_InternArray.h"
#include "ESMC_Grid.h"
#include "ESMC_FieldBundle.h"

// config
#include "ESMCI_Config.h"

// components and related items
#include "ESMC_State.h"
#include "ESMC_FTable.h"
#include "ESMC_Comp.h"
#include "ESMC_GridComp.h"
#include "ESMC_CplComp.h"

// framework-wide initialization and finalization
#include "ESMCI_Init.h"


#endif  // ESMCI_H

