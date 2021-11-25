#pragma once
#include <iostream>

class Card {
public:
    enum rank {
        ACE = 1,
        TWO = 2,
        THREE = 3,
        FOUR = 4,
        FIVE = 5,
        SIX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10,
        JACK = 10,
        QUEEN = 10,
        KING = 10
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};