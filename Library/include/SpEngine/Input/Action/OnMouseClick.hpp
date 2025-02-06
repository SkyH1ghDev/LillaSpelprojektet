#pragma once

#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

class OnMouseClick : public IObserver
{
public:
    OnMouseClick() = default;
    ~OnMouseClick() override = default;
    OnMouseClick(const OnMouseClick& other) = default;
    OnMouseClick& operator=(const OnMouseClick& other) = default;
    OnMouseClick(OnMouseClick&& other) noexcept = default;
    OnMouseClick& operator=(OnMouseClick&& other) noexcept = default;

    /**
     * Updates the m_shouldExit variable to true
     *
     * @param data Nothing
     */
    void Update(std::optional<std::any> data) override;
    /**
     * Returns if application VL_button clicked
     *
     * @return True if yes, False if not
     */
    bool VL_Click() const;

private:
    bool m_isClicked = false;

};

inline bool OnMouseClick::VL_Click() const
{
    return m_isClicked;
}