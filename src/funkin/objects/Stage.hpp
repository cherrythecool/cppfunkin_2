#pragma once

#include "Group.hpp"
#include "Sprite.hpp"

namespace funkin::objects {
    class Stage : public Group<Sprite> {
        public:
            Stage();
            ~Stage();
    };
    
} // namespace funkin::objects
