/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_FFT1_api.c
 *
 * Code generation for function '_coder_FFT1_api'
 *
 */

/* Include files */
#include "_coder_FFT1_api.h"
#include "FFT1.h"
#include "FFT1_data.h"
#include "FFT1_emxutil.h"
#include "FFT1_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo q_emlrtRTEI = {
    1,                 /* lineNo */
    1,                 /* colNo */
    "_coder_FFT1_api", /* fName */
    ""                 /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *a,
                             const char_T *identifier, emxArray_creal_T *y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_creal_T *u);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_creal_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_creal_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  creal_T *ret_data;
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            true, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_creal_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 8, true);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *a,
                             const char_T *identifier, emxArray_creal_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a), &thisId, y);
  emlrtDestroyArray(&a);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_creal_T *u)
{
  const mxArray *m;
  const mxArray *y;
  const creal_T *u_data;
  int32_T iv[2];
  u_data = u->data;
  y = NULL;
  iv[0] = 1;
  iv[1] = u->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtCTX)sp, m, (void *)&u_data[0], 8);
  emlrtAssign(&y, m);
  return y;
}

void FFT1_api(const mxArray *prhs, int32_T nlhs, const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_creal_T *a;
  emxArray_creal_T *out;
  emxArray_real_T *wout;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_creal_T(&st, &a, &q_emlrtRTEI);
  emxInit_creal_T(&st, &out, &q_emlrtRTEI);
  emxInit_real_T(&st, &wout, &q_emlrtRTEI);
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs), "a", a);
  /* Invoke the target function */
  FFT1(&st, a, out, wout);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, out);
  emxFree_creal_T(&st, &out);
  emxFree_creal_T(&st, &a);
  if (nlhs > 1) {
    wout->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(wout);
  }
  emxFree_real_T(&st, &wout);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_FFT1_api.c) */
