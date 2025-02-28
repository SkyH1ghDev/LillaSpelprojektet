#pragma once
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class Pause : public IObserver
{
public:
    Pause() = default;
    ~Pause() override = default;
    Pause(const Pause& other) = default;
    Pause& operator=(const Pause& other) = default;
    Pause(Pause&& other) noexcept = default;
    Pause& operator=(Pause&& other) noexcept = default;

    bool GetPause() const;
    void Update(std::optional<std::any> data) override;

protected:
    bool m_pause;

};

//Returns if true if attack key is pressed, false if not
inline bool Pause::GetPause() const
{
    return this->m_pause;
}

//Update bool for pause key
inline void Pause::Update(std::optional<std::any> data)
{
    float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    if (scale == 1)
        this->m_pause = true;
    else
        this->m_pause = false;
}
