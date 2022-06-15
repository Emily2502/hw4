cmake_minimum_required(VERSION 3.22)
project(hw4)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw4 main.cpp Players/Player.cpp Players/Player.h Players/HealthPoints.cpp Players/HealthPoints.h Players/Fighter.cpp Players/Fighter.h Players/Rogue.cpp Players/Rogue.h Players/Wizard.cpp Players/Wizard.h Cards/Card.cpp Cards/Card.h Cards/Merchant.cpp Cards/Merchant.h utilities.cpp utilities.h Cards/Treasure.cpp Cards/Treasure.h Cards/Pitfall.cpp Cards/Pitfall.h Cards/Barfight.cpp Cards/Barfight.h Cards/Fairy.cpp Cards/Fairy.h Cards/BattleCard.cpp Cards/BattleCard.h Cards/Goblin.cpp Cards/Goblin.h Cards/Vampire.cpp Cards/Vampire.h Cards/Dragon.cpp Cards/Dragon.h Mtmchkin.cpp Mtmchkin.h Exception.h)
