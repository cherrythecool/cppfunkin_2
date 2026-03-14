
#pragma once
#include "LuaScript.hpp"
#include "Sprite.hpp"

namespace funkin::objects {

	enum CharacterType {
		BOYFRIEND,
		DAD,
		GIRLFRIEND
	};

	class Character : public Sprite {
		public:
			Character(float x, float y, const std::string& characterName, CharacterType type);
			~Character() override;

			CharacterType type;
			std::string characterName;

			std::shared_ptr<modding::LuaScript> script = nullptr;
	};

} // namespace funkin::objects
