#pragma once

#include <any>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace funkin::data {
	typedef struct NoteData {
		float time;
		uint8_t lane;
		float length;
		bool player;
	} NoteData;

	typedef struct EventData {
		float time;
		std::string name;
		std::unordered_map<std::string, std::any> parameters;
	} EventData;

	typedef struct SongData {
		std::vector<NoteData> playerNotes;
		std::vector<NoteData> opponentNotes;
		std::vector<EventData> events;
		float speed;
		float bpm;
		std::string stage;
		std::string player;
		std::string opponent;
	} SongData;


	class Song {
	public:
		static SongData parseSong(const std::string &songName);
		static SongData parseVSlice(const std::string &songName);
		static SongData parseLegacy(const std::string &songName);

	};
}