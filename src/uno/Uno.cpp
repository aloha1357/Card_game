// Uno.cpp
#include "Uno.h"
#include "../player/AIPlayer.h"
#include "../player/HumanPlayer.h"
#include "UnoDeck.h"
#include <iostream>

Uno::Uno() : topCard(nullptr) {}

void Uno::setupPlayers() {
  int numHuman, numAI;
  std::cout << "How many human players for UNO? ";
  std::cin >> numHuman;
  std::cout << "How many AI players for UNO? ";
  std::cin >> numAI;
  for (int i = 0; i < numHuman; i++) {
    players.push_back(new HumanPlayer());
  }
  for (int i = 0; i < numAI; i++) {
    players.push_back(new AIPlayer());
  }
}

void Uno::setupDeck() { deck = new UnoDeck(); }

int Uno::initialCardCount() const { return 5; }

bool Uno::isGameOver() {
  // 有人沒牌 => 結束
  for (auto p : players) {
    if (!p->hasCards()) {
      return true;
    }
  }
  return false;
}

void Uno::onGameEnd() {
  // 找出誰先沒牌
  for (auto p : players) {
    if (!p->hasCards()) {
      std::cout << "[UNO] Winner: " << p->getName() << "\n";
      return;
    }
  }
}

void Uno::determineRoundWinner() {
  // UNO不需要每回合決定勝者
}

bool Uno::isValidPlay(IPlayer * /*player*/, ICard *card) {
  if (!topCard) {
    return true;
  }
  return (card->getSuit() == topCard->getSuit()) ||
         (card->getRank() == topCard->getRank());
}

void Uno::onValidPlay(IPlayer * /*player*/, ICard *card) { topCard = card; }

void Uno::start() {
  AbstractGame::start();
  // 翻第一張到檯面
  topCard = deck->drawTopCard();
  if (topCard) {
    std::cout << "[UNO] Starting top card: " << topCard->getSuit() << " "
              << topCard->getRank() << "\n";
  }
}
