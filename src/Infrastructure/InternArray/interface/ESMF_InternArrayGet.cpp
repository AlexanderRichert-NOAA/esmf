! $Id: ESMF_InternArrayGet.cpp,v 1.3 2006/11/16 05:21:04 cdeluca Exp $
!
! Earth System Modeling Framework
! Copyright 2002-2008, University Corporation for Atmospheric Research, 
! Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
! Laboratory, University of Michigan, National Centers for Environmental 
! Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
! NASA Goddard Space Flight Center.
! Licensed under the University of Illinois-NCSA License.
!
!==============================================================================
^define ESMF_FILENAME "ESMF_InternArrayGet.F90"
!
!     ESMF Array module
      module ESMF_InternArrayGetMod
!
!==============================================================================
!
! This file contains the Array class methods which are automatically
!  generated from macros to handle the type/kind/rank overloading.
!  See ESMF_ArrayBase.F90 for non-macroized entry points.
! class methods.
!
!------------------------------------------------------------------------------
! INCLUDES
! < ignore blank lines below.  they are created by the files which
!   define various macros. >
#include "ESMF_StdCppMacros.h"
#include "ESMF_InternArrayGetMacros.h"
^include "ESMF.h"
!------------------------------------------------------------------------------
! !USES:
      use ESMF_UtilTypesMod
      use ESMF_BaseMod
      use ESMF_LogErrMod
      use ESMF_LocalArrayMod
      use ESMF_InternArrayMod
      use ESMF_InternArrayCreateMod
      implicit none

!------------------------------------------------------------------------------
! !PRIVATE TYPES:
      private


!------------------------------------------------------------------------------
!     ! Internal wrapper structures for passing f90 pointers to C++ and
!     ! guaranteeing they are passed by reference on all compilers and all
!     ! platforms.  These are never seen outside this module.
!
      ! < these expand into defined type declarations >
AllTypesMacro(ArrayType)

!------------------------------------------------------------------------------
! !PUBLIC MEMBER FUNCTIONS:

      public ESMF_InternArraySetData
      public ESMF_InternArrayGetData

      public operator(.eq.), operator(.ne.)

!------------------------------------------------------------------------------
! The following line turns the CVS identifier string into a printable variable.
      character(*), parameter, private :: version = &
      '$Id: ESMF_InternArrayGet.cpp,v 1.3 2006/11/16 05:21:04 cdeluca Exp $'

!==============================================================================
! 
! INTERFACE BLOCKS
!
!==============================================================================

!------------------------------------------------------------------------------

!BOPI
! !IROUTINE: ESMF_InternArrayGetData -- Get a Fortran pointer to the data contents
!
! !INTERFACE:
     interface ESMF_InternArrayGetData
!
! !PRIVATE MEMBER FUNCTIONS:
!
      ! < declarations of interfaces for each T/K/R >
InterfaceMacro(ArrayGetData)

! !DESCRIPTION: 
! This interface provides a single entry point for the various 
!  types of {\tt ESMF\_InternArrayGetData} functions.   
!  
!EOPI 
end interface

!==============================================================================

      contains

!==============================================================================

!------------------------------------------------------------------------------
!------------------------------------------------------------------------------
!BOPI
! !IROUTINE: ESMF_InternArraySetData
!
! !INTERFACE:
      subroutine ESMF_InternArraySetData(array, databuf, docopy, rc)
!
! !ARGUMENTS:
      type(ESMF_InternArray) :: array 
      real, dimension (:), pointer :: databuf    
      type(ESMF_CopyFlag), intent(in) :: docopy 
      integer, intent(out), optional :: rc     
!
! !DESCRIPTION:
!      Used only with the version of ArrayCreate which creates an empty 
!      Array and allows the Data to be specified later.  Otherwise it is an 
!      error to replace the data contents associated with a Array.  
! 
!  TODO: this needs to be macroized for T/K/R, just like create
!
!EOPI
! !REQUIREMENTS:

!
!       Changed BOP/EOP to BOPI/EOPI until code is added.
! TODO: code goes here
!
        rc = ESMF_FAILURE

        end subroutine ESMF_InternArraySetData

!------------------------------------------------------------------------------
!------------------------------------------------------------------------------

!! < start of macros which become actual function bodies after expansion >
DeclarationMacro(ArrayGetData)

!------------------------------------------------------------------------------
!------------------------------------------------------------------------------


        end module ESMF_InternArrayGetMod

