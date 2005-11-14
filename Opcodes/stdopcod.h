/*
    stdopcod.h:

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
    02111-1307 USA
*/

#ifndef CSOUND_STDOPCOD_H
#define CSOUND_STDOPCOD_H

#include "csdl.h"

/* file structure for fout opcodes */

struct fileinTag {
    SNDFILE     *file;          /* Used in audio cases */
    FILE        *raw;           /* Only used if text file */
    void        *fd;
    char        *name;
    char        *fullName;
    int         do_scale;
};

typedef struct VCO2_TABLE_ARRAY_  VCO2_TABLE_ARRAY;
typedef struct _atsbufread        ATSBUFREAD;

typedef struct STDOPCOD_GLOBALS_ {
    CSOUND      *csound;
    /* fout.c */
    struct fileinTag  *file_opened;
    int         file_max;
    int         file_num;
    long        fout_kreset;
    MYFLT       *buf;
    int         buf_size;
    /* oscbnk.c */
    unsigned long     oscbnk_seed;
    long        rnd31i_seed;
    int         denorm_seed;
    int         vco2_nr_table_arrays;
    VCO2_TABLE_ARRAY  **vco2_tables;
    /* ugnorman.c */
    ATSBUFREAD  *atsbufreadaddr;
    int         swapped_warning;
    /* locsig.c */
    void        *locsigaddr;
    /* space.c */
    void        *spaceaddr;
    /* gab/gab.c */
    MYFLT       *tb_ptrs[16];
    /* scansyn.c */
    MYFLT       *ewin;
    void        *scsn_list;
    /* scansynx.c */
    MYFLT       *ewinx;
    void        *scsnx_list;
} STDOPCOD_GLOBALS;

static inline STDOPCOD_GLOBALS *stdopcod_getGlobals(CSOUND *csound,
                                                    STDOPCOD_GLOBALS **p)
{
    if (*p == NULL) {
      *p = (STDOPCOD_GLOBALS*) csound->QueryGlobalVariableNoCheck(csound,
                                                                  "stdOp_Env");
    }
    return *p;
}

extern int ambicode_init_(CSOUND *);
extern int babo_init_(CSOUND *);
extern int bbcut_init_(CSOUND *);
extern int biquad_init_(CSOUND *);
extern int butter_init_(CSOUND *);
extern int clfilt_init_(CSOUND *);
extern int cross2_init_(CSOUND *);
extern int dam_init_(CSOUND *);
extern int dcblockr_init_(CSOUND *);
extern int filter_init_(CSOUND *);
extern int flanger_init_(CSOUND *);
extern int follow_init_(CSOUND *);
extern int fout_init_(CSOUND *);
extern int freeverb_init_(CSOUND *);
extern int ftconv_init_(CSOUND *);
extern int ftgen_init_(CSOUND *);
extern int gab_gab_init_(CSOUND *);
extern int gab_vectorial_init_(CSOUND *);
extern int grain4_init_(CSOUND *);
extern int grain_init_(CSOUND *);
extern int hrtferX_init_(CSOUND *);
extern int ifd_init_(CSOUND *);
extern int locsig_init_(CSOUND *);
extern int lowpassr_init_(CSOUND *);
extern int metro_init_(CSOUND *);
extern int midiops2_init_(CSOUND *);
extern int midiops3_init_(CSOUND *);
extern int newfils_init_(CSOUND *);
extern int nlfilt_init_(CSOUND *);
extern int oscbnk_init_(CSOUND *);
extern int partials_init_(CSOUND *);
extern int phisem_init_(CSOUND *);
extern int pluck_init_(CSOUND *);
extern int psynth_init_(CSOUND *);
extern int pvsbasic_init_(CSOUND *);
extern int pvscent_init_(CSOUND *);
extern int pvsdemix_init_(CSOUND *);
extern int repluck_init_(CSOUND *);
extern int reverbsc_init_(CSOUND *);
extern int scansyn_init_(CSOUND *);
extern int scansynx_init_(CSOUND *);
extern int seqtime_init_(CSOUND *);
extern int sndloop_init_(CSOUND *);
extern int sndwarp_init_(CSOUND *);
extern int space_init_(CSOUND *);
extern int spat3d_init_(CSOUND *);
extern int syncgrain_init_(CSOUND *);
extern int ugens7_init_(CSOUND *);
extern int ugens9_init_(CSOUND *);
extern int ugensa_init_(CSOUND *);
extern int uggab_init_(CSOUND *);
extern int ugmoss_init_(CSOUND *);
extern int ugnorman_init_(CSOUND *);
extern int ugsc_init_(CSOUND *);
extern int wave_terrain_init_(CSOUND *);

#endif  /* CSOUND_STDOPCOD_H */

