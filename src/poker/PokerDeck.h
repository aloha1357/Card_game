#pragma once
#include "../abstract/AbstractDeck.h"

class PokerDeck : public AbstractDeck {
public:
  PokerDeck(); // 主動宣告一個建構子
protected:
  void generateDeck() override;
};
