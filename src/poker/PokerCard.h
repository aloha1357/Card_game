#pragma once
#include "../abstract/AbstractCard.h"

class PokerCard : public AbstractCard {
public:
  PokerCard(const std::string &s, const std::string &r) : AbstractCard(s, r) {}
};
