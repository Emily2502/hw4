//
// Created by 97250 on 6/20/2022.
//

#ifndef HW4_GANG_H
#define HW4_GANG_H
#include "Card.h"
#include "BattleCard.h"
#include "../Exception.h"

#include <deque>
#include <memory>


class Gang : public Card
{

public:
    explicit Gang(std::istream& is, int line);

    void applyEncounter(Player& player) const override {}

    void printCard(std::ostream &os) const override;

private:
    std::deque<std::unique_ptr<BattleCard>> m_gang;

};

#endif //HW4_GANG_H
