/**
 * \file wasmtime/poolingallocator_config.h
 *
 * Wasmtime-specific extensions to #wasm_poolingallocator_config_t.
 */

#ifndef WASMTIME_POOLINGALLOCATOR_CONFIG_H
#define WASMTIME_POOLINGALLOCATOR_CONFIG_H

#include <wasm.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t wasmtime_opt_mpk_enable_t;

enum wasmtime_opt_mpk_enable_enum { // Memory protection keys
  /// Use MPK or fail if not supported.
  WASMTIME_OPT_MPK_ENABLE,
  /// Do not use MPK.
  WASMTIME_OPT_MPK_DISABLE,
  /// Use MPK if supported by the current system; fall back to guard regions otherwise.
  WASMTIME_OPT_MPK_AUTO,
};

#define WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(ret, name, ty)                                    \
WASM_API_EXTERN ret wasmtime_poolingallocator_config_##name##_set(wasm_poolingallocator_config_t *, ty);

#ifdef WASMTIME_FEATURE_POOLING_ALLOCATOR
/**
 * \brief The maximum number of concurrent Wasm linear memories supported.
 *
 * For more information see the Rust documentation at
 * https://docs.wasmtime.dev/api/wasmtime/struct.PoolingAllocationConfig.html#method.total_memories
 */
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, total_memories, uint64_t);

/**
 * \brief The maximum byte size that any WebAssembly linear memory may grow to.
 *
 * For more information see the Rust documentation at
 * https://docs.wasmtime.dev/api/wasmtime/struct.PoolingAllocationConfig.html#method.max_memory_size
 */
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, max_memory_size, uint64_t);

/**
 * \brief  The maximum number of concurrent tables supported (default is `1000`).
 * This value has a direct impact on the amount of memory allocated by the
 *  pooling instance allocator.
 * For more information see the Rust documentation at
 * https://docs.wasmtime.dev/api/wasmtime/struct.PoolingAllocationConfig.html#method.total_table
 */
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, total_table, uint32_t);

/**
 * \brief The maximum table elements for any table defined in a module.
 *
 * For more information see the Rust documentation at
 * https://docs.wasmtime.dev/api/wasmtime/struct.PoolingAllocationConfig.html#method.table_elements
 */
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, table_elements, uint32_t);

/**
 * \brief The maximum number of execution stacks allowed for asynchronous execution.
 *
 * For more information see the Rust documentation at
 * https://docs.wasmtime.dev/api/wasmtime/struct.PoolingAllocationConfig.html#method.total_stacks
 */
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, total_stacks, uint32_t);

#  ifdef WASMTIME_FEATURE_MEMORY_PROTECTION_KEYS
/**
 * \brief Configures whether memory protection keys (MPK) should be used for more
 * efficient layout of pool-allocated memories.
 *
 * For more information see the Rust documentation at
 https://docs.wasmtime.dev/api/wasmtime/struct.PoolingAllocationConfig.html#method.memory_protection_keys
*/
WASMTIME_POOLINGALLOCATOR_CONFIG_PROP(void, memory_protection_keys, wasmtime_opt_mpk_enable_t);
#  endif
#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif // WASMTIME_POOLING_CONFIG_H
