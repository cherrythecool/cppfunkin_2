
#pragma once

#include <string>
#include "wasm_export.h"

namespace funkin::modding {
	class WasmSandbox {
		public:
			explicit WasmSandbox(const std::string& path);
		private:
			char *buffer, error_buf[128]{};
			wasm_module_t module;
			wasm_module_inst_t module_inst;
			wasm_function_inst_t entrypoint;
			wasm_exec_env_t exec_env;
			uint32_t size{}, stack_size = 8092, heap_size = 8092;
	};

} // namespace funkin::modding
