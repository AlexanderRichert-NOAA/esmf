#if 0
! $Id: ESMF_TypeKindTemplate.h,v 1.1 2006/03/28 21:51:15 theurich Exp $
!
! Earth System Modeling Framework
! Copyright 2002-2003, University Corporation for Atmospheric Research,
! Massachusetts Institute of Technology, Geophysical Fluid Dynamics
! Laboratory, University of Michigan, National Centers for Environmental
! Prediction, Los Alamos National Laboratory, Argonne National Laboratory,
! NASA Goddard Space Flight Center.
! Licensed under the GPL.
!
!==============================================================================
!
#endif
#if 0
!------------------------------------------------------------------------------
! Macros for any functions which must be overloaded T/K (type/kind).
!
! Currently defined types/kinds integer (kind *1,2,4,8), real (kind *4,8)
!
! The structure of this file and these macros are compatible with the gcc
! preprocessor - they assume the use of ## as a paste operator, require that
! no additional spaces be added (e.g. no pre-tokenization as done by some
! preprocessors which assume C syntax), assume an option exists to suppress
! C-specific syntax directives such as #line or #pragma, and that an option
! exists to produce output on stdout and not into a file.  The output of
! the preprocessor phase is a valid .F90 file ready to be compiled by the
! standard fortran compiler.  (gcc is *not* used for compilation.)
!
! The macros are intended to be written with @\ at the end of each line of
! a multiline macro, and the output piped thru 'tr' to translate each
! @ into <cr> to produce multiple lines of fortran code from a single
! macro invocation.   If any preprocessor directives are to be left in the
! output file (e.g. #include <>), the source should use ^directive (e.g.
! ^include <header.h> ) again using 'tr' to substitute # for ^ after
! preprocessing is completed.  
!------------------------------------------------------------------------------
#endif

#if 0
!------------------------------------------------------------------------------
! Expand a string into each of the T/K procedure interface blocks.
! Expected use:
!
! interface fred
!  InterfaceMacro(fred)
!  module procedure other_explicit_non_TKR_interfaces_to_overload
! end interface
!
!------------------------------------------------------------------------------
#endif

#define TypeKindTemplateInterfaceMacro(funcname) \
!------------------------------------------------------------------------------ @\
! <This section created by macro - do not edit directly> @\
    module procedure funcname##I1 @\
    module procedure funcname##I2 @\
    module procedure funcname##I4 @\
    module procedure funcname##I8 @\
    module procedure funcname##R4 @\
    module procedure funcname##R8 @\
! < end macro - do not edit directly >  @\
!------------------------------------------------------------------------------ @\

#if 0
!------------------------------------------------------------------------------
! Expand a string into each of the T/K procedures.  Assumes one macro
! which contains only the general protex documentation, and the rest do NOT
! contain protex.  Expected use:
!
!  DeclarationMacro(fred)
!
! where the following other macros are defined elsewhere by the user:
!  #define fredDoc() ...
! which contains generic protex documentation only, no code, plus:
!  #define fredMacro(typename, typekind) ...
! which contains the actual code for the function, with no protex documentation.
!------------------------------------------------------------------------------
#endif

#define TypeKindTemplateDeclarationMacro(funcname) \
!------------------------------------------------------------------------------ @\
! <This section created by macro - do not edit directly> @\
 @\
!! < start of macros which become actual subroutine bodies after expansion > @\
 @\
funcname##Doc() @\
funcname##Macro(integer, I1) @\
funcname##Macro(integer, I2) @\
funcname##Macro(integer, I4) @\
funcname##Macro(integer, I8) @\
funcname##Macro(real, R4) @\
funcname##Macro(real, R8) @\
 @\
! < end macro - do not edit directly >  @\
!------------------------------------------------------------------------------ @\

