#pragma once
#include "../interface/IDeck.h"
#include <vector>
#include <algorithm>
#include <random>

class AbstractDeck : public IDeck {
protected:
    std::vector<ICard*> cards;

    virtual void generateDeck() = 0; 
public:
    AbstractDeck();
    virtual void shuffle() override;
    virtual void drawCard(IPlayer* player) override;
    virtual ICard* drawTopCard() override;
    virtual ~AbstractDeck();
};
