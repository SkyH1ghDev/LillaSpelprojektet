#pragma once
class IMove
{
public:
	virtual void Move() = 0;
	virtual ~IMove() = default;
};