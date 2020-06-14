/* { dg-require-effective-target arm_v8_1m_mve_ok } */
/* { dg-add-options arm_v8_1m_mve } */
/* { dg-additional-options "-O2" } */

#include "arm_mve.h"

int32x4_t
foo (int32x4_t a, int32_t b, mve_pred16_t p)
{
  return vaddq_x_n_s32 (a, b, p);
}

/* { dg-final { scan-assembler "vpst" } } */
/* { dg-final { scan-assembler "vaddt.i32"  }  } */

int32x4_t
foo1 (int32x4_t a, int32_t b, mve_pred16_t p)
{
  return vaddq_x (a, b, p);
}

/* { dg-final { scan-assembler "vpst" } } */
/* { dg-final { scan-assembler "vaddt.i32"  }  } */