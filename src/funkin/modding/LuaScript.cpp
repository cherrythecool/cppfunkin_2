#include "LuaScript.hpp"

#include "Game.hpp"
#include "Sprite.hpp"
#include "Stage.hpp"
#include "notes/PlayField.hpp"

namespace funkin::modding
{
    LuaScript::LuaScript(const std::string& path){
        state.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math);

    	state["add"] = sol::overload(&Game::add<Sprite>, &Game::add<objects::notes::PlayField>);
    	state["parseSong"] = &data::Song::parseSong;

		state.new_usertype<Game>("Game",
			"defaultCamera", sol::var(std::ref(Game::defaultCamera))
		);


    	sol::usertype<objects::Stage> lua_Stage = state.new_usertype<objects::Stage>("Stage",
    		sol::constructors<objects::Stage(std::string)>(),
			"stageName", &objects::Stage::stageName
		);

    	lua_Stage["add"] = &objects::Stage::add;

    	state.new_usertype<Camera>("Camera",
			sol::constructors<Camera()>(),
			"zoom", &Camera::zoom,
			"angle", &Camera::angle,
			"target", &Camera::target,
			"position", &Camera::position
		);


    	sol::usertype<Sprite> lua_Sprite = state.new_usertype<Sprite>("Sprite", sol::constructors<Sprite(), Sprite(float), Sprite(float, float)>());
    	lua_Sprite["loadTexture"] = &Sprite::loadTexture;

    	sol::usertype<data::Song> lua_Song = state.new_usertype<data::Song>("Song");
    	lua_Song["parseSong"] = &data::Song::parseSong;


    	state.new_usertype<data::SongData>("SongData",
			sol::constructors<data::SongData()>(),
			"speed", &data::SongData::speed,
			"bpm", &data::SongData::bpm,
			"playerNotes", &data::SongData::playerNotes,
			"opponentNotes", &data::SongData::opponentNotes
		);

    	state.new_usertype<Vector2>("Vector2",
			sol::constructors<Vector2()>(),
			"x", &Vector2::x,
			"y", &Vector2::y
		);

    	sol::usertype<objects::notes::PlayField> lua_PlayField = state.new_usertype<objects::notes::PlayField>(
    		"PlayField",
    		sol::constructors<objects::notes::PlayField(),
    		objects::notes::PlayField(float),
    		objects::notes::PlayField(float, float),
    		objects::notes::PlayField(float, float, std::uint8_t),
    		objects::notes::PlayField(float, float, std::uint8_t, float),
    		objects::notes::PlayField(float, float, std::uint8_t, float, std::vector<data::NoteData>),
    		objects::notes::PlayField(float, float, std::uint8_t, float, std::vector<data::NoteData>, std::shared_ptr<game::Conductor>)
    		>());
    	lua_PlayField["botplay"] = sol::property(&objects::notes::PlayField::getBotplay, &objects::notes::PlayField::setBotplay);
    	lua_PlayField["camera"] = sol::property(&objects::notes::PlayField::camera);
    	lua_PlayField["position"] = sol::property(&objects::notes::PlayField::position);


		state.script_file(path);
		call("onCreate");
    }

    LuaScript::~LuaScript() {
		call("onDestroy");
    }
} // namespace funkin::modding
