// UnoDeck.cpp
#include "UnoDeck.h"
#include "UnoCard.h"

UnoDeck::UnoDeck() {
  generateDeck(); // <-- 這裡真正呼叫產生 40 張牌
}
void UnoDeck::generateDeck() {
  static std::string colors[] = {"BLUE", "RED", "YELLOW", "GREEN"};
  for (auto &c : colors) {
    for (int i = 0; i < 10; i++) {
      cards.push_back(new UnoCard(c, std::to_string(i)));
    }
  }
}
