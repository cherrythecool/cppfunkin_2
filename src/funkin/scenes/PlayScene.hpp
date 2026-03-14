#pragma once

#include "Character.hpp"
#include "Conductor.hpp"
#include "LuaScript.hpp"
#include "Scene.hpp"
#include "Stage.hpp"

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

		Music inst = {};
		Music voices = {};
		Music voicesPlayer = {};

	protected:
		void create() override;

		void update(float delta) override;
	};
}