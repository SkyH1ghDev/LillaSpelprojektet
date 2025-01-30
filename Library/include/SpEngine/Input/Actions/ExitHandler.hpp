#pragma once

#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

class ExitHandler : public IObserver
{
public:
    ExitHandler() = default;
    ~ExitHandler() override = default;
    ExitHandler(const ExitHandler& other) = default;
    ExitHandler& operator=(const ExitHandler& other) = default;
    ExitHandler(ExitHandler&& other) noexcept = default;
    ExitHandler& operator=(ExitHandler&& other) noexcept = default;

    void Update(std::optional<std::any> data) override;
    bool ShouldExit();

private:
    bool m_shouldExit = false;
};
