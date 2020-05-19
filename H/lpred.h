/*
  lpred.h:

  Copyright 2020 Victor Lazzarini

  streaming linear prediction

  This file is part of Csound.

  The Csound Library is free software; you can redistribute it
  and/or modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Csound is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
  02110-1301 USA
*/

#ifndef CSOUND_LPRED_H
#define CSOUND_LPRED_H

#if !defined(__BUILDING_LIBCSOUND)
#  error "Csound plugins and host applications should not include fftlib.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
  * Compute autocorrelation function
  * r: autocorrelation output array (size N)
  * s: input signal
  * N: signal size
  * returns: autocorrelation r
  */
  MYFLT *csoundAutoCorrelation(CSOUND *csound, MYFLT *r, MYFLT *s, int N);


   /**
   * Linear prediction setup
   *
   * N: autocorrelation size
   * M: filter order
   *
   * returns: opaque LP structure to use with linear prediction function
   */
  void *csoundLPsetup(CSOUND *csound, int N, int M);

   /**
   * Linear prediction setup deallocation
   *
   * param: LP setup object
   *
   */

  void csoundLPfree(CSOUND *csound, void *param);

  /**
   * Compute linear prediction coefficients
   *
   * x: input signal
   * param: LP setup object
   *
   * returns: array of size M+1 with error E and coefficients 1-M
   * output format is [E,c1,c2,...,cm] OR NULL if a memory problem occured
   * NB: c0 is always 1
  */
  MYFLT *csoundLPread(CSOUND *csound, void *p, MYFLT *x);

  /**
   * Compute cepstrum coefficients from all-pole coefficients
   * and linear prediction error
   *
   * c: array of size N
   * b: array of size M+1 with M all-pole coefficients
   *   and E in place of coefficient 0 [E,c1,...,cM]
   * N: size of cepstrum array output
   * M: all-pole filter order
   *
   * returns: array with N cepstrum coefficients
   * NB: cepstrum is computed from power spectrum
   */
  MYFLT *csoundCepsLP(CSOUND *csound, MYFLT *b, MYFLT *c, int M, int N);

  /**
   * Compute all-pole coefficients and linear prediction error
   * from cepstrum coefficients
   *
   * b: array of size M+1
   * c: array of size N with cepstrum coeffs
   *
   * M: all-pole filter order
   * N: cepstrum size
   *
   * returns: M+1 size array with all-pole coefficients 1-M and
   * E in place of coefficient 0 [E,c1,...,cM]
   * NB: cepstrum is expected to be computed from power spectrum
   */
  MYFLT *csoundLPCeps(CSOUND *csound, MYFLT *c, MYFLT *b, int N, int M);


typedef struct _lpfil {
  OPDS h;
  MYFLT *out;
  MYFLT *in, *koff, *kflag, *ifn, *isiz, *iord, *iwin;
  AUXCH coefs;
  AUXCH del;
  AUXCH buf;
  int32_t M, N, wlen;
  int32_t rp;
  void *setup;
  MYFLT *win, g;
  FUNC *ft;
} LPCFIL;

typedef struct _lpfil2 {
  OPDS h;
  MYFLT *out;
  MYFLT *in, *sig, *flag, *prd, *isiz, *iord, *iwin;
  AUXCH coefs;
  AUXCH del;
  AUXCH buf;
  AUXCH cbuf;
  int32_t M, N, wlen;
  int32_t rp,bp,cp;
  MYFLT *win, g;
  void *setup;
} LPCFIL2;

typedef struct _lpreda {
  OPDS h;
  ARRAYDAT *out;
  MYFLT *rms, *err, *cps;
  MYFLT  *off, *flag, *ifn, *isiz, *iord, *iwin;
  AUXCH buf;
  int32_t M, N, wlen;
  FUNC *ft;
  MYFLT *win;
  void *setup;
} LPREDA;

typedef struct _lpfil3 {
  OPDS h;
  MYFLT *out, *in;
  ARRAYDAT *coefs;
  AUXCH del;
  int32_t M;
  int32_t rp;
} LPCFIL3;

typedef struct _lpreda2 {
  OPDS h;
  ARRAYDAT *out;
  MYFLT *rms, *err, *cps;
  MYFLT  *in, *flag, *prd, *isiz, *iord, *iwin;
  AUXCH cbuf;
  AUXCH buf;
  int32_t M, N, wlen, cp, bp;
  MYFLT *win;
  void *setup;
} LPREDA2;  


#ifdef __cplusplus
}
#endif

#endif      /* CSOUND_LPRED_H */