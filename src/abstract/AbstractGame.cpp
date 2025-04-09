#include "AbstractGame.h"
#include <iostream>

AbstractGame::AbstractGame() : deck(nullptr) {}

AbstractGame::~AbstractGame() {
  for (auto p : players) {
    delete p;
  }
  delete deck;
}

void AbstractGame::start() {
  setupPlayers();
  setupDeck();
  deck->shuffle();

  // 給每個玩家命名
  for (auto p : players) {
    p->naming();
  }

  // 每人發 initialCardCount() 張牌
  for (int i = 0; i < initialCardCount(); i++) {
    for (auto p : players) {
      deck->drawCard(p);
    }
  }
}

// 關鍵：讓玩家自行選哪張牌 or 抽牌
void AbstractGame::next_turn() {
  for (auto p : players) {
    // 若沒牌 => 已經出光可跳過(UNO先出光的就贏)
    if (!p->hasCards()) {
      continue;
    }

    // 重複詢問，直到玩家出了一張「合法牌」或選擇抽牌
    while (true) {
      bool canDraw = allowDraw(); // Poker: false, Uno: true
      // 顯示手牌並讓玩家選擇一張牌或選擇抽牌
      ICard *chosen = p->showHandAndPickOneOrDraw(canDraw);
      if (!chosen) {
        // null => 表示玩家要抽牌
        deck->drawCard(p);
        p->setLastPlayedCard(nullptr);
        break; // 該玩家回合結束
      } else {
        // 試著出這張牌
        p->setLastPlayedCard(chosen);
        if (isValidPlay(p, chosen)) {
          onValidPlay(p, chosen);
          break; // 出牌完成, 結束該玩家回合
        } else {
          // 不合法 => 提示 + 將牌還回手牌
          std::cout << "[!] Invalid play for " << p->getName()
                    << ". Please pick again or draw.\n";
          p->addCard(chosen);
        }
      }
    }
  }
}

void AbstractGame::compare() { determineRoundWinner(); }

bool AbstractGame::check() { return isGameOver(); }

void AbstractGame::end_game() { onGameEnd(); }
