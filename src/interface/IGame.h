#pragma once
class IGame {
public:
    virtual void start() = 0;     // 遊戲初始化 (建立玩家, 洗牌, etc.)
    virtual void next_turn() = 0; // 一輪出牌
    virtual void compare() = 0;   // 回合或分數比較
    virtual bool check() = 0;     // 是否結束
    virtual void end_game() = 0;  // 遊戲結束處理
    virtual ~IGame() {}
};