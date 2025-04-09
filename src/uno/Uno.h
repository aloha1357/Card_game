#pragma once
#include "../abstract/AbstractGame.h"

class Uno : public AbstractGame {
private:
  ICard *topCard; // 檯面上的牌
protected:
  void setupPlayers() override;
  void setupDeck() override;
  int initialCardCount() const override;
  bool isGameOver() override;
  void onGameEnd() override;
  void determineRoundWinner() override;

  bool isValidPlay(IPlayer *player, ICard *card) override;
  void onValidPlay(IPlayer *player, ICard *card) override;
  bool allowDraw() const override {
    return true; // UNO允許抽牌
  }

public:
  Uno();
  ~Uno() {}
  void start() override; // 覆寫start以翻開第一張
};
