#pragma once

#include <any>
#include <string>
#define LUA_VERSION_NUM 505
#include "sol/sol.hpp"

namespace funkin::modding {
    class LuaScript {
        public:
			explicit LuaScript(const std::string& path);
            ~LuaScript();

    		bool call(const std::string& name, const std::vector<std::any>& args) const; // NOLINT(*-use-nodiscard)
        
        private:
            sol::state state; 
        
    };
} // namespace funkin::modding
