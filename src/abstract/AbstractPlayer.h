#pragma once
#include "../interface/IPlayer.h"
#include <vector>

class AbstractPlayer : public IPlayer {
protected:
  std::string name;
  int points;
  std::vector<ICard *> hand;
  ICard *lastPlayedCard;

public:
  AbstractPlayer();
  virtual ~AbstractPlayer();

  // 預設命名行為
  virtual void naming() override;

  // 核心：讓子類別(Human/AI)實作「選牌或抽牌」
  virtual ICard *showHandAndPickOneOrDraw(bool canDraw) override = 0;

  // 手牌相關
  void addCard(ICard *card) override;
  bool hasCards() const override;
  const std::vector<ICard *> &getHand() const override;

  // 基本資訊
  std::string getName() const override;
  void addPoint() override;
  int getPoints() const override;

  // 記錄最後牌
  void setLastPlayedCard(ICard *card) override;
  ICard *getLastPlayedCard() const override;

  // 顯示整個手牌 (給 HumanPlayer 用)
  void displayHand() const;
};
