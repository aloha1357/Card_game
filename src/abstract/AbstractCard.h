#pragma once
#include "../interface/ICard.h"
#include <string>

class AbstractCard : public ICard {
protected:
    std::string suit;
    std::string rank;
public:
    AbstractCard(const std::string& s, const std::string& r)
        : suit(s), rank(r) {}
    std::string getSuit() const override { return suit; }
    std::string getRank() const override { return rank; }
    virtual ~AbstractCard() {}
};
