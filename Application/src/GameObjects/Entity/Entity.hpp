#pragma once
#include <memory>
#include <string>
#include "IAttack.hpp"
#include "IMove.hpp"
#include "IVisible.hpp"
#include "ITakeDamage.hpp"
#include "IUseCard.hpp"
#
class Entity
{
private:
	std::unique_ptr<IMove> move;
	std::unique_ptr<IVisible> visible;
	std::unique_ptr<IAttack> attack;
	std::unique_ptr<ITakeDamage> takeDamage;
	std::unique_ptr<IUseCard> useCard;
	std::string type;

public:
	
	Entity(const std::string& entityType);

	void performMove() { if (move) move->Move(); }
	void performRender() { if (visible) visible->Visible(); }
	void performAttack() { if (attack) attack->Attack(); }
	void performTakeDamage() { if (takeDamage) takeDamage->TakeDamage(); }
	void performUseCard() { if (useCard) useCard->UseCard(); }

	std::string getType() const { return type; }

};