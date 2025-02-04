#pragma once
#include <chrono>
#include <queue>

namespace Chrono = std::chrono;

class Clock
{
public:

    static void Start();
    static void End();
    static float GetDeltaTime();
    static int GetFrameRate();

private:
    static Chrono::time_point<Chrono::high_resolution_clock> m_startTime;
    static Chrono::time_point<Chrono::high_resolution_clock> m_endTime;

    static int m_maxFrames;
    static std::queue<float> m_frameTimeQueue;
};

/**
 * Sets start time of clock
 */
inline void Clock::Start()
{
    m_startTime = Chrono::high_resolution_clock::now();
}

/**
 * Sets end time of clock
 */
inline void Clock::End()
{
    m_endTime = Chrono::high_resolution_clock::now();
    const Chrono::duration<double> timeDiff = m_endTime - m_startTime;

    m_frameTimeQueue.push(static_cast<float>(timeDiff.count()));

    if (m_frameTimeQueue.size() > m_maxFrames)
    {
        m_frameTimeQueue.pop();
    }
}

/**
 * Returns the delta time in seconds
 *
 * @return Delta Time
 */
inline float Clock::GetDeltaTime()
{
    return m_frameTimeQueue.back();
}

/**
 * Returns the frame rate in frames / second (Average of 5 frames)
 *
 * @return Frame Rate
 */
inline int Clock::GetFrameRate()
{
    std::queue<float> timeQueue = m_frameTimeQueue;

    double timeSum = 0;
    size_t numFrames = timeQueue.size();

    for (int i = 0; i < numFrames; ++i)
    {
        timeSum += timeQueue.front();
        timeQueue.pop();
    }

    double average = timeSum / m_maxFrames;

    return static_cast<int>(std::round(1 / average));
}
