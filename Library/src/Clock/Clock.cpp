#include "Clock.hpp"

Chrono::time_point<Chrono::high_resolution_clock> Clock::m_startTime = {};
Chrono::time_point<Chrono::high_resolution_clock> Clock::m_endTime = {};

int Clock::m_maxFrames = 60;
std::queue<float> Clock::m_frameTimeQueue = std::queue<float>({0});
