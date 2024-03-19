/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFT1.c
 *
 * Code generation for function 'FFT1'
 *
 */

/* Include files */
#include "FFT1.h"
#include "FFT1_data.h"
#include "FFT1_emxutil.h"
#include "FFT1_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = {
    6,                                      /* lineNo */
    "FFT1",                                 /* fcnName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    10,                                     /* lineNo */
    11,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    2,                                      /* nDims */
    13,                                     /* lineNo */
    12,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,                                      /* nDims */
    14,                                     /* lineNo */
    14,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    -1,                                     /* nDims */
    14,                                     /* lineNo */
    9,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    2,                                      /* nDims */
    15,                                     /* lineNo */
    18,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    -1,                                     /* nDims */
    15,                                     /* lineNo */
    9,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    5,                                               /* lineNo */
    7,                                               /* colNo */
    "Reverse_Rader",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    3,                                       /* lineNo */
    14,                                      /* colNo */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    1                                        /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    3,                                       /* lineNo */
    14,                                      /* colNo */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    4                                        /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    7,                                                /* lineNo */
    13,                                               /* colNo */
    "F",                                              /* aName */
    "Reverse_Rader",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    8,                                                /* lineNo */
    18,                                               /* colNo */
    "F",                                              /* aName */
    "Reverse_Rader",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    8,                                                /* lineNo */
    18,                                               /* colNo */
    "Reverse_Rader",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    8,                                                /* lineNo */
    11,                                               /* colNo */
    "F",                                              /* aName */
    "Reverse_Rader",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    9,                                                /* lineNo */
    11,                                               /* colNo */
    "F",                                              /* aName */
    "Reverse_Rader",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    9,                                                /* lineNo */
    11,                                               /* colNo */
    "Reverse_Rader",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\Reverse_Rader.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    12,                                      /* lineNo */
    14,                                      /* colNo */
    "a",                                     /* aName */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    0                                        /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    12,                                      /* lineNo */
    14,                                      /* colNo */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    1                                        /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    13,                                      /* lineNo */
    14,                                      /* colNo */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    1                                        /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    13,                                      /* lineNo */
    14,                                      /* colNo */
    "a",                                     /* aName */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    14,                                      /* lineNo */
    11,                                      /* colNo */
    "a",                                     /* aName */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    0                                        /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    15,                                      /* lineNo */
    11,                                      /* colNo */
    "a",                                     /* aName */
    "FFT1",                                  /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m", /* pName */
    0                                        /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    3,                                      /* lineNo */
    1,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    49,         /* lineNo */
    20,         /* colNo */
    "linspace", /* fName */
    "D:\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" /* pName
                                                                        */
};

static emlrtRTEInfo e_emlrtRTEI = {
    19,                                     /* lineNo */
    1,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    28,                                                           /* lineNo */
    9,                                                            /* colNo */
    "colon",                                                      /* fName */
    "D:\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    11,                                     /* lineNo */
    9,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    12,                                     /* lineNo */
    9,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    13,                                     /* lineNo */
    14,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    13,                                     /* lineNo */
    23,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    13,                                     /* lineNo */
    9,                                      /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    14,                                     /* lineNo */
    11,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    14,                                     /* lineNo */
    14,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    15,                                     /* lineNo */
    11,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    15,                                     /* lineNo */
    18,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    1,                                      /* lineNo */
    21,                                     /* colNo */
    "FFT1",                                 /* fName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pName */
};

static emlrtRSInfo i_emlrtRSI = {
    15,                                     /* lineNo */
    "FFT1",                                 /* fcnName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    13,                                     /* lineNo */
    "FFT1",                                 /* fcnName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    14,                                     /* lineNo */
    "FFT1",                                 /* fcnName */
    "D:\\电子技术\\DSP\\labs\\Lab4\\FFT1.m" /* pathName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *c2,
                             const emxArray_creal_T *a,
                             const emxArray_uint32_T *r2,
                             const emxArray_creal_T *r3);

static void minus(const emlrtStack *sp, emxArray_creal_T *c1,
                  const emxArray_creal_T *c2);

static void plus(const emlrtStack *sp, emxArray_creal_T *r1,
                 const emxArray_creal_T *c1, const emxArray_creal_T *c2);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *c2,
                             const emxArray_creal_T *a,
                             const emxArray_uint32_T *r2,
                             const emxArray_creal_T *r3)
{
  const creal_T *a_data;
  const creal_T *r;
  creal_T *c2_data;
  real_T b_re_tmp;
  real_T c_re_tmp;
  int32_T i;
  int32_T loop_ub;
  int32_T re_tmp;
  int32_T stride_0_1;
  int32_T stride_1_1;
  const uint32_T *r1;
  r = r3->data;
  r1 = r2->data;
  a_data = a->data;
  i = c2->size[0] * c2->size[1];
  c2->size[0] = 1;
  if (r3->size[1] == 1) {
    c2->size[1] = r2->size[1];
  } else {
    c2->size[1] = r3->size[1];
  }
  emxEnsureCapacity_creal_T(sp, c2, i, &k_emlrtRTEI);
  c2_data = c2->data;
  stride_0_1 = (r2->size[1] != 1);
  stride_1_1 = (r3->size[1] != 1);
  if (r3->size[1] == 1) {
    loop_ub = r2->size[1];
  } else {
    loop_ub = r3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    re_tmp = i * stride_1_1;
    b_re_tmp = r[re_tmp].im;
    c_re_tmp = r[re_tmp].re;
    c2_data[i].re = a_data[(int32_T)r1[i * stride_0_1] - 1].re * c_re_tmp -
                    a_data[(int32_T)r1[i * stride_0_1] - 1].im * b_re_tmp;
    c2_data[i].im = a_data[(int32_T)r1[i * stride_0_1] - 1].re * b_re_tmp +
                    a_data[(int32_T)r1[i * stride_0_1] - 1].im * c_re_tmp;
  }
}

static void minus(const emlrtStack *sp, emxArray_creal_T *c1,
                  const emxArray_creal_T *c2)
{
  emxArray_creal_T *b_c1;
  const creal_T *c2_data;
  creal_T *b_c1_data;
  creal_T *c1_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  c2_data = c2->data;
  c1_data = c1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &b_c1, &o_emlrtRTEI);
  i = b_c1->size[0] * b_c1->size[1];
  b_c1->size[0] = 1;
  if (c2->size[1] == 1) {
    b_c1->size[1] = c1->size[1];
  } else {
    b_c1->size[1] = c2->size[1];
  }
  emxEnsureCapacity_creal_T(sp, b_c1, i, &o_emlrtRTEI);
  b_c1_data = b_c1->data;
  stride_0_1 = (c1->size[1] != 1);
  stride_1_1 = (c2->size[1] != 1);
  if (c2->size[1] == 1) {
    loop_ub = c1->size[1];
  } else {
    loop_ub = c2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    b_c1_data[i].re = c1_data[i * stride_0_1].re - c2_data[i1].re;
    b_c1_data[i].im = c1_data[i * stride_0_1].im - c2_data[i1].im;
  }
  i = c1->size[0] * c1->size[1];
  c1->size[0] = 1;
  c1->size[1] = b_c1->size[1];
  emxEnsureCapacity_creal_T(sp, c1, i, &o_emlrtRTEI);
  c1_data = c1->data;
  loop_ub = b_c1->size[1];
  for (i = 0; i < loop_ub; i++) {
    c1_data[i] = b_c1_data[i];
  }
  emxFree_creal_T(sp, &b_c1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_creal_T *r1,
                 const emxArray_creal_T *c1, const emxArray_creal_T *c2)
{
  const creal_T *c1_data;
  const creal_T *c2_data;
  creal_T *r;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  c2_data = c2->data;
  c1_data = c1->data;
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  if (c2->size[1] == 1) {
    r1->size[1] = c1->size[1];
  } else {
    r1->size[1] = c2->size[1];
  }
  emxEnsureCapacity_creal_T(sp, r1, i, &m_emlrtRTEI);
  r = r1->data;
  stride_0_1 = (c1->size[1] != 1);
  stride_1_1 = (c2->size[1] != 1);
  if (c2->size[1] == 1) {
    loop_ub = c1->size[1];
  } else {
    loop_ub = c2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    r[i].re = c1_data[i * stride_0_1].re + c2_data[i1].re;
    r[i].im = c1_data[i * stride_0_1].im + c2_data[i1].im;
  }
}

void FFT1(const emlrtStack *sp, emxArray_creal_T *a, emxArray_creal_T *out,
          emxArray_real_T *wout)
{
  emlrtStack st;
  emxArray_creal_T *c1;
  emxArray_creal_T *c2;
  emxArray_creal_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *l;
  emxArray_uint32_T *r2;
  creal_T varargout_1;
  creal_T *a_data;
  creal_T *c2_data;
  creal_T *out_data;
  creal_T *r4;
  real_T J;
  real_T LH;
  real_T N;
  real_T S;
  real_T T_im;
  real_T T_re;
  real_T b_tmp;
  real_T d;
  real_T delta1;
  real_T *wout_data;
  int32_T eint;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T *r5;
  uint32_T *r3;
  int8_T i3;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (a->size[1] == 0) {
    delta1 = rtMinusInf;
  } else {
    delta1 = frexp(a->size[1], &eint);
    if (delta1 == 0.5) {
      delta1 = (real_T)eint - 1.0;
    } else if ((eint == 1) && (delta1 < 0.75)) {
      delta1 = muDoubleScalarLog(2.0 * delta1) / 0.69314718055994529;
    } else {
      delta1 = muDoubleScalarLog(delta1) / 0.69314718055994529 + (real_T)eint;
    }
  }
  N = muDoubleScalarPower(2.0, muDoubleScalarCeil(delta1));
  /* 最近二次幂 */
  d = N - (real_T)a->size[1];
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &b_emlrtDCI, (emlrtCTX)sp);
  }
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtCTX)sp);
  }
  eint = (int32_T)d;
  i = a->size[1];
  i1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] += (int32_T)d;
  emxEnsureCapacity_creal_T(sp, a, i1, &c_emlrtRTEI);
  a_data = a->data;
  for (i1 = 0; i1 < eint; i1++) {
    i2 = i1 + i;
    a_data[i2].re = 0.0;
    a_data[i2].im = 0.0;
  }
  i = wout->size[0] * wout->size[1];
  wout->size[0] = 1;
  wout->size[1] = a->size[1];
  emxEnsureCapacity_real_T(sp, wout, i, &d_emlrtRTEI);
  wout_data = wout->data;
  if (a->size[1] >= 1) {
    wout_data[a->size[1] - 1] = 6.2831853071795862;
    if (wout->size[1] >= 2) {
      wout_data[0] = 0.0;
      if (wout->size[1] >= 3) {
        delta1 = 6.2831853071795862 / ((real_T)wout->size[1] - 1.0);
        i = wout->size[1];
        for (k = 0; k <= i - 3; k++) {
          wout_data[k + 1] = ((real_T)k + 1.0) * delta1;
        }
      }
    }
  }
  S = 1.0;
  st.site = &b_emlrtRSI;
  LH = N / 2.0;
  J = LH;
  i = (int32_T)(N - 2.0);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, N - 2.0, mxDOUBLE_CLASS,
                                (int32_T)(N - 2.0), &b_emlrtRTEI, &st);
  for (eint = 0; eint < i; eint++) {
    if ((real_T)eint + 1.0 < J) {
      if (eint + 2 > a->size[1]) {
        emlrtDynamicBoundsCheckR2012b(eint + 2, 1, a->size[1], &emlrtBCI, &st);
      }
      T_re = a_data[eint + 1].re;
      if (eint + 2 > a->size[1]) {
        emlrtDynamicBoundsCheckR2012b(eint + 2, 1, a->size[1], &emlrtBCI, &st);
      }
      T_im = a_data[eint + 1].im;
      if (eint + 2 > a->size[1]) {
        emlrtDynamicBoundsCheckR2012b(eint + 2, 1, a->size[1], &c_emlrtBCI,
                                      &st);
      }
      d = (int32_T)muDoubleScalarFloor(J + 1.0);
      if (J + 1.0 != d) {
        emlrtIntegerCheckR2012b(J + 1.0, &c_emlrtDCI, &st);
      }
      if (((int32_T)(J + 1.0) < 1) || ((int32_T)(J + 1.0) > a->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(J + 1.0), 1, a->size[1],
                                      &b_emlrtBCI, &st);
      }
      a_data[eint + 1].re = a_data[(int32_T)(J + 1.0) - 1].re;
      if (J + 1.0 != d) {
        emlrtIntegerCheckR2012b(J + 1.0, &c_emlrtDCI, &st);
      }
      if (((int32_T)(J + 1.0) < 1) || ((int32_T)(J + 1.0) > a->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(J + 1.0), 1, a->size[1],
                                      &b_emlrtBCI, &st);
      }
      if (eint + 2 > a->size[1]) {
        emlrtDynamicBoundsCheckR2012b(eint + 2, 1, a->size[1], &c_emlrtBCI,
                                      &st);
      }
      a_data[eint + 1].im = a_data[(int32_T)(J + 1.0) - 1].im;
      if (J + 1.0 != d) {
        emlrtIntegerCheckR2012b(J + 1.0, &d_emlrtDCI, &st);
      }
      if (((int32_T)(J + 1.0) < 1) || ((int32_T)(J + 1.0) > a->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(J + 1.0), 1, a->size[1],
                                      &d_emlrtBCI, &st);
      }
      a_data[(int32_T)(J + 1.0) - 1].re = T_re;
      if (J + 1.0 != d) {
        emlrtIntegerCheckR2012b(J + 1.0, &d_emlrtDCI, &st);
      }
      if (((int32_T)(J + 1.0) < 1) || ((int32_T)(J + 1.0) > a->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(J + 1.0), 1, a->size[1],
                                      &d_emlrtBCI, &st);
      }
      a_data[(int32_T)(J + 1.0) - 1].im = T_im;
    }
    delta1 = LH;
    /* K是比较位数的指示，一开始是二进制最高位，如果J的K位为1，则跳0，比较下一位
     */
    while (J >= delta1) {
      /* 是0则不跳，退出循环       */
      J -= delta1;
      delta1 /= 2.0;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    J += delta1;
    /* K位跳1 还是不明白逻辑，太神棍了这段代码 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxInit_real_T(sp, &l, &g_emlrtRTEI);
  emxInit_creal_T(sp, &c1, &h_emlrtRTEI);
  emxInit_creal_T(sp, &c2, &k_emlrtRTEI);
  emxInit_creal_T(sp, &r, &p_emlrtRTEI);
  emxInit_int32_T(sp, &r1, &p_emlrtRTEI);
  emxInit_uint32_T(sp, &r2, &i_emlrtRTEI);
  while (S <= N) {
    delta1 = N / S;
    /* 每层S循环的DFT问题规模 */
    d = -6.2831853071795862 / S;
    T_re = muDoubleScalarCos(d);
    T_im = muDoubleScalarSin(d);
    i = (int32_T)delta1;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, delta1, mxDOUBLE_CLASS,
                                  (int32_T)delta1, &emlrtRTEI, (emlrtCTX)sp);
    if (0 <= (int32_T)delta1 - 1) {
      b_tmp = S / 2.0;
    }
    for (k = 0; k < i; k++) {
      /* （对每个子段进行循环） */
      if (b_tmp < 1.0) {
        l->size[1] = 0;
      } else {
        i1 = l->size[0] * l->size[1];
        l->size[0] = 1;
        eint = (int32_T)muDoubleScalarFloor(b_tmp - 1.0);
        l->size[1] = eint + 1;
        emxEnsureCapacity_real_T(sp, l, i1, &f_emlrtRTEI);
        wout_data = l->data;
        for (i1 = 0; i1 <= eint; i1++) {
          wout_data[i1] = (real_T)i1 + 1.0;
        }
      }
      i1 = l->size[0] * l->size[1];
      l->size[0] = 1;
      emxEnsureCapacity_real_T(sp, l, i1, &g_emlrtRTEI);
      wout_data = l->data;
      delta1 = (((real_T)k + 1.0) - 1.0) * S;
      eint = l->size[1] - 1;
      for (i1 = 0; i1 <= eint; i1++) {
        wout_data[i1] += delta1;
      }
      i1 = c1->size[0] * c1->size[1];
      c1->size[0] = 1;
      c1->size[1] = l->size[1];
      emxEnsureCapacity_creal_T(sp, c1, i1, &h_emlrtRTEI);
      out_data = c1->data;
      eint = l->size[1];
      for (i1 = 0; i1 < eint; i1++) {
        i2 = (int32_T)wout_data[i1];
        if (wout_data[i1] != i2) {
          emlrtIntegerCheckR2012b(wout_data[i1], &e_emlrtDCI, (emlrtCTX)sp);
        }
        if ((i2 < 1) || (i2 > a->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, a->size[1], &e_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        out_data[i1].re = a_data[i2 - 1].re;
        if (wout_data[i1] != (int32_T)wout_data[i1]) {
          emlrtIntegerCheckR2012b(wout_data[i1], &e_emlrtDCI, (emlrtCTX)sp);
        }
        if (i2 > a->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, a->size[1], &e_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        out_data[i1].im = a_data[i2 - 1].im;
      }
      i1 = r2->size[0] * r2->size[1];
      r2->size[0] = 1;
      r2->size[1] = l->size[1];
      emxEnsureCapacity_uint32_T(sp, r2, i1, &i_emlrtRTEI);
      r3 = r2->data;
      eint = l->size[1];
      for (i1 = 0; i1 < eint; i1++) {
        d = wout_data[i1] + b_tmp;
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &f_emlrtDCI, (emlrtCTX)sp);
        }
        r3[i1] = (uint32_T)d;
      }
      eint = r2->size[1];
      for (i1 = 0; i1 < eint; i1++) {
        i2 = (int32_T)r3[i1];
        if ((i2 < 1) || (i2 > a->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, a->size[1], &f_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      i1 = r->size[0] * r->size[1];
      r->size[0] = 1;
      r->size[1] = l->size[1];
      emxEnsureCapacity_creal_T(sp, r, i1, &j_emlrtRTEI);
      r4 = r->data;
      eint = l->size[1];
      for (i1 = 0; i1 < eint; i1++) {
        J = wout_data[i1] - 1.0;
        if ((T_im == 0.0) && (T_re >= 0.0)) {
          varargout_1.re = muDoubleScalarPower(T_re, J);
          varargout_1.im = 0.0;
        } else if ((T_re == 0.0) && (J == J)) {
          LH = muDoubleScalarPower(T_im, J);
          if (muDoubleScalarIsInf(J)) {
            delta1 = rtNaN;
          } else if (J == 0.0) {
            delta1 = 0.0;
          } else {
            delta1 = muDoubleScalarRem(J, 4.0);
            if (delta1 == 0.0) {
              delta1 = 0.0;
            }
          }
          d = muDoubleScalarRound(delta1);
          if (d < 128.0) {
            i3 = (int8_T)d;
          } else {
            i3 = 0;
          }
          if (i3 == 3) {
            varargout_1.re = 0.0;
            varargout_1.im = -LH;
          } else if (i3 == 2) {
            varargout_1.re = -LH;
            varargout_1.im = 0.0;
          } else if (i3 == 1) {
            varargout_1.re = 0.0;
            varargout_1.im = LH;
          } else {
            varargout_1.re = LH;
            varargout_1.im = 0.0;
          }
        } else if ((T_im == 0.0) && muDoubleScalarIsInf(J) &&
                   (muDoubleScalarAbs(T_re) == 1.0)) {
          varargout_1.re = 1.0;
          varargout_1.im = 0.0;
        } else {
          if (T_im == 0.0) {
            if (T_re < 0.0) {
              delta1 = muDoubleScalarLog(muDoubleScalarAbs(T_re));
              LH = 3.1415926535897931;
            } else {
              delta1 = muDoubleScalarLog(T_re);
              LH = 0.0;
            }
          } else {
            delta1 = muDoubleScalarLog(muDoubleScalarHypot(T_re, T_im));
            LH = muDoubleScalarAtan2(T_im, T_re);
          }
          varargout_1.re = J * delta1;
          varargout_1.im = J * LH;
          if (varargout_1.im == 0.0) {
            d = varargout_1.re;
            varargout_1.re = muDoubleScalarExp(d);
            varargout_1.im = 0.0;
          } else if (muDoubleScalarIsInf(varargout_1.im) &&
                     muDoubleScalarIsInf(varargout_1.re) &&
                     (varargout_1.re < 0.0)) {
            varargout_1.re = 0.0;
            varargout_1.im = 0.0;
          } else {
            delta1 = muDoubleScalarExp(varargout_1.re / 2.0);
            d = varargout_1.im;
            J = varargout_1.im;
            varargout_1.re = delta1 * (delta1 * muDoubleScalarCos(d));
            varargout_1.im = delta1 * (delta1 * muDoubleScalarSin(J));
          }
        }
        r4[i1] = varargout_1;
      }
      if ((r2->size[1] != r->size[1]) &&
          ((r2->size[1] != 1) && (r->size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(r2->size[1], r->size[1], &emlrtECI,
                                    (emlrtCTX)sp);
      }
      if (r2->size[1] == r->size[1]) {
        i1 = c2->size[0] * c2->size[1];
        c2->size[0] = 1;
        c2->size[1] = r2->size[1];
        emxEnsureCapacity_creal_T(sp, c2, i1, &k_emlrtRTEI);
        c2_data = c2->data;
        eint = r2->size[1];
        for (i1 = 0; i1 < eint; i1++) {
          i2 = (int32_T)r3[i1] - 1;
          d = a_data[i2].re;
          J = r4[i1].im;
          delta1 = a_data[i2].im;
          LH = r4[i1].re;
          c2_data[i1].re = d * LH - delta1 * J;
          c2_data[i1].im = d * J + delta1 * LH;
        }
      } else {
        st.site = &j_emlrtRSI;
        binary_expand_op(&st, c2, a, r2, r);
        c2_data = c2->data;
      }
      if ((l->size[1] != c2->size[1]) &&
          ((l->size[1] != 1) && (c2->size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(l->size[1], c2->size[1], &b_emlrtECI,
                                    (emlrtCTX)sp);
      }
      i1 = r1->size[0] * r1->size[1];
      r1->size[0] = 1;
      r1->size[1] = l->size[1];
      emxEnsureCapacity_int32_T(sp, r1, i1, &l_emlrtRTEI);
      r5 = r1->data;
      eint = l->size[1];
      for (i1 = 0; i1 < eint; i1++) {
        i2 = (int32_T)wout_data[i1];
        if ((i2 < 1) || (i2 > a->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)wout_data[i1], 1, a->size[1],
                                        &g_emlrtBCI, (emlrtCTX)sp);
        }
        r5[i1] = i2;
      }
      if (c1->size[1] == c2->size[1]) {
        i1 = r->size[0] * r->size[1];
        r->size[0] = 1;
        r->size[1] = c1->size[1];
        emxEnsureCapacity_creal_T(sp, r, i1, &m_emlrtRTEI);
        r4 = r->data;
        eint = c1->size[1];
        for (i1 = 0; i1 < eint; i1++) {
          r4[i1].re = out_data[i1].re + c2_data[i1].re;
          r4[i1].im = out_data[i1].im + c2_data[i1].im;
        }
      } else {
        st.site = &k_emlrtRSI;
        plus(&st, r, c1, c2);
        r4 = r->data;
      }
      if (r1->size[1] != r->size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(r1->size[1], r->size[1], &c_emlrtECI,
                                        (emlrtCTX)sp);
      }
      eint = r->size[1] - 1;
      for (i1 = 0; i1 <= eint; i1++) {
        a_data[r5[i1] - 1] = r4[i1];
      }
      if ((c1->size[1] != c2->size[1]) &&
          ((c1->size[1] != 1) && (c2->size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(c1->size[1], c2->size[1], &d_emlrtECI,
                                    (emlrtCTX)sp);
      }
      i1 = r1->size[0] * r1->size[1];
      r1->size[0] = 1;
      r1->size[1] = r2->size[1];
      emxEnsureCapacity_int32_T(sp, r1, i1, &n_emlrtRTEI);
      r5 = r1->data;
      eint = r2->size[1];
      for (i1 = 0; i1 < eint; i1++) {
        if (((int32_T)r3[i1] < 1) || ((int32_T)r3[i1] > a->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)r3[i1], 1, a->size[1],
                                        &h_emlrtBCI, (emlrtCTX)sp);
        }
        r5[i1] = (int32_T)r3[i1];
      }
      if (c1->size[1] == c2->size[1]) {
        eint = c1->size[1] - 1;
        i1 = c1->size[0] * c1->size[1];
        c1->size[0] = 1;
        emxEnsureCapacity_creal_T(sp, c1, i1, &o_emlrtRTEI);
        out_data = c1->data;
        for (i1 = 0; i1 <= eint; i1++) {
          out_data[i1].re -= c2_data[i1].re;
          out_data[i1].im -= c2_data[i1].im;
        }
      } else {
        st.site = &i_emlrtRSI;
        minus(&st, c1, c2);
        out_data = c1->data;
      }
      if (r1->size[1] != c1->size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(r1->size[1], c1->size[1], &e_emlrtECI,
                                        (emlrtCTX)sp);
      }
      eint = c1->size[1] - 1;
      for (i1 = 0; i1 <= eint; i1++) {
        a_data[r5[i1] - 1] = out_data[i1];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    S *= 2.0;
    /* 向上递归 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_uint32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_creal_T(sp, &r);
  emxFree_creal_T(sp, &c2);
  emxFree_creal_T(sp, &c1);
  emxFree_real_T(sp, &l);
  i = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = a->size[1];
  emxEnsureCapacity_creal_T(sp, out, i, &e_emlrtRTEI);
  out_data = out->data;
  eint = a->size[1];
  for (i = 0; i < eint; i++) {
    delta1 = a_data[i].re;
    LH = a_data[i].im;
    if (LH == 0.0) {
      out_data[i].re = delta1 / N;
      out_data[i].im = 0.0;
    } else if (delta1 == 0.0) {
      out_data[i].re = 0.0;
      out_data[i].im = LH / N;
    } else {
      out_data[i].re = delta1 / N;
      out_data[i].im = LH / N;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (FFT1.c) */
