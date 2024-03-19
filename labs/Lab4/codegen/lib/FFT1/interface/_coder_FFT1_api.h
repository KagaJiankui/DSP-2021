/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_FFT1_api.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 05-Dec-2021 23:57:59
 */

#ifndef _CODER_FFT1_API_H
#define _CODER_FFT1_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void FFT1(emxArray_creal_T *a, emxArray_creal_T *out, emxArray_real_T *wout);

void FFT1_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[2]);

void FFT1_atexit(void);

void FFT1_initialize(void);

void FFT1_terminate(void);

void FFT1_xil_shutdown(void);

void FFT1_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_FFT1_api.h
 *
 * [EOF]
 */
