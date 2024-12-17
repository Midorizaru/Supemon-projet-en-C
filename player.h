#ifndef PLAYER_H
#define PLAYER_H
#include "supemon.h"
#include "items.h"

typedef struct {
    char name[50];
    int level;
    Supemon supemonList[6];
    Supemon supemonEnemyList[3];
    Supemon currentSupemon[1];
    int selectedSupemon;
    int supcoins;
    Items itemsList[3];
    int location;
    int userChoise;
    int loadGame;
} Player ;


void initPlayer(Player *player, const Supemon *supemon1, const Supemon *supemon2, const Supemon *supemon3, const Supemon *supemonEnemy1, const Supemon *supemonEnemy2, const Supemon *supemonEnemy3, const Items *item1, const Items *item2, const Items *item3, const Move *move1, const Move *move2, const Move *move3, const Move *move4, const Move *move5, const Move *move6, const Move *move7, const Move *move8, const Move *move9, const Move *move10);


#endif