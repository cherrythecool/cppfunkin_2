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
    	return lua_pcall(state, 0, 0, LUA_MULTRET);
    }
} // namespace funkin::modding
