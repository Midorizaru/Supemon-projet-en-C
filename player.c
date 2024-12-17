#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supemon.h"
#include "player.h"
#include "battle.h"
#include "shop.h"
#include "items.h"
#include "supemon_center.h"
#include "save.h" 

void initPlayer(Player *player, const Supemon *supemon1, const Supemon *supemon2, const Supemon *supemon3, const Supemon *supemonEnemy1, const Supemon *supemonEnemy2, const Supemon *supemonEnemy3, const Items *item1, const Items *item2, const Items *item3, const Move *move1, const Move *move2, const Move *move3, const Move *move4, const Move *move5, const Move *move6, const Move *move7, const Move *move8, const Move *move9, const Move *move10) {
    int playerTurn = 1;
    printf("What is your name?\n");
    scanf("%s", player->name);
    printf("Hello %s!\nWelcome in Supemon World\n\n+------------------------------+\n| Choose your starter Supemon: |\n", player->name);
    printf("|     1 - %s            |\n", supemon1->name);
    printf("|     2 - %s             |\n", supemon2->name);
    printf("|     3 - %s             |\n", supemon3->name);
    printf("+------------------------------+\n");
    printf("1, 2 or 3 : ");
    scanf("%d", &player->selectedSupemon);
    player->level = 1;
    
    if (player->selectedSupemon == 1)
    {
        printf("\n");
        printf("%s\n", supemon1->name);
        printf("--------------------------------\n");
        printf("HP: %d     Lvl: %d\n", supemon1->hp, supemon1->level);
        printf("Atk: %d     Def: %d\n", supemon1->attack, supemon1->defense);
        printf("Acc: %d     Eva: %d\n", supemon1->accuracy, supemon1->evasion);
        printf("\n");

        player->currentSupemon[0] = *supemon1;
        player->supemonList[0] = *supemon1; 
        player->supemonList[1] = *supemon2;
        player->supemonList[2] = *supemon3;
        player->supemonEnemyList[0] = *supemonEnemy1;
        player->supemonEnemyList[1] = *supemonEnemy2;
        player->supemonEnemyList[2] = *supemonEnemy3;
        player->supcoins = player->level * 500;

    } 

    else if (player->selectedSupemon == 2)
    {
        printf("\n");
        printf("%s\n", supemon2->name);
        printf("--------------------------------\n");
        printf("HP: %d      Lvl: %d\n", supemon2->hp, supemon2->level);
        printf("Atk: %d     Def: %d\n", supemon2->attack, supemon2->defense);
        printf("Acc: %d     Eva: %d\n", supemon2->accuracy, supemon2->evasion);
        printf("\n");
        player->currentSupemon[0] = *supemon2;
        player->supemonList[0] = *supemon1;
        player->supemonList[1] = *supemon2;
        player->supemonList[2] = *supemon3;
        player->supemonEnemyList[0] = *supemonEnemy1;
        player->supemonEnemyList[1] = *supemonEnemy2;
        player->supemonEnemyList[2] = *supemonEnemy3;
        player->supcoins = player->level * 500;

    }

    else if (player->selectedSupemon == 3)
    {
        printf("\n");
        printf("%s\n", supemon3->name);
        printf("--------------------------------\n");
        printf("HP: %d     Lvl: %d\n", supemon3->hp, supemon3->level);
        printf("Atk: %d     Def: %d\n", supemon3->attack, supemon3->defense);
        printf("Acc: %d     Eva: %d\n", supemon3->accuracy, supemon3->evasion);
        printf("\n");
        player->currentSupemon[0] = *supemon3;
        player->supemonList[0] = *supemon1;
        player->supemonList[1] = *supemon2;
        player->supemonList[2] = *supemon3;
        player->supemonEnemyList[0] = *supemonEnemy1;
        player->supemonEnemyList[1] = *supemonEnemy2;
        player->supemonEnemyList[2] = *supemonEnemy3;
        player->supcoins = player->level * 500;

    }


    printf("+------------------------------+\n");
    printf("|You have %d supcoins         |\n", player->supcoins);
    printf("|Where do you want to go?      |\n|     1 - Into the Wild        |\n|     2 - To the shop          |\n|     3 - In the Supemon Center|\n|     4 - Leave the Game|\n");
    printf("+------------------------------+\n");
    printf("1, 2, 3 or 4 ? : ");
    scanf("%d",&player->location);

    if (player->location == 1)
    {
        Battle battle;
        initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
    }

    else if (player->location == 2)
    {
        Shop shop;
        initShop(&shop, player, item1, item2, item3, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
    }

    else if (player->location == 3) 
    {
        Supcenter supcenter;
        initSupcenter(&supcenter, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
    }
    
    else if (player->location == 4)
    {
        printf("Goodbye, your progression has been saved !\n");
        saveGame(player);
    }
}