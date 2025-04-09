#include "AIPlayer.h"
#include <cstdlib>
#include <iostream>

AIPlayer::AIPlayer() { name = "AI_" + std::to_string(rand() % 1000); }

// 這裡示範一種簡單 AI：
// 70% 機率嘗試隨機出一張牌，30% 機率選擇抽牌
ICard *AIPlayer::showHandAndPickOneOrDraw(bool canDraw) {
  if (hand.empty()) {
    return nullptr; // 沒牌可出 => 回傳nullptr觸發抽牌(理論上AI也沒牌就贏了)
  }

  int r = rand() % 10;
  if (r < 3 && canDraw) {
    // 30%機率抽牌
    std::cout << "[" << name << " AI] decides to draw.\n";
    return nullptr;
  } else {
    // 70%機率出牌
    int idx = rand() % hand.size();
    ICard *chosen = hand[idx];
    hand.erase(hand.begin() + idx);

    std::cout << "[" << name << " AI] plays: " << chosen->getSuit() << " "
              << chosen->getRank() << "\n";
    return chosen;
  }
}
