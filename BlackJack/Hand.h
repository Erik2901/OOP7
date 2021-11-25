#pragma once

#include "Card.h"
#include <vector>

class Hand {
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetTotal() const;

protected:
    std::vector<Card*> m_Cards;
};