#pragma once

#include <cstdint>
#include <random>

class SpMath {
public:
    SpMath() = delete;
    ~SpMath() = delete;
    SpMath(const SpMath& other) = delete;
    SpMath& operator=(const SpMath& other) = delete;
    SpMath(SpMath&& other) noexcept = delete;
    SpMath& operator=(SpMath&& other) noexcept = delete;

    template <typename T>
    constexpr static T RandomReal(const T& min, const T& max)
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_real_distribution<T> dis(min, max);
        return dis(gen);
    }

    template <typename T>
    constexpr static T RandomInteger(const T& min, const T& max)
    {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_int_distribution<T> dis(min, max);
        return dis(gen);
    }
};