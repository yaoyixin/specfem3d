/* Copyright 2007,2008 ENSEIRB, INRIA & CNRS
**
** This file is part of the Scotch software package for static mapping,
** graph partitioning and sparse matrix ordering.
**
** This software is governed by the CeCILL-C license under French law
** and abiding by the rules of distribution of free software. You can
** use, modify and/or redistribute the software under the terms of the
** CeCILL-C license as circulated by CEA, CNRS and INRIA at the following
** URL: "http://www.cecill.info".
** 
** As a counterpart to the access to the source code and rights to copy,
** modify and redistribute granted by the license, users are provided
** only with a limited warranty and the software's author, the holder of
** the economic rights, and the successive licensors have only limited
** liability.
** 
** In this respect, the user's attention is drawn to the risks associated
** with loading, using, modifying and/or developing or reproducing the
** software by the user in light of its specific status of free software,
** that may mean that it is complicated to manipulate, and that also
** therefore means that it is reserved for developers and experienced
** professionals having in-depth computer knowledge. Users are therefore
** encouraged to load and test the software's suitability as regards
** their requirements in conditions enabling the security of their
** systems and/or data to be ensured and, more generally, to use and
** operate it in the same conditions as regards security.
** 
** The fact that you are presently reading this means that you have had
** knowledge of the CeCILL-C license and that you accept its terms.
*/
/************************************************************/
/**                                                        **/
/**   NAME       : arch_cmpltw.h                           **/
/**                                                        **/
/**   AUTHOR     : Francois PELLEGRINI                     **/
/**                                                        **/
/**   FUNCTION   : These lines are the data declaration    **/
/**                for the weighted complete graph target  **/
/**                architecture functions.                 **/
/**                                                        **/
/**   DATES      : # Version 5.1  : from : 11 dec 2007     **/
/**                                 to     21 jan 2008     **/
/**                                                        **/
/************************************************************/

/*
**  The type and structure definitions.
*/

/*+ The weighted target vertex. They are coded as Gnum
    rather than as Anum because this array needs to be
    sorted, by means of the intSort2asc1 routine.      +*/

#ifndef GRAPH_H
#define Gnum                        Anum          /* Prevent data type to be undefined */
#endif /* GRAPH_H */

typedef struct ArchCmpltwLoad_ {
  Gnum                      veloval;              /*+ Vertex load  +*/
  Gnum                      vertnum;              /*+ Vertex index +*/
} ArchCmpltwLoad;

/*+ The weighted complete graph definitions. +*/

typedef struct ArchCmpltw_ {
  Anum                      vertnbr;              /*+ Number of vertices +*/
  ArchCmpltwLoad * restrict velotab;              /*+ Vertex index array +*/
  Anum                      velosum;              /*+ Sum of all weights +*/
} ArchCmpltw;

/*+ The weighted domain structure. +*/

typedef struct ArchCmpltwDom_ {
  Anum                      vertmin;              /*+ Minimum vertex number +*/
  Anum                      vertnbr;              /*+ Number of vertices    +*/
  Anum                      veloval;              /*+ Weight of subdomain   +*/
} ArchCmpltwDom;

/*
**  The function prototypes.
*/

#ifndef ARCH_CMPLTW
#define static
#endif

int                         archCmpltwArchBuild (ArchCmpltw * restrict const archptr, const Gnum, const Gnum * restrict const);
int                         archCmpltwArchLoad  (ArchCmpltw * restrict const, FILE * restrict const);
int                         archCmpltwArchSave  (const ArchCmpltw * const, FILE * restrict const);
int                         archCmpltwArchFree  (ArchCmpltw * restrict const);
ArchDomNum                  archCmpltwDomNum    (const ArchCmpltw * const, const ArchCmpltwDom * const);
int                         archCmpltwDomTerm   (const ArchCmpltw * const, ArchCmpltwDom * restrict const, const ArchDomNum);
Anum                        archCmpltwDomSize   (const ArchCmpltw * const, const ArchCmpltwDom * const);
Anum                        archCmpltwDomWght   (const ArchCmpltw * const, const ArchCmpltwDom * const);
Anum                        archCmpltwDomDist   (const ArchCmpltw * const, const ArchCmpltwDom * const, const ArchCmpltwDom * const);
int                         archCmpltwDomFrst   (const ArchCmpltw * const, ArchCmpltwDom * const);
int                         archCmpltwDomLoad   (const ArchCmpltw * const, ArchCmpltwDom * const, FILE * const);
int                         archCmpltwDomSave   (const ArchCmpltw * const, const ArchCmpltwDom * const, FILE * const);
int                         archCmpltwDomBipart (const ArchCmpltw * const, const ArchCmpltwDom * const, ArchCmpltwDom * restrict const, ArchCmpltwDom * restrict const);
#ifdef SCOTCH_PTSCOTCH
int                         archCmpltwDomMpiType (const ArchCmpltw * const, MPI_Datatype * const);
#endif /* SCOTCH_PTSCOTCH */

#undef static