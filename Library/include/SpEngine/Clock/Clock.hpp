#pragma once
#include <chrono>
#include <queue>

namespace Chrono = std::chrono;

class Clock
{
public:
    Clock() = default;

    void Start();
    void End();
    double GetDeltaTime() const;
    double GetFrameRate() const;

private:
    Chrono::time_point<Chrono::high_resolution_clock> m_startTime;
    Chrono::time_point<Chrono::high_resolution_clock> m_endTime;

    int m_maxFrames = 30;
    std::queue<double> m_frameTimeQueue;
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

    m_frameTimeQueue.push(timeDiff.count());

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
inline double Clock::GetDeltaTime() const
{
    return m_frameTimeQueue.back();
}

/**
 * Returns the frame rate in frames / second (Average of 5 frames)
 *
 * @return Frame Rate
 */
inline double Clock::GetFrameRate() const
{
    std::queue<double> timeQueue = m_frameTimeQueue;

    double timeSum = 0;
    size_t numFrames = timeQueue.size();

    for (int i = 0; i < numFrames; ++i)
    {
        timeSum += timeQueue.front();
        timeQueue.pop();
    }

    double average = timeSum / m_maxFrames;

    double frameTime = std::round(1 / average);

    return std::round(1 / average);
}
