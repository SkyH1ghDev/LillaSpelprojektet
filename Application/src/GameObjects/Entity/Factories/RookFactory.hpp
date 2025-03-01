#pragma once

class RookFactory
{
public:
    RookFactory() = default;
    ~RookFactory() = default;
    RookFactory(const RookFactory& other) = default;
    RookFactory& operator=(const RookFactory& other) = default;
    RookFactory(RookFactory&& other) noexcept = default;
    RookFactory& operator=(RookFactory&& other) noexcept = default;
    
};
