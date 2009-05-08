/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2009  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef IGRAPH_PSUMTREE_H
#define IGRAPH_PSUMTREE_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include "igraph_vector.h"

__BEGIN_DECLS

typedef struct {
  igraph_vector_t v;
  long int size;
  long int offset;
} igraph_psumtree_t;
int igraph_psumtree_init(igraph_psumtree_t *t, long int size);
void igraph_psumtree_destroy(igraph_psumtree_t *t);
igraph_real_t igraph_psumtree_get(const igraph_psumtree_t *t, long int idx);
long int igraph_psumtree_size(const igraph_psumtree_t *t);
int igraph_psumtree_search(const igraph_psumtree_t *t, long int *idx,
			   igraph_real_t elem);
int igraph_psumtree_update(igraph_psumtree_t *t, long int idx, 
			   igraph_real_t new_value);
igraph_real_t igraph_psumtree_sum(const igraph_psumtree_t *t);

__END_DECLS

#endif
