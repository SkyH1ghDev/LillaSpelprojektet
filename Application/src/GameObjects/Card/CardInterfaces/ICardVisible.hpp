#pragma once
#include <string>

enum class CardState {
	stateOne,
	stateTwo
};

class ICardVisible
{
public:
	virtual void Visible(std::string& texture, CardState cardState, float& layer, float& scale) = 0;
	virtual ~ICardVisible() = default;
};