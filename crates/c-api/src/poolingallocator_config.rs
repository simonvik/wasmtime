
#[repr(C)]
#[derive(Clone)]
pub struct wasm_poolingallocator_config_t {
    pub(crate) config: wasmtime::PoolingAllocationConfig,
}
wasmtime_c_api_macros::declare_own!(wasm_poolingallocator_config_t);

#[repr(u8)]
#[derive(Clone)]
pub enum wasmtime_opt_mpk_enable_t {
    WASMTIME_OPT_MPK_ENABLE,
    WASMTIME_OPT_MPK_DISABLE,
    WASMTIME_OPT_MPK_AUTO,
}
#[unsafe(no_mangle)]
pub extern "C" fn wasm_poolingallocator_config_new() -> Box<wasm_poolingallocator_config_t> {
    Box::new(wasm_poolingallocator_config_t {
        config: wasmtime::PoolingAllocationConfig::default(),
    })
}

#[unsafe(no_mangle)]
pub extern "C" fn wasmtime_poolingallocator_config_total_memories_set(c: &mut wasm_poolingallocator_config_t, total: u32) {
    c.config.total_memories(total);
}

#[unsafe(no_mangle)]
pub extern "C" fn wasmtime_poolingallocator_config_max_memory_size_set(c: &mut wasm_poolingallocator_config_t, size: usize) {
    c.config.max_memory_size(size);
}

#[unsafe(no_mangle)]
pub extern "C" fn wasmtime_poolingallocator_config_total_tables_set(c: &mut wasm_poolingallocator_config_t, tables: u32) {
    c.config.total_tables(tables);
}

#[unsafe(no_mangle)]
pub extern "C" fn wasmtime_poolingallocator_config_table_elements_set(c: &mut wasm_poolingallocator_config_t, elements: usize) {
    c.config.table_elements(elements);
}

#[unsafe(no_mangle)]
pub extern "C" fn wasmtime_poolingallocator_config_total_stacks_set(c: &mut wasm_poolingallocator_config_t, stacks: u32) {
    c.config.total_stacks(stacks);
}

#[cfg(feature = "memory-protection-keys")]
#[unsafe(no_mangle)]
pub extern "C" fn wasmtime_poolingallocator_config_memory_protection_keys_set(c: &mut wasm_poolingallocator_config_t, enabled: wasmtime_opt_mpk_enable_t) {
    use wasmtime_opt_mpk_enable_t::*;
    use wasmtime::MpkEnabled;
    c.config.memory_protection_keys(match enabled {
        WASMTIME_OPT_MPK_ENABLE => MpkEnabled::Enable,
        WASMTIME_OPT_MPK_DISABLE => MpkEnabled::Disable,
        WASMTIME_OPT_MPK_AUTO => MpkEnabled::Auto,
    });
}