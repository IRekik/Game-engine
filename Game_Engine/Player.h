#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H

#include "Map.h"
#include "Cards.h"
#include "Orders.h"

class Player {
public:
    vector<Territory> playerTerritories;
    Hand playerHand;
    OrdersList playerOrdersList;
    vector<Territory> toDefend();
    vector<Territory> toAttack();
    void issueOrder(Order o);
};

#endif //PLAYER_PLAYER_H