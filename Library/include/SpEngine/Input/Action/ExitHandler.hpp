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

    /**
     * Updates the m_shouldExit variable to true
     *
     * @param data Nothing
     */
    void Update(std::optional<std::any> data) override;

    /**
     * Returns if application should exit
     *
     * @return True if yes, False if not
     */
    bool ShouldExit();

private:
    bool m_shouldExit = false;

};
