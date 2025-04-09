#pragma once
#include "../abstract/AbstractDeck.h"

class UnoDeck : public AbstractDeck {
public:
  UnoDeck(); // 主動宣告一個建構子

protected:
  void generateDeck() override;
};
