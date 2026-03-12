#pragma once

#include "Group.hpp"
#include "Sprite.hpp"
#include "LuaScript.hpp"

namespace funkin::objects {
    class Stage : public Group<Sprite> {
        public:
            Stage();
            ~Stage();

            std::shared_ptr<modding::LuaScript> script = nullptr;
    };
    
} // namespace funkin::objects
