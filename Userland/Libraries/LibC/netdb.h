/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

struct hostent {
    char* h_name;
    char** h_aliases;
    int h_addrtype;
    int h_length;
    char** h_addr_list;
#define h_addr h_addr_list[0]
};

struct hostent* gethostbyname(const char*);
struct hostent* gethostbyaddr(const void* addr, socklen_t len, int type);

struct servent {
    char* s_name;
    char** s_aliases;
    int s_port;
    char* s_proto;
};

struct servent* getservent(void);
struct servent* getservbyname(const char* name, const char* protocol);
struct servent* getservbyport(int port, const char* protocol);
void setservent(int stay_open);
void endservent(void);

struct protoent {
    char* p_name;
    char** p_aliases;
    int p_proto;
};

void endprotoent(void);
struct protoent* getprotobyname(const char* name);
struct protoent* getprotobynumber(int proto);
struct protoent* getprotoent(void);
void setprotoent(int stay_open);

extern int h_errno;

#define HOST_NOT_FOUND 101
#define NO_DATA 102
#define NO_RECOVERY 103
#define TRY_AGAIN 104

struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    socklen_t ai_addrlen;
    struct sockaddr* ai_addr;
    char* ai_canonname;
    struct addrinfo* ai_next;
};

#define EAI_ADDRFAMILY 1
#define EAI_AGAIN 2
#define EAI_BADFLAGS 3
#define EAI_FAIL 4
#define EAI_FAMILY 5
#define EAI_MEMORY 6
#define EAI_NODATA 7
#define EAI_NONAME 8
#define EAI_SERVICE 9
#define EAI_SOCKTYPE 10
#define EAI_SYSTEM 11
#define EAI_OVERFLOW 12

#define AI_PASSIVE 0x0001
#define AI_CANONNAME 0x0002
#define AI_NUMERICHOST 0x0004
#define AI_NUMERICSERV 0x0008
#define AI_V4MAPPED 0x0010
#define AI_ALL 0x0020
#define AI_ADDRCONFIG 0x0040

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

#define NI_NUMERICHOST 1
#define NI_NUMERICSERV 2
#define NI_NAMEREQD 3
#define NI_NOFQDN 4
#define NI_DGRAM 5

int getaddrinfo(const char* __restrict node, const char* __restrict service, const struct addrinfo* __restrict hints, struct addrinfo** __restrict res);
void freeaddrinfo(struct addrinfo* res);
const char* gai_strerror(int errcode);
int getnameinfo(const struct sockaddr* __restrict addr, socklen_t addrlen, char* __restrict host, socklen_t hostlen, char* __restrict serv, socklen_t servlen, int flags);

__END_DECLS
