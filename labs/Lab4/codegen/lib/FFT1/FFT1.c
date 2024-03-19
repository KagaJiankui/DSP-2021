/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: FFT1.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 05-Dec-2021 23:57:59
 */

/* Include Files */
#include "FFT1.h"
#include "FFT1_emxutil.h"
#include "FFT1_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <immintrin.h>
#include <math.h>

/* Variable Definitions */
omp_nest_lock_t FFT1_nestLockGlobal;

static boolean_T isInitialized_FFT1 = false;

/* Function Declarations */
static void b_binary_expand_op(emxArray_creal_T *a, const emxArray_real_T *l,
                               const emxArray_creal_T *c1,
                               const emxArray_creal_T *c2);

static void binary_expand_op(emxArray_creal_T *a, const emxArray_uint32_T *r1,
                             const emxArray_creal_T *c1,
                             const emxArray_creal_T *c2);

static void c_binary_expand_op(emxArray_creal_T *c2, const emxArray_creal_T *a,
                               const emxArray_uint32_T *r2,
                               const emxArray_creal_T *r3);

static double rt_atan2d_snf(double u0, double u1);

static double rt_hypotd_snf(double u0, double u1);

static double rt_powd_snf(double u0, double u1);

static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : emxArray_creal_T *a
 *                const emxArray_real_T *l
 *                const emxArray_creal_T *c1
 *                const emxArray_creal_T *c2
 * Return Type  : void
 */
static void b_binary_expand_op(emxArray_creal_T *a, const emxArray_real_T *l,
                               const emxArray_creal_T *c1,
                               const emxArray_creal_T *c2)
{
  const creal_T *c1_data;
  const creal_T *c2_data;
  creal_T *a_data;
  const double *l_data;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  c2_data = c2->data;
  c1_data = c1->data;
  l_data = l->data;
  a_data = a->data;
  stride_0_1 = (c1->size[1] != 1);
  stride_1_1 = (c2->size[1] != 1);
  if (c2->size[1] == 1) {
    loop_ub = c1->size[1];
  } else {
    loop_ub = c2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    i2 = (int)l_data[i] - 1;
    a_data[i2].re = c1_data[i * stride_0_1].re + c2_data[i1].re;
    a_data[i2].im = c1_data[i * stride_0_1].im + c2_data[i1].im;
  }
}

/*
 * Arguments    : emxArray_creal_T *a
 *                const emxArray_uint32_T *r1
 *                const emxArray_creal_T *c1
 *                const emxArray_creal_T *c2
 * Return Type  : void
 */
static void binary_expand_op(emxArray_creal_T *a, const emxArray_uint32_T *r1,
                             const emxArray_creal_T *c1,
                             const emxArray_creal_T *c2)
{
  const creal_T *c1_data;
  const creal_T *c2_data;
  creal_T *a_data;
  const unsigned int *r;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  c2_data = c2->data;
  c1_data = c1->data;
  r = r1->data;
  a_data = a->data;
  stride_0_1 = (c1->size[1] != 1);
  stride_1_1 = (c2->size[1] != 1);
  if (c2->size[1] == 1) {
    loop_ub = c1->size[1];
  } else {
    loop_ub = c2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    i2 = (int)r[i] - 1;
    a_data[i2].re = c1_data[i * stride_0_1].re - c2_data[i1].re;
    a_data[i2].im = c1_data[i * stride_0_1].im - c2_data[i1].im;
  }
}

/*
 * Arguments    : emxArray_creal_T *c2
 *                const emxArray_creal_T *a
 *                const emxArray_uint32_T *r2
 *                const emxArray_creal_T *r3
 * Return Type  : void
 */
static void c_binary_expand_op(emxArray_creal_T *c2, const emxArray_creal_T *a,
                               const emxArray_uint32_T *r2,
                               const emxArray_creal_T *r3)
{
  const creal_T *a_data;
  const creal_T *r;
  creal_T *c2_data;
  double b_re_tmp;
  double c_re_tmp;
  double e_re_tmp;
  double f_re_tmp;
  const unsigned int *r1;
  int d_re_tmp;
  int i;
  int loop_ub;
  int re_tmp;
  int stride_0_1;
  int stride_1_1;
  r = r3->data;
  r1 = r2->data;
  a_data = a->data;
  re_tmp = c2->size[0] * c2->size[1];
  c2->size[0] = 1;
  if (r3->size[1] == 1) {
    c2->size[1] = r2->size[1];
  } else {
    c2->size[1] = r3->size[1];
  }
  emxEnsureCapacity_creal_T(c2, re_tmp);
  c2_data = c2->data;
  stride_0_1 = (r2->size[1] != 1);
  stride_1_1 = (r3->size[1] != 1);
  if (r3->size[1] == 1) {
    loop_ub = r2->size[1];
  } else {
    loop_ub = r3->size[1];
  }
  if (loop_ub < 1200) {
    for (i = 0; i < loop_ub; i++) {
      re_tmp = i * stride_1_1;
      b_re_tmp = r[re_tmp].im;
      c_re_tmp = r[re_tmp].re;
      c2_data[i].re = a_data[(int)r1[i * stride_0_1] - 1].re * c_re_tmp -
                      a_data[(int)r1[i * stride_0_1] - 1].im * b_re_tmp;
      c2_data[i].im = a_data[(int)r1[i * stride_0_1] - 1].re * b_re_tmp +
                      a_data[(int)r1[i * stride_0_1] - 1].im * c_re_tmp;
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    12 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 12) private(d_re_tmp, e_re_tmp, f_re_tmp)

    for (i = 0; i < loop_ub; i++) {
      d_re_tmp = i * stride_1_1;
      e_re_tmp = r[d_re_tmp].im;
      f_re_tmp = r[d_re_tmp].re;
      c2_data[i].re = a_data[(int)r1[i * stride_0_1] - 1].re * f_re_tmp -
                      a_data[(int)r1[i * stride_0_1] - 1].im * e_re_tmp;
      c2_data[i].im = a_data[(int)r1[i * stride_0_1] - 1].re * e_re_tmp +
                      a_data[(int)r1[i * stride_0_1] - 1].im * f_re_tmp;
    }
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double d;
  double d1;
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * function [out,wout]=FFT1(a)
 *
 * Arguments    : emxArray_creal_T *a
 *                emxArray_creal_T *out
 *                emxArray_real_T *wout
 * Return Type  : void
 */
void FFT1(emxArray_creal_T *a, emxArray_creal_T *out, emxArray_real_T *wout)
{
  __m256d r2;
  emxArray_creal_T *c1;
  emxArray_creal_T *c2;
  emxArray_creal_T *r1;
  emxArray_real_T *l;
  emxArray_uint32_T *r;
  creal_T T;
  creal_T varargout_1;
  creal_T *a_data;
  creal_T *c2_data;
  creal_T *out_data;
  creal_T *r4;
  double J;
  double K;
  double N;
  double S;
  double ai;
  double ar;
  double b_tmp;
  double d;
  double delta1;
  double *wout_data;
  int b_k;
  int eint;
  int i;
  int i1;
  int i2;
  int k;
  int loop_ub;
  int vectorUB;
  unsigned int *r3;
  signed char i3;
  if (!isInitialized_FFT1) {
    FFT1_initialize();
  }
  /* 'FFT1:2' N=2^(ceil(log2(length(a)))); */
  if (a->size[1] == 0) {
    delta1 = rtMinusInf;
  } else {
    delta1 = frexp(a->size[1], &eint);
    if (delta1 == 0.5) {
      delta1 = (double)eint - 1.0;
    } else if ((eint == 1) && (delta1 < 0.75)) {
      delta1 = log(2.0 * delta1) / 0.69314718055994529;
    } else {
      delta1 = log(delta1) / 0.69314718055994529 + (double)eint;
    }
  }
  N = rt_powd_snf(2.0, ceil(delta1));
  /* 最近二次幂 */
  /* 'FFT1:3' a=[a,zeros(1,N-length(a))]; */
  eint = (int)(N - (double)a->size[1]);
  i = a->size[1];
  i1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] += eint;
  emxEnsureCapacity_creal_T(a, i1);
  a_data = a->data;
  if (eint < 1200) {
    for (i2 = 0; i2 < eint; i2++) {
      i1 = i2 + i;
      a_data[i1].re = 0.0;
      a_data[i1].im = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    12 > omp_get_max_threads() ? omp_get_max_threads() : 12) private(k)

    for (i2 = 0; i2 < eint; i2++) {
      k = i2 + i;
      a_data[k].re = 0.0;
      a_data[k].im = 0.0;
    }
  }
  /* 'FFT1:4' wout=linspace(0,2*pi,length(a)); */
  i = wout->size[0] * wout->size[1];
  wout->size[0] = 1;
  wout->size[1] = a->size[1];
  emxEnsureCapacity_real_T(wout, i);
  wout_data = wout->data;
  if (a->size[1] >= 1) {
    wout_data[a->size[1] - 1] = 6.2831853071795862;
    if (wout->size[1] >= 2) {
      wout_data[0] = 0.0;
      if (wout->size[1] >= 3) {
        delta1 = 6.2831853071795862 / ((double)wout->size[1] - 1.0);
        i = wout->size[1];
        if (wout->size[1] - 2 < 1200) {
          for (k = 0; k <= i - 3; k++) {
            wout_data[k + 1] = ((double)k + 1.0) * delta1;
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    12 > omp_get_max_threads() ? omp_get_max_threads() : 12)

          for (k = 0; k <= i - 3; k++) {
            wout_data[k + 1] = ((double)k + 1.0) * delta1;
          }
        }
      }
    }
  }
  /* 'FFT1:5' S=1; */
  S = 1.0;
  /* 'FFT1:6' a=Reverse_Rader(a,N); */
  /* 'Reverse_Rader:2' LH=N/2; */
  delta1 = N / 2.0;
  /* 'Reverse_Rader:3' J=LH; */
  J = delta1;
  /* 'Reverse_Rader:4' N1=N-2; */
  /* 'Reverse_Rader:5' for I=1:1:N1 */
  i = (int)(N - 2.0);
  for (eint = 0; eint < i; eint++) {
    /* 'Reverse_Rader:6' if I<J */
    if ((double)eint + 1.0 < J) {
      /* 'Reverse_Rader:7' T=F(I+1); */
      T = a_data[eint + 1];
      /* 'Reverse_Rader:8' F(I+1)=F(J+1); */
      a_data[eint + 1] = a_data[(int)(J + 1.0) - 1];
      /* 'Reverse_Rader:9' F(J+1)=T; */
      a_data[(int)(J + 1.0) - 1] = T;
    }
    /* 'Reverse_Rader:11' K=LH; */
    /* K是比较位数的指示，一开始是二进制最高位，如果J的K位为1，则跳0，比较下一位
     */
    /* 'Reverse_Rader:12' while J>=K */
    for (K = delta1; J >= K; K /= 2.0) {
      /* 是0则不跳，退出循环       */
      /* 'Reverse_Rader:13' J=J-K; */
      J -= K;
      /* 'Reverse_Rader:14' K=K/2; */
    }
    /* 'Reverse_Rader:16' J=J+K; */
    J += K;
    /* K位跳1 还是不明白逻辑，太神棍了这段代码 */
  }
  /* 'Reverse_Rader:18' Y=F; */
  /* 'FFT1:7' while S<=N */
  emxInit_real_T(&l, 2);
  emxInit_creal_T(&c1, 2);
  emxInit_creal_T(&c2, 2);
  emxInit_uint32_T(&r);
  emxInit_creal_T(&r1, 2);
  while (S <= N) {
    /* 'FFT1:8' T=N/S; */
    /* 每层S循环的DFT问题规模 */
    /* 'FFT1:9' Ws=exp(-1i*2*pi/S); */
    d = -6.2831853071795862 / S;
    T.re = cos(d);
    T.im = sin(d);
    /* 'FFT1:10' for k=1:T */
    i = (int)(N / S);
    if (0 <= i - 1) {
      b_tmp = S / 2.0;
    }
    for (b_k = 0; b_k < i; b_k++) {
      /* （对每个子段进行循环） */
      /* 'FFT1:11' l=(k-1)*S+(1:S/2); */
      if (b_tmp < 1.0) {
        l->size[1] = 0;
      } else {
        i1 = l->size[0] * l->size[1];
        l->size[0] = 1;
        loop_ub = (int)floor(b_tmp - 1.0);
        l->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(l, i1);
        wout_data = l->data;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          wout_data[i1] = (double)i1 + 1.0;
        }
      }
      i1 = l->size[0] * l->size[1];
      l->size[0] = 1;
      emxEnsureCapacity_real_T(l, i1);
      wout_data = l->data;
      delta1 = (((double)b_k + 1.0) - 1.0) * S;
      loop_ub = l->size[1] - 1;
      eint = (l->size[1] / 4) << 2;
      vectorUB = eint - 4;
      for (i1 = 0; i1 <= vectorUB; i1 += 4) {
        r2 = _mm256_loadu_pd(&wout_data[i1]);
        _mm256_storeu_pd(&wout_data[i1],
                         _mm256_add_pd(_mm256_set1_pd(delta1), r2));
      }
      for (i1 = eint; i1 <= loop_ub; i1++) {
        wout_data[i1] += delta1;
      }
      /* 'FFT1:12' c1=a(l); */
      i1 = c1->size[0] * c1->size[1];
      c1->size[0] = 1;
      c1->size[1] = l->size[1];
      emxEnsureCapacity_creal_T(c1, i1);
      out_data = c1->data;
      loop_ub = l->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        out_data[i1] = a_data[(int)wout_data[i1] - 1];
      }
      /* 'FFT1:13' c2=a(l+S/2).*(Ws.^(l-1)); */
      i1 = r->size[0] * r->size[1];
      r->size[0] = 1;
      r->size[1] = l->size[1];
      emxEnsureCapacity_uint32_T(r, i1);
      r3 = r->data;
      loop_ub = l->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        r3[i1] = (unsigned int)(wout_data[i1] + b_tmp);
      }
      i1 = r1->size[0] * r1->size[1];
      r1->size[0] = 1;
      r1->size[1] = l->size[1];
      emxEnsureCapacity_creal_T(r1, i1);
      r4 = r1->data;
      loop_ub = l->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        K = wout_data[i1] - 1.0;
        if ((T.im == 0.0) && (T.re >= 0.0)) {
          varargout_1.re = rt_powd_snf(T.re, K);
          varargout_1.im = 0.0;
        } else if ((T.re == 0.0) && (K == K)) {
          J = rt_powd_snf(T.im, K);
          if (rtIsInf(K)) {
            delta1 = rtNaN;
          } else if (K == 0.0) {
            delta1 = 0.0;
          } else {
            delta1 = fmod(K, 4.0);
            if (delta1 == 0.0) {
              delta1 = 0.0;
            }
          }
          d = rt_roundd_snf(delta1);
          if (d < 128.0) {
            i3 = (signed char)d;
          } else {
            i3 = 0;
          }
          if (i3 == 3) {
            varargout_1.re = 0.0;
            varargout_1.im = -J;
          } else if (i3 == 2) {
            varargout_1.re = -J;
            varargout_1.im = 0.0;
          } else if (i3 == 1) {
            varargout_1.re = 0.0;
            varargout_1.im = J;
          } else {
            varargout_1.re = J;
            varargout_1.im = 0.0;
          }
        } else if ((T.im == 0.0) && rtIsInf(K) && (fabs(T.re) == 1.0)) {
          varargout_1.re = 1.0;
          varargout_1.im = 0.0;
        } else {
          if (T.im == 0.0) {
            if (T.re < 0.0) {
              delta1 = log(fabs(T.re));
              J = 3.1415926535897931;
            } else {
              delta1 = log(T.re);
              J = 0.0;
            }
          } else {
            delta1 = log(rt_hypotd_snf(T.re, T.im));
            J = rt_atan2d_snf(T.im, T.re);
          }
          varargout_1.re = K * delta1;
          varargout_1.im = K * J;
          if (varargout_1.im == 0.0) {
            d = varargout_1.re;
            varargout_1.re = exp(d);
            varargout_1.im = 0.0;
          } else if (rtIsInf(varargout_1.im) && rtIsInf(varargout_1.re) &&
                     (varargout_1.re < 0.0)) {
            varargout_1.re = 0.0;
            varargout_1.im = 0.0;
          } else {
            delta1 = exp(varargout_1.re / 2.0);
            d = varargout_1.im;
            K = varargout_1.im;
            varargout_1.re = delta1 * (delta1 * cos(d));
            varargout_1.im = delta1 * (delta1 * sin(K));
          }
        }
        r4[i1] = varargout_1;
      }
      if (r->size[1] == r1->size[1]) {
        i1 = c2->size[0] * c2->size[1];
        c2->size[0] = 1;
        c2->size[1] = r->size[1];
        emxEnsureCapacity_creal_T(c2, i1);
        c2_data = c2->data;
        loop_ub = r->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          eint = (int)r3[i1] - 1;
          d = a_data[eint].re;
          K = r4[i1].im;
          delta1 = a_data[eint].im;
          J = r4[i1].re;
          c2_data[i1].re = d * J - delta1 * K;
          c2_data[i1].im = d * K + delta1 * J;
        }
      } else {
        c_binary_expand_op(c2, a, r, r1);
        c2_data = c2->data;
      }
      /* 'FFT1:14' a(l)=c1+c2; */
      if (c1->size[1] == c2->size[1]) {
        loop_ub = c1->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          eint = (int)wout_data[i1] - 1;
          a_data[eint].re = out_data[i1].re + c2_data[i1].re;
          a_data[eint].im = out_data[i1].im + c2_data[i1].im;
        }
      } else {
        b_binary_expand_op(a, l, c1, c2);
        a_data = a->data;
      }
      /* 'FFT1:15' a(l+S/2)=c1-c2; */
      if (c1->size[1] == c2->size[1]) {
        loop_ub = c1->size[1];
        for (i1 = 0; i1 < loop_ub; i1++) {
          eint = (int)r3[i1] - 1;
          a_data[eint].re = out_data[i1].re - c2_data[i1].re;
          a_data[eint].im = out_data[i1].im - c2_data[i1].im;
        }
      } else {
        binary_expand_op(a, r, c1, c2);
        a_data = a->data;
      }
    }
    /* 'FFT1:17' S=S*2; */
    S *= 2.0;
    /* 向上递归 */
  }
  emxFree_creal_T(&r1);
  emxFree_uint32_T(&r);
  emxFree_creal_T(&c2);
  emxFree_creal_T(&c1);
  emxFree_real_T(&l);
  /* 'FFT1:19' out=a/N; */
  i = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = a->size[1];
  emxEnsureCapacity_creal_T(out, i);
  out_data = out->data;
  loop_ub = a->size[1];
  if (a->size[1] < 1200) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      delta1 = a_data[i2].re;
      J = a_data[i2].im;
      if (J == 0.0) {
        out_data[i2].re = delta1 / N;
        out_data[i2].im = 0.0;
      } else if (delta1 == 0.0) {
        out_data[i2].re = 0.0;
        out_data[i2].im = J / N;
      } else {
        out_data[i2].re = delta1 / N;
        out_data[i2].im = J / N;
      }
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    12 > omp_get_max_threads() ? omp_get_max_threads() : 12) private(ar, ai)

    for (i2 = 0; i2 < loop_ub; i2++) {
      ar = a_data[i2].re;
      ai = a_data[i2].im;
      if (ai == 0.0) {
        out_data[i2].re = ar / N;
        out_data[i2].im = 0.0;
      } else if (ar == 0.0) {
        out_data[i2].re = 0.0;
        out_data[i2].im = ai / N;
      } else {
        out_data[i2].re = ar / N;
        out_data[i2].im = ai / N;
      }
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void FFT1_initialize(void)
{
  omp_init_nest_lock(&FFT1_nestLockGlobal);
  isInitialized_FFT1 = true;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void FFT1_terminate(void)
{
  omp_destroy_nest_lock(&FFT1_nestLockGlobal);
  isInitialized_FFT1 = false;
}

/*
 * File trailer for FFT1.c
 *
 * [EOF]
 */
