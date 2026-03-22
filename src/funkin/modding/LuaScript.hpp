#pragma once

#include <string>
#define LUA_VERSION_NUM 505
#include "sol/sol.hpp"

namespace funkin::modding {
    class LuaScript {
        public:
    		explicit LuaScript(const std::string& path);
    	~LuaScript();

    		template<typename... Args>
    		void call(const std::string& name, Args... args) {
				if (sol::optional<sol::function> func = state[name]) {
    				func->operator()(args...);
    			}
    		}

    		template<typename T>
    		void set(std::string name, T value) {
    			state[name] = value;
    		}

        
        private:
            sol::state state; 
        
    };
} // namespace funkin::modding
