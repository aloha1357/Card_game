#include "HumanPlayer.h"
#include <iostream>
#include <limits>
#include <string>

void HumanPlayer::naming() {
  std::cout << "Enter your name: ";
  std::cin >> name;
}

// 人類玩家：顯示所有手牌，讓玩家輸入索引或 'd' 來抽牌
ICard *HumanPlayer::showHandAndPickOneOrDraw(bool canDraw) {
  if (hand.empty()) {
    std::cout << "[" << name << "] has no cards.\n";
    return nullptr;
  }

  while (true) {
    std::cout << "\n[" << name << "] Your hand:\n";
    displayHand();
    if (canDraw) {
      std::cout << "Enter card index to play, or 'd' to draw: ";
    } else {
      std::cout << "Enter card index to play: (no draw in Poker) ";
    }

    std::string input;
    std::cin >> input;

    // 不允許抽牌的遊戲 => 不能輸入 'd'
    if ((input == "d" || input == "D") && !canDraw) {
      std::cout << "[!] Invalid, this game does NOT allow draw.\n";
      continue;
    }

    if ((input == "d" || input == "D") && canDraw) {
      // 選擇抽牌
      return nullptr;
    }

    // 嘗試將輸入轉成整數
    int idx;
    try {
      idx = std::stoi(input);
    } catch (...) {
      std::cout << "Invalid input. Try again.\n";
      continue;
    }
    if (idx < 0 || idx >= (int)hand.size()) {
      std::cout << "Index out of range. Try again.\n";
      continue;
    }

    // 取出該牌
    ICard *chosen = hand[idx];
    // 從手牌移除
    hand.erase(hand.begin() + idx);

    std::cout << "[" << name << "] plays: " << chosen->getSuit() << " "
              << chosen->getRank() << "\n";
    return chosen;
  }

  // 理論上不會到這
  return nullptr;
}
