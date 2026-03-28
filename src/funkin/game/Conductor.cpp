#include "Conductor.hpp"

#include <iostream>

namespace funkin::game {
	Conductor::Conductor(const std::vector<Music> &tracks) {
		this->tracks = tracks;
	}

	Conductor::~Conductor() {
		stop();
		tracks.clear();
	}

	void Conductor::start() {
		if (tracks.empty()) {
			return;
		}
		for (const auto track: tracks) {
			PlayMusicStream(track);
		}
		playing = true;
		update(0.0f);
	}

	void Conductor::stop() {
		if (tracks.empty()) {
			return;
		}
		for (const auto track: tracks) {
			StopMusicStream(track);
		}
		playing = false;
	}

	void Conductor::pause() {
		if (tracks.empty()) {
			return;
		}
		for (const auto track: tracks) {
			PauseMusicStream(track);
		}
		playing = false;
	}

	void Conductor::resume() {
		if (tracks.empty()) {
			return;
		}
		for (const auto track: tracks) {
			ResumeMusicStream(track);
		}
		playing = true;
	}

	void Conductor::update(const float delta) {
		if (tracks.empty() || !playing) {
			return;
		}

		for (const auto track: tracks) {
			UpdateMusicStream(track);
		}

		const auto track = tracks.front();

		if (const float _time = GetMusicTimePlayed(track); lastMixPos != _time) {
			lastMixPos = _time;
			lastMixTimer = 0.0f;
		} else {
			lastMixTimer += delta;
		}
		time = (lastMixPos + lastMixTimer) * 1000.0f;

		crochet = 60.0f / bpm * 1000.0f;
		stepCrochet = crochet / 4.0f;

		const int oldStep = step;
		const int oldBeat = beat;

		updateStep();
		updateBeat();

		if (oldStep != step) {
			stepHit();
		}

		if (oldBeat != beat) {
			beatHit();
		}
	}

	void Conductor::updateStep() {
		const int potentialNewStep = static_cast<int>(time / stepCrochet);
		if (potentialNewStep != step) {
			step = potentialNewStep;
		}
	}

	void Conductor::updateBeat() {
		const int potentialNewBeat = static_cast<int>(time / crochet);
		if (potentialNewBeat != beat) {
			beat = potentialNewBeat;
		}
	}

	void Conductor::stepHit() const {
		onStepHit(step);
	}

	void Conductor::beatHit() const {
		onBeatHit(beat);
	}
}