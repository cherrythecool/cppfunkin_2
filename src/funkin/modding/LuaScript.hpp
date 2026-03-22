#pragma once

#include <string>
#define LUA_VERSION_NUM 505
#include "sol/sol.hpp"

namespace funkin::modding {
    class LuaScript {
        public:
			explicit LuaScript(const std::string& path);
            ~LuaScript();

    		bool call(const std::string& name) const; // NOLINT(*-use-nodiscard)

    		template<typename T>
    		void set(std::string name, T value) {
    			state[name] = value;
			}

        
        private:
            sol::state state; 
        
    };
} // namespace funkin::modding
