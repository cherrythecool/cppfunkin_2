
#include "WasmSandbox.hpp"

#include <iostream>
#include <ostream>
#include "bh_read_file.h"

namespace funkin::modding {

	void modded_println(wasm_exec_env_t exec_env, char* string_ptr) {
		std::cout << string_ptr << std::endl;
	}

	WasmSandbox::WasmSandbox(const std::string& path) {
		wasm_runtime_init();
		buffer = bh_read_file_to_buffer(path.c_str(), &size);
		NativeSymbol native_symbols[] = {
			{
				"modded_println",
				(void*)modded_println,
				"($)"
			}
		};
		wasm_runtime_register_natives("env", native_symbols, std::size(native_symbols));

		module = wasm_runtime_load(reinterpret_cast<uint8_t *>(buffer), size, error_buf, sizeof(error_buf));

		module_inst = wasm_runtime_instantiate(module, stack_size, heap_size, error_buf, sizeof(error_buf));

		entrypoint = wasm_runtime_lookup_function(module_inst, "main");

		/* creat an execution environment to execute the WASM functions */
		exec_env = wasm_runtime_create_exec_env(module_inst, stack_size);

		uint32 argv[2];

		/* arguments are always transferred in 32-bit element */
		argv[0] = 8;

		if (wasm_runtime_call_wasm(exec_env, entrypoint, std::size(argv), argv) ) {
			std::cout << "function called successfully!" << std::endl;
		}
		else {
			std::cerr << "error on function call: " << wasm_runtime_get_exception(module_inst) << std::endl;
		}
	}
} // namespace funkin::modding
