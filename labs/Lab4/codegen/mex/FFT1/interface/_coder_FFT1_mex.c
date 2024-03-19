/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_FFT1_mex.c
 *
 * Code generation for function '_coder_FFT1_mex'
 *
 */

/* Include files */
#include "_coder_FFT1_mex.h"
#include "FFT1_data.h"
#include "FFT1_initialize.h"
#include "FFT1_terminate.h"
#include "_coder_FFT1_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void FFT1_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                      const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        4, "FFT1");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "FFT1");
  }
  /* Call the function. */
  FFT1_api(prhs[0], nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&FFT1_atexit);
  /* Module initialization. */
  FFT1_initialize();
  /* Dispatch the entry-point. */
  FFT1_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  FFT1_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_FFT1_mex.c) */
