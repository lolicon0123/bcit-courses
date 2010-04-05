/*-----------------------------------------------------------------------------
 * forward-server.h
 * Copyright (C) 2010 Steffen L. Norgren <ironix@trollop.org>
 * 
 * forward-server.h is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * forward-server.h is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *----------------------------------------------------------------------------*/

#ifndef FORWARD_SERVER_H
#define FORWARD_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#include <getopt.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h>
#include <errno.h>
#include <err.h>
#include <stddef.h>

/* for SSL support */
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>

/* using libev instead of libevent */
#ifdef OSX
	#include <ev.h>
#elif LINUX
	#include <libev/ev.h>
#endif

/* defaults */
#define SERVER_PORT 9000 /* delete this later */
#define IO_BUFFER	8192

/* error codes */
#define ERROR_NONE	0
#define ERROR		-1

/* testing */
#define OUT_PORT	80
#define OUT_IP		"google.ca"

int setnonblock(int);
static void read_client_cb(struct ev_loop *, struct ev_io *, int);
static void read_remote_cb(struct ev_loop *, struct ev_io *, int);
static void accept_cb(struct ev_loop *, struct ev_io *, int);

struct client {
	int fd_in;		/* inbound socket */
	int fd_out;		/* outbound socket */
	ev_io ev_read;
	ev_io ev_read_out;
};

ev_io ev_accept;
/* struct client *client; */

#endif