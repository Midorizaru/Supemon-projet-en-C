#ifndef SHOP_H
#define SHOP_H
#include "items.h"
#include "player.h"
#include "supemon.h"
#include "move.h"


typedef struct{
    int itemsChoise;
    int buyChoise;
} Shop;

void initShop(Shop *shop, Player *player, const Items *item1, const Items *item2, const Items *item3, const Supemon *supemon1, const Supemon *supemon2, const Supemon *supemon3, const Supemon *supemonEnemy1, const Supemon *supemonEnemy2, const Supemon *supemonEnemy3, const Move *move1, const Move *move2, const Move *move3, const Move *move4, const Move *move5, const Move *move6, const Move *move7, const Move *move8, const Move *move9, const Move *move10);


#endif