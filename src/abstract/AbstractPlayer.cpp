#include "AbstractPlayer.h"
#include <iostream>

AbstractPlayer::AbstractPlayer() : points(0), lastPlayedCard(nullptr) {}

AbstractPlayer::~AbstractPlayer() {
  for (auto c : hand) {
    delete c;
  }
}

// 預設空命名，可由 HumanPlayer 或 AIPlayer 覆寫
void AbstractPlayer::naming() {
  // do nothing
}

void AbstractPlayer::addCard(ICard *card) { hand.push_back(card); }

bool AbstractPlayer::hasCards() const { return !hand.empty(); }

const std::vector<ICard *> &AbstractPlayer::getHand() const { return hand; }

std::string AbstractPlayer::getName() const { return name; }

void AbstractPlayer::addPoint() { points++; }

int AbstractPlayer::getPoints() const { return points; }

void AbstractPlayer::setLastPlayedCard(ICard *card) { lastPlayedCard = card; }

ICard *AbstractPlayer::getLastPlayedCard() const { return lastPlayedCard; }

void AbstractPlayer::displayHand() const {
  for (size_t i = 0; i < hand.size(); i++) {
    std::cout << i << ": " << hand[i]->getSuit() << " " << hand[i]->getRank()
              << "\n";
  }
}
