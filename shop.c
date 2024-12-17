#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"
#include "shop.h"
#include "items.h"
#include "battle.h"
#include "supemon.h"
#include "move.h"

void initShop(Shop *shop, Player *player, const Items *item1, const Items *item2, const Items *item3, const Supemon *supemon1, const Supemon *supemon2, const Supemon *supemon3, const Supemon *supemonEnemy1, const Supemon *supemonEnemy2, const Supemon *supemonEnemy3, const Move *move1, const Move *move2, const Move *move3, const Move *move4, const Move *move5, const Move *move6, const Move *move7, const Move *move8, const Move *move9, const Move *move10) {
    int continuer = 1;
    Battle battle;
    while(continuer)
    {
        printf("+---------------------------------+\n| Welcome to the shop!            |\n| Here are the items for sale:    |\n| 1 - %s: %d supcoins        |\n| 2 - %s: %d supcoins  |\n| 3 - %s: %d supcoins    |\n+---------------------------------+\n", item1->name, item1->price, item2->name, item2->price, item3->name, item3->price);
        printf("1, 2 or 3: ");
        scanf("%d", &shop->itemsChoise);
        
        switch (shop->itemsChoise)
        {
        case 1:
            if (item1->price > player->supcoins)
            {
                printf("You don't have enough supcoins\n");
            }
            else if (item1->price <= player->supcoins)
            {
                printf("You bought %s\n", item1->name);
                player->supcoins -= item1->price;
                printf("You have %d supcoins left\n", player->supcoins);
                continuer = 0;
                player->itemsList[0] = *item1;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
            }
        break;

        case 2:
            if (item2->price > player->supcoins)
            {
                printf("You don't have enough supcoins\n");
            }
            else if (item2->price <= player->supcoins)
            {
                printf("You bought %s\n", item2->name);
                player->supcoins -= item2->price;
                printf("You have %d supcoins left\n", player->supcoins);
                continuer = 0;
                player->itemsList[1] = *item2;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
            }
        break;

        case 3:
            if (item3->price > player->supcoins)
            {
                printf("You don't have enough supcoins\n");
            }
            else if (item3->price <= player->supcoins)
            {
                printf("You bought %s\n", item3->name);
                player->supcoins -= item3->price;
                printf("You have %d supcoins left\n", player->supcoins);
                continuer = 0;
                player->itemsList[2] = *item3;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
            }
        break;
        
        default:
            break;
        }
    }
}