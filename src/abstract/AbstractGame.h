#pragma once
#include "../interface/IDeck.h"
#include "../interface/IGame.h"
#include "../interface/IPlayer.h"
#include <vector>

class AbstractGame : public IGame {
protected:
  std::vector<IPlayer *> players;
  IDeck *deck;

  // 子類別必須實作：
  virtual void setupPlayers() = 0;
  virtual void setupDeck() = 0;
  virtual int initialCardCount() const = 0;
  virtual bool isGameOver() = 0;
  virtual void onGameEnd() = 0;
  virtual void determineRoundWinner() = 0;
  virtual bool allowDraw() const = 0;

  // 檢查該張牌是否符合遊戲規則
  virtual bool isValidPlay(IPlayer *player, ICard *card) = 0;
  // 合法出牌後的行為
  virtual void onValidPlay(IPlayer *player, ICard *card) = 0;

public:
  AbstractGame();
  virtual ~AbstractGame();

  // 固定流程
  void start() override;
  void next_turn() override;
  void compare() override;
  bool check() override;
  void end_game() override;
};
