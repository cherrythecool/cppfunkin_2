#pragma once

#include <string>
#include <cstdint>


namespace funkin::utilities
{
    class CoolUtil
    {
        public:
            /**
             * @see https://gist.github.com/dgoguerra/7194777
             */
            static std::string formatBytes(std::size_t bytes, std::uint8_t precision = 2);
    };
    
} // namespace funkin::utilities
