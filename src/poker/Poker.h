#pragma once
#include "../abstract/AbstractGame.h"

class Poker : public AbstractGame {
private:
  int currentRound = 0;
  const int MAX_ROUNDS = 13;
  bool compareCards(ICard *a, ICard *b);

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
    return false; // Poker不允許抽牌
  }

public:
  Poker();
  ~Poker() {}
};
