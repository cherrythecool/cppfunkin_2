#include "LuaScript.hpp"

#include "Game.hpp"
#include "Sprite.hpp"

namespace funkin::modding
{
    LuaScript::LuaScript(const std::string& path){
        state = luaL_newstate();
        luaL_openlibs(state);
		luaaa::LuaClass<Sprite> luaSprite(state, "Sprite");
		luaSprite.ctor<float, float>();
		luaSprite.fun("loadTexture", &Sprite::loadTexture);
		luaSprite.fun("draw", &Sprite::draw);
		luaSprite.fun("update", &Sprite::update);
		luaaa::LuaModule(state).fun("add", &Game::add);
        luaL_dofile(state, path.c_str());
    }

    LuaScript::~LuaScript(){
        lua_close(state);
    }

	bool LuaScript::call(const std::string& name, const std::vector<std::any>& args) const {
    	lua_getglobal(state, name.c_str());
    	for (const auto& arg : args) {
    		if (arg.type() == typeid(std::nullptr_t)) {
				lua_pushnil(state);
    		}
    		else if (arg.type() == typeid(LUA_INTEGER)) {
    			lua_pushinteger(state, std::any_cast<LUA_INTEGER>(arg));
    		}
    		else if (arg.type() == typeid(LUA_NUMBER)) {
    			lua_pushnumber(state, std::any_cast<LUA_NUMBER>(arg));
    		}
    		else if (arg.type() == typeid(bool)) {
    			lua_pushboolean(state, std::any_cast<bool>(arg));
    		}
    		else if (arg.type() == typeid(std::string)) {
    			lua_pushstring(state, std::any_cast<std::string>(arg).c_str());
    		}
    	}
		const auto result = lua_pcall(state, args.size(), 1, 0);
    	lua_pop(state, 1);
    	return result == LUA_OK;
    }
} // namespace funkin::modding
