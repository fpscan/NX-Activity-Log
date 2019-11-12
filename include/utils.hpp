#ifndef UTILS_H
#define UTILS_H

#include <ctime>
#include <map>
#include <SDL2/SDL.h>
#include <switch.h>

namespace Utils {
    // Map from HidControllerKeys -> int
    #define KEY_MAP_SIZE 28
    extern std::map<HidControllerKeys, int> key_map;

    // Nicely format a time (from zero)
    std::string formatPlaytime(u32);

    // Returns a string with the difference between the two timestamps
    std::string formatTimestamps(std::time_t, std::time_t);

    // Struct representing a "clock", which represents time between ticks
    struct Clock {
        uint32_t last_tick = 0;
        uint32_t delta = 0;

        void tick() {
            uint32_t tick = SDL_GetTicks();
            delta = tick - last_tick;
            last_tick = tick;
        }
    };
};

#endif