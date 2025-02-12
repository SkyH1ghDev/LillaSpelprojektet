#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>

// Define an enum for the card 
enum class CardType {
    Shotgun,
    Shield
};

#include "ICardActivated.hpp"
#include "ICardAvailability.hpp"
#include "ICardVisible.hpp"

class Card : public IGameObject
{
public:
    Card() = default;
    ~Card() override = default;
    Card(const Card& other) = default;
    Card& operator=(const Card& other) = default;
    Card(Card&& other) noexcept = default;
    Card& operator=(Card&& other) noexcept = default;

    Card(CardType cardtype);
    void Update() override;
    void OnStart() override;

    void PerformVisible() { if (m_visible) m_visible->Visible(this->m_textureName, CardState::stateOne, m_layerFloat, m_scaleFloat); }
    void PerformAvailable() { if (m_available) m_available->Available(); }
    void PerformActivated(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) { if (m_activated) m_activated->Activate(position, direction); }

private:
    std::shared_ptr<ICardAvailability> m_available;
    std::shared_ptr<ICardActivated> m_activated;
    std::shared_ptr<ICardVisible> m_visible;

    CardType m_type;
};
