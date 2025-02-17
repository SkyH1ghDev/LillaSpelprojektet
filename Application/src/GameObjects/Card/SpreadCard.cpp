#include "Card.hpp"
#include "AbilityManager.hpp"
#include <iostream>



void SpreadCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
	AbilityManager::SurroundShot(position, 10, 5, 100);
}

void SpreadCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
	AbilityManager::SurroundShot(position, 20, 6, 150);
}

void SpreadCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
	AbilityManager::SurroundShot(position, 30, 7, 200);
}