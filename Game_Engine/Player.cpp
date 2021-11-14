#include "Player.h"

vector<Territory> Player::toDefend() {
    vector<Territory> territoriesToDefend();
    // add computation for territories to defend
    return territoriesToDefend();
}

vector<Territory> Player::toAttack() {
    vector<Territory> territoriesToAttack();
    // add computation for territories to defend
    return territoriesToAttack();
}

void Player::issueOrder(Order o) {
    playerOrdersList.add(o);
}