#pragma once
#include "../abstract/AbstractPlayer.h"

class AIPlayer : public AbstractPlayer {
public:
  AIPlayer();
  ICard *showHandAndPickOneOrDraw(bool canDraw) override; // 改成帶參數
};
