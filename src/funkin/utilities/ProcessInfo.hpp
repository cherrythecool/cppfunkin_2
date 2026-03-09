#pragma once

#include <cstddef>


namespace funkin::utilities{
    class ProcessInfo
    {
        public:
            static std::size_t getMemoryUsage();
            static std::size_t getMemoryPeak();
    };
    
}