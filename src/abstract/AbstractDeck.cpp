#include "AbstractDeck.h"
#include "../interface/IPlayer.h"

AbstractDeck::AbstractDeck() {}

void AbstractDeck::shuffle() {
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(cards.begin(), cards.end(), g);
}

void AbstractDeck::drawCard(IPlayer *player) {
  if (cards.empty())
    return;
  ICard *top = cards.back();
  cards.pop_back();
  player->addCard(top);
}

ICard *AbstractDeck::drawTopCard() {
  if (cards.empty())
    return nullptr;
  ICard *top = cards.back();
  cards.pop_back();
  return top;
}

AbstractDeck::~AbstractDeck() {
  for (auto c : cards) {
    delete c;
  }
}
