#pragma once
#include "Entity.hpp"
#include "Mesh.hpp"
#include "Actions/UseCard.hpp"

#include <SpEngine/Assets/IScript.hpp>


class PlayerCardScript : public IScript
{
public:
	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<UseCard> m_useCard = std::make_shared<UseCard>();
	float m_useCardTimer = 0;
};
