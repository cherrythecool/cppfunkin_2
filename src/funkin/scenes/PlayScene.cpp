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

		const std::string songName = "titular";
		auto songData = data::Song::parseSong(songName);

		inst = LoadMusicStream(("assets/songs/" + songName + "/Inst.ogg").c_str());
		voicesPlayer = LoadMusicStream(("assets/songs/" + songName + "/Voices-player.ogg").c_str());
		voices = LoadMusicStream(("assets/songs/" + songName + "/Voices-opponent.ogg").c_str());

		std::vector tracks = {inst, voices, voicesPlayer};

		conductor = std::make_shared<Conductor>(tracks);
		conductor->bpm = songData.bpm;

		stage = std::make_shared<objects::Stage>(songData.stage);
		scripts.push_back(stage->script);

		opponentField = std::make_shared<objects::notes::PlayField>(100.0f, 50.0f, 4, songData.speed, songData.opponentNotes, conductor);
		opponentField->setBotplay(true);
		opponentField->camera = camHUD;
		add(opponentField);


		playerField = std::make_shared<objects::notes::PlayField>(static_cast<float>(GetRenderWidth()) / 2 + 100.0f, 50.0f, 4, songData.speed, songData.playerNotes, conductor);
		playerField->camera = camHUD;
		add(playerField);

		conductor->start();

		callOnScripts("onCreatePost");
	}

	void PlayScene::update(const float delta) {
		callOnScripts("onUpdate", delta);

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

		callOnScripts("onUpdatePost", delta);
	}
}
