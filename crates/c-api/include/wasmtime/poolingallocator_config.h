/**
 * \file wasmtime/poolingallocator_config.h
 *
 * Wasmtime-specific extensions to #wasm_poolingallocator_config_t.
 */

#ifndef WASMTIME_POOLINGALLICATOR_CONFIG_H
#define WASMTIME_POOLINGALLICATOR_CONFIG_H

#include <wasm.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t wasmtime_opt_mpk_enable_t;

enum wasmtime_opt_mpk_enable_enum { // OptLevel
  WASMTIME_OPT_MPK_ENABLE,
  WASMTIME_OPT_MPK_DISABLE,
  WASMTIME_OPT_MPK_AUTO,
};

#define WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(ret, name, ty)                                    \
WASM_API_EXTERN ret wasmtime_poolingallocator_config_##name##_set(wasm_poolingallocator_config_t *, ty);

#ifdef WASMTIME_FEATURE_POOLING_ALLOCATOR
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, total_memories, int);
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, max_memory_size, int);
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, total_table, int);
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, table_elements, int);
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, total_stacks, int);

#  ifdef WASMTIME_FEATURE_MEMORY_PROTECTION_KEYS
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, memory_protection_keys, wasmtime_opt_mpk_enable_t);
#  endif
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif // WASMTIME_POOLING_CONFIG_H
