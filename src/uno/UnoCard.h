#pragma once
#include "../abstract/AbstractCard.h"

class UnoCard : public AbstractCard {
public:
  UnoCard(const std::string &c, const std::string &n) : AbstractCard(c, n) {}
};
