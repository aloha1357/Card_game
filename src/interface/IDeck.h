#pragma once
#include "ICard.h"
#include "IPlayer.h" // forward declaration也可
class IDeck {
public:
  virtual void shuffle() = 0;
  virtual void drawCard(class IPlayer *player) = 0;
  virtual ICard *drawTopCard() = 0; // 給UNO翻開第一張牌用
  virtual ~IDeck() {}
};