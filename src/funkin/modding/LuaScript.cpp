#include "LuaScript.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "notes/PlayField.hpp"

namespace funkin::modding
{
    LuaScript::LuaScript(const std::string& path){
        state.open_libraries(sol::lib::base, sol::lib::package);

    	sol::usertype<Sprite> lua_Sprite = state.new_usertype<Sprite>("Sprite", sol::constructors<Sprite(), Sprite(float), Sprite(float, float)>());
    	lua_Sprite["loadTexture"] = &Sprite::loadTexture;
    	state["add"] = sol::overload(&Game::add<Sprite>, &Game::add<objects::notes::PlayField>);

    	sol::usertype<objects::notes::PlayField> lua_PlayField = state.new_usertype<objects::notes::PlayField>("PlayField", sol::constructors<objects::notes::PlayField(), objects::notes::PlayField(float), objects::notes::PlayField(float, float)>());


		state.script_file(path);
		// ReSharper disable once CppExpressionWithoutSideEffects
		call("onCreate", {});
    }

    LuaScript::~LuaScript() {
		// ReSharper disable once CppExpressionWithoutSideEffects
		call("onDestroy", {});
        lua_close(state);
    }

	bool LuaScript::call(const std::string& name, const std::vector<std::any>& args) const {
    	return true;
    }
} // namespace funkin::modding
