#ifndef __BENCH_H__
#define __BENCH_H__
#include <stdio.h>
#include <sys/time.h>

#ifdef TIMER
float _cmark_start_time;
float _cmark_end_time;

#define start_timer() \
	_cmark_start_time = (float)clock()/CLOCKS_PER_SEC

#define end_timer(M) \
	_cmark_end_time = (float)clock()/CLOCKS_PER_SEC; \
	fprintf(stderr, "[TIME] (%s:%d) %8.f ns " M "\n", __FILE__, \
		__LINE__, (_cmark_end_time - _cmark_start_time) * 1000000)

#else
#define start_timer()
#define end_timer(M)
#endif
#endif
