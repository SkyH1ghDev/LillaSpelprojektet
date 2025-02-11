#pragma once



class ICardAvailability
{
public:
    virtual void Available() = 0;
    virtual ~ICardAvailability() = default;
};
