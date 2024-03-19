/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FFT1.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 05-Dec-2021 23:57:59
 */

#ifndef FFT1_H
#define FFT1_H

/* Include Files */
#include "FFT1_types.h"
#include "rtwtypes.h"
#include "omp.h"
#include <stddef.h>
#include <stdlib.h>

/* Variable Declarations */
extern omp_nest_lock_t FFT1_nestLockGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void FFT1(emxArray_creal_T *a, emxArray_creal_T *out,
                 emxArray_real_T *wout);

extern void FFT1_initialize(void);

extern void FFT1_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for FFT1.h
 *
 * [EOF]
 */
