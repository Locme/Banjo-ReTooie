#ifndef __TOOIE_TRACE_H__
#define __TOOIE_TRACE_H__

// Included by recompiled code generated with trace_mode = true
// (tools/trace_build.sh): counts calls to every function, see src/debug/trace.cpp.

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
uint32_t* tooie_trace_slot(const char* func_name);
#ifdef __cplusplus
}
#endif

#define TRACE_ENTRY() { static uint32_t* tooie_trace_count_ = 0; \
    if (!tooie_trace_count_) tooie_trace_count_ = tooie_trace_slot(__func__); \
    __atomic_fetch_add(tooie_trace_count_, 1, __ATOMIC_RELAXED); }
#define TRACE_RETURN()

#endif
