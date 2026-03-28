#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace funkin::data {
	typedef struct NoteData {
		float time;
		uint8_t lane;
		float length;
		bool player;
	} NoteData;

	typedef struct SongData {
		std::vector<NoteData> playerNotes;
		std::vector<NoteData> opponentNotes;
		float speed;
		float bpm;
		std::string stage;
		std::string player;
	} SongData;

	class Song {
	public:
		static SongData parseSong(const std::string &songName);
		static SongData parseVSlice(const std::string &songName);
		static SongData parseLegacy(const std::string &songName);

	};
}