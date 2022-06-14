//
// Created by 97250 on 6/13/2022.
//

#include "Wizard.h"

void Wizard::heal(int hpPointsToUpgrade)
{
    Player::heal(2 * hpPointsToUpgrade);
}

std::string Wizard::getType() const
{
    return "Wizard";
}
