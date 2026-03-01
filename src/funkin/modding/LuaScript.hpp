#pragma once

#include <any>
#include <string>
#include "luaaa.hpp"

namespace funkin::modding {
    class LuaScript {
        public:
			explicit LuaScript(const std::string& path);
            ~LuaScript();

    		bool call(const std::string& name, const std::vector<std::any>& args) const;
        
        private:
            lua_State* state; 
        
    };
} // namespace funkin::modding
