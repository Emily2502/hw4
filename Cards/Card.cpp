//
// Created by 97250 on 6/13/2022.
//

#include "Card.h"

void Card::printCard(std::ostream &os) const
{
    printCardDetails(os, m_name);
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printCard(os);
    printEndOfCardDetails(os);
    return os;
}