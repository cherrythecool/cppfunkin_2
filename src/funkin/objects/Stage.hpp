#pragma once

#include "Game.hpp"
#include "Group.hpp"
#include "LuaScript.hpp"
#include "Sprite.hpp"

namespace funkin::objects {
	class Stage : public Group<Sprite> {
	public:
		explicit Stage(const std::string &stageName);
		~Stage() override;

		std::shared_ptr<modding::LuaScript> script = nullptr;
		std::string stageName;

		void add(Sprite* object) {
			Group<Sprite>::add(std::shared_ptr<Sprite>(object));
		}
	};

} // namespace funkin::objects
