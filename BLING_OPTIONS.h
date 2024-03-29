C $Header: /u/gcmpack/MITgcm_contrib/verification_other/global_oce_biogeo_bling/code/BLING_OPTIONS.h,v 1.5 2016/11/16 18:23:41 mmazloff Exp $
C $Name:  $

#ifndef BLING_OPTIONS_H
#define BLING_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_BLING
C     Package-specific Options & Macros go here

c Active tracer for total phytoplankton biomass
#undef ADVECT_PHYTO

c Prevents negative values in nutrient fields
#define BLING_NO_NEG

c Assume that phytoplankton in the mixed layer experience
c the average light over the mixed layer
c (as in original BLING model)
#define ML_MEAN_LIGHT

c Assume that phytoplankton are homogenized in the mixed layer
#define ML_MEAN_PHYTO

c Sub grid scale sediments
#undef  USE_SGS_SED

c Determine PAR from shortwave radiation from EXF package
#define USE_EXFQSW

c Use local atmospheric pressure from EXF package for fugacity factor
#undef USE_EXF_ATMPRES

c Read atmospheric pCO2 values from EXF package
#define USE_EXFCO2

c For exf undefined cannot use exf fields
#ifndef ALLOW_EXF
#undef USE_EXFCO2
#undef USE_EXF_ATMPRES
c  this one ok. In FFIELDS.h. #undef USE_EXFQSW
#endif

c  apply remineralization from diel vertical migration
#define USE_BLING_DVM
c In the DVM routine, assume fixed mixed layer depth
c (so no need to calc MLD in bling_production)
#undef FIXED_MLD_DVM

c Simplify some parts of the code that are problematic
c when using the adjoint
#undef BLING_ADJOINT_SAFE

c For adjoint safe, use constant MLD in bling_dvm
#ifdef BLING_ADJOINT_SAFE
#define FIXED_MLD_DVM
#endif

#endif /* ALLOW_BLING */
#endif /* BLING_OPTIONS_H */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
