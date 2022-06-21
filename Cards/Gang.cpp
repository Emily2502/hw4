//
// Created by 97250 on 6/20/2022.
//

#include "Gang.h"


Gang::Gang(std::istream &is, int line):
        Card("Gang")
{}

void Gang::printCard(std::ostream &os) const {
    Card::printCard(os);
    for (int i = 0; i < m_gang.size(); ++i)
    {
        m_gang[i]->printCard(os);

    }
}
