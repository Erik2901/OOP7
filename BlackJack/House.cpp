#include "House.h"

House::House() { m_Name = "House"; }

House::~House() {}

bool House::IsHitting() const {
    return(GetTotal() <= 16);
}

void House::FlipFirstCard() {
    if (!(m_Cards.empty()))
    {
        m_Cards[0]->Flip();
    }
    else
    {
        std::cout << "No card to flip!\n";
    }
}