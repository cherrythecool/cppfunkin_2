#pragma once

#include <string>

namespace funkin::utilities
{
    class CoolUtil
    {
        public:
            static std::string formatBytes(std::size_t bytes, std::uint8_t precision = 2);
    };
    
} // namespace funkin::utilities
