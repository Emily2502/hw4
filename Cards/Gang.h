//
// Created by 97250 on 6/20/2022.
//

#ifndef HW4_GANG_H
#define HW4_GANG_H
#include "../Mtmchkin.h"

#include <deque>
#include <memory>


class Gang : public Card
{

public:
    explicit Gang(std::deque<std::string>& gang);

    void applyEncounter(Player& player) const override;


private:
    std::deque<std::unique_ptr<BattleCard>> m_gang;

};

#endif //HW4_GANG_H
