#pragma once

#include "Character.hpp"
#include "Conductor.hpp"
#include "LuaScript.hpp"
#include "Scene.hpp"
#include "Stage.hpp"
#include "notes/PlayField.hpp"

namespace funkin::scenes {
	using namespace game;

	class PlayScene : public Scene {
	public:
		PlayScene();

		~PlayScene() override;

		std::shared_ptr<Conductor> conductor = nullptr;
		std::vector<std::shared_ptr<modding::LuaScript>> scripts = {};

		std::shared_ptr<Camera> camHUD = nullptr;

		std::shared_ptr<objects::Stage> stage = nullptr;

		std::shared_ptr<objects::Character> dad = nullptr;
		std::shared_ptr<objects::Character> boyfriend = nullptr;
		std::shared_ptr<objects::Character> girlfriend = nullptr;

		std::shared_ptr<objects::notes::PlayField> playerField = nullptr;
		std::shared_ptr<objects::notes::PlayField> opponentField = nullptr;

		Music inst = {};
		Music voices = {};
		Music voicesPlayer = {};

		void create() override;
		void update(float delta) override;

    	template<typename... Args>
		void callOnScripts(const std::string& name, Args... args){
			for(const auto& script : scripts){
				script->call(name, args...);
			}
		}

    	template<typename T>
		void setOnScripts(const std::string& name, T type){
			for(const auto& script : scripts){
				script->set(name, type);
			}
		}
	};
}