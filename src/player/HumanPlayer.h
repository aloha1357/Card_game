#pragma once
#include "../abstract/AbstractPlayer.h"

class HumanPlayer : public AbstractPlayer {
public:
  void naming() override;
  ICard *showHandAndPickOneOrDraw(bool canDraw) override; // 改成帶參數
};
