// PokerDeck.cpp
#include "PokerDeck.h"
#include "PokerCard.h"
#include <iostream>

PokerDeck::PokerDeck() {

  generateDeck(); // <-- 這裡真正呼叫產生 52 張牌

}
void PokerDeck::generateDeck() {
  static std::string suits[] = {"Club", "Diamond", "Heart", "Spade"};
  static std::string ranks[] = {"2", "3",  "4", "5", "6", "7", "8",
                                "9", "10", "J", "Q", "K", "A"};
  for (auto &s : suits) {
    for (auto &r : ranks) {
      cards.push_back(new PokerCard(s, r));
    }
  }
}
