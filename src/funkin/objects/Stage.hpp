#pragma once

#include "Group.hpp"
#include "Sprite.hpp"
#include "LuaScript.hpp"

namespace funkin::objects {
    class Stage : public Group<Sprite> {
        public:
			explicit Stage(const std::string& stageName);
            ~Stage() override;

            std::shared_ptr<modding::LuaScript> script = nullptr;
    		std::string stageName;
    };
    
} // namespace funkin::objects
