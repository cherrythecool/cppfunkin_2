#include "PlayScene.hpp"

#include <iostream>


#include "Game.hpp"
#include "Sprite.hpp"
#include "WasmSandbox.hpp"
#include "objects/notes/PlayField.hpp"

namespace funkin::scenes {
	PlayScene::PlayScene() = default;

	PlayScene::~PlayScene() {
		scripts.clear();
	};

	void PlayScene::create() {
		Scene::create();


		camHUD = std::make_shared<Camera>();
		Game::cameras.push_back(camHUD);

		Game::defaultCamera->zoom = 0.7f;

		auto script = std::make_shared<modding::LuaScript>("assets/scripts/testscript.lua");
		scripts.push_back(script);

		script->set("camHUD", camHUD);

		const std::string songName = "bonedoggle";
		auto [playerNotes, opponentNotes, speed, bpm] = data::Song::parseSong(songName);

		inst = LoadMusicStream(("assets/songs/" + songName + "/Inst.ogg").c_str());
		voicesPlayer = LoadMusicStream(("assets/songs/" + songName + "/Voices.ogg").c_str());
		voices = LoadMusicStream(("assets/songs/" + songName + "/Voices-opponent.ogg").c_str());

		std::vector tracks = {inst, voices, voicesPlayer};

		conductor = std::make_shared<Conductor>(tracks);
		conductor->bpm = bpm;
		conductor->start();

		script->set("conductor", conductor);

		opponentField = std::make_shared<objects::notes::PlayField>(100.0f, 50.0f, 4, speed, opponentNotes,conductor);
		for (const auto& lane : opponentField->members) {
			lane->botplay = true;
		}
		opponentField->camera = camHUD;
		add(opponentField);

		script->set("opponentField", opponentField);

		playerField = std::make_shared<objects::notes::PlayField>(static_cast<float>(GetRenderWidth()) / 2 + 100.0f, 50.0f, 4, speed, playerNotes, conductor);
		playerField->camera = camHUD;
		add(playerField);

		script->set("playerField", playerField);

		for (const auto& s : scripts) {
			s->call("onCreatePost");
		}
	}

	void PlayScene::update(const float delta) {
		for (const auto& s : scripts) {
			s->call("onUpdate", delta);
		}
		Scene::update(delta);
		conductor->update(delta);
		if (IsKeyPressed(KEY_SPACE)) {
			if (conductor->playing) {
				conductor->pause();
			}
			else {
				conductor->resume();
			}
		}
		for (const auto& s : scripts) {
			s->call("onUpdatePost", delta);
		}
	}
}
