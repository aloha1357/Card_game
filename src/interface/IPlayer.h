#pragma once
#include "ICard.h"
#include <string>
#include <vector>

class ICard;

class IPlayer {
public:
  virtual ~IPlayer() {}

  // 讓玩家自行輸入(或AI隨機)名字
  virtual void naming() = 0;

  // 【新】讓玩家自由在整隻手牌中挑選某張牌出牌
  // 回傳 nullptr 表示玩家想抽牌，而不是出任何牌
  virtual ICard *showHandAndPickOneOrDraw(bool canDraw) = 0;

  // 新增 / 取得 / 檢查手牌
  virtual void addCard(ICard *card) = 0;
  virtual bool hasCards() const = 0;
  virtual const std::vector<ICard *> &getHand() const = 0;

  // 玩家基本資訊
  virtual std::string getName() const = 0;
  virtual void addPoint() = 0;
  virtual int getPoints() const = 0;

  // 記錄最後打出的牌（Poker需要）
  virtual void setLastPlayedCard(ICard *card) = 0;
  virtual ICard *getLastPlayedCard() const = 0;
};
