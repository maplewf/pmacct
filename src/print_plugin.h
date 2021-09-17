/*
    pmacct (Promiscuous mode IP Accounting package)
    pmacct is Copyright (C) 2003-2019 by Paolo Lucente
*/

/*
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
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef PRINT_PLUGIN_H
#define PRINT_PLUGIN_H

/* includes */
#include <sys/poll.h>

/* structures */

#if defined(WITH_JANSSON) && defined(WITH_ZMQ)
struct pt_zmq_sock {
  void *obj;
  char str[SHORTBUFLEN];
};

struct pt_zmq_host {
  void *ctx;
  char log_id[SHORTBUFLEN];
  struct pt_zmq_sock sock;
  struct pt_zmq_sock sock_inproc;
  char topic[SHORTBUFLEN];
  int hwm;
  void * m_sock;
};
#endif

/* prototypes */
extern void print_plugin(int, struct configuration *, void *);
extern void P_cache_purge(struct chained_cache *[], int, int);
extern void P_write_stats_header_formatted(FILE *, int);
extern void P_write_stats_header_csv(FILE *, int);
extern void P_fprintf_csv_string(FILE *, struct pkt_vlen_hdr_primitives *, pm_cfgreg_t, char *, char *);

/* global variables */
extern int print_output_stdout_header;
#if defined(WITH_JANSSON) && defined(WITH_ZMQ)
extern struct pt_zmq_host print_output_zmq_host;
extern char *pt_buf;
#endif

#endif //PRINT_PLUGIN_H
