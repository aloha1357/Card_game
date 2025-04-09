// Poker.cpp
#include "Poker.h"
#include "../player/AIPlayer.h"
#include "../player/HumanPlayer.h"
#include "PokerDeck.h"
#include <algorithm>
#include <iostream>

Poker::Poker() : currentRound(0) {}

void Poker::setupPlayers() {
  int numHuman, numAI;
  std::cout << "How many human players for Poker? ";
  std::cin >> numHuman;
  std::cout << "How many AI players for Poker? ";
  std::cin >> numAI;

  for (int i = 0; i < numHuman; i++) {
    players.push_back(new HumanPlayer());
  }
  for (int i = 0; i < numAI; i++) {
    players.push_back(new AIPlayer());
  }
}

void Poker::setupDeck() { deck = new PokerDeck(); }

int Poker::initialCardCount() const { return 13; }

bool Poker::isGameOver() {
  // // Debug: 看看現在玩家狀況或回合數
  // std::cout << "[DEBUG] Checking if game is over...\n";

  // // 以 Uno 為例:
  // for (auto p : players) {
  //   std::cout << "  " << p->getName() << " hasCards= " << p->hasCards()
  //             << " (hand size= " << p->getHand().size() << ")\n";

  //   if (!p->hasCards()) {
  //     std::cout << "[DEBUG] => " << p->getName()
  //               << " has 0 cards => game over!\n";
  //     return true;
  //   }
  // }
  // std::cout << "[DEBUG] => Not over yet.\n";

  return (currentRound >= MAX_ROUNDS);
}

void Poker::onGameEnd() {
  IPlayer *champion = nullptr;
  int maxPts = -1;
  for (auto p : players) {
    if (p->getPoints() > maxPts) {
      maxPts = p->getPoints();
      champion = p;
    }
  }
  if (champion) {
    std::cout << "[Poker] Winner: " << champion->getName() << " with "
              << champion->getPoints() << " points!\n";
  }
}

bool Poker::compareCards(ICard *a, ICard *b) {
  // 先比 rank, 再比 suit
  static std::vector<std::string> rankOrder = {
      "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  static std::vector<std::string> suitOrder = {"Club", "Diamond", "Heart",
                                               "Spade"};

  auto ra = std::find(rankOrder.begin(), rankOrder.end(), a->getRank());
  auto rb = std::find(rankOrder.begin(), rankOrder.end(), b->getRank());
  if (ra != rb) {
    return (ra > rb);
  } else {
    auto sa = std::find(suitOrder.begin(), suitOrder.end(), a->getSuit());
    auto sb = std::find(suitOrder.begin(), suitOrder.end(), b->getSuit());
    return (sa > sb);
  }
}

void Poker::determineRoundWinner() {
  IPlayer *winner = nullptr;
  ICard *best = nullptr;
  for (auto p : players) {
    ICard *c = p->getLastPlayedCard();
    if (!c)
      continue; // 如果沒出牌
    if (!best) {
      best = c;
      winner = p;
    } else {
      if (compareCards(c, best)) {
        best = c;
        winner = p;
      }
    }
  }
  if (winner) {
    winner->addPoint();
    std::cout << "[Poker] Round winner: " << winner->getName() << "\n";
  }
  currentRound++;
}

bool Poker::isValidPlay(IPlayer * /*player*/, ICard * /*card*/) {
  // Poker 都合法
  return true;
}

void Poker::onValidPlay(IPlayer * /*player*/, ICard * /*card*/) {
  // 不用即時加分，等 determineRoundWinner() 再計分
}
