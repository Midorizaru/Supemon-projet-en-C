#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supemon.h"
#include "player.h"
#include "battle.h"
#include "move.h"
#include "items.h"
#include "save.h"
#include "shop.h"
#include "supemon_center.h"

void saveGame(Player *player) { 
    FILE *file = fopen("savegame.dat", "wb");
    fwrite(player, sizeof(Player), 1, file);
    for (int i = 0; i < 6; i++) {
        fwrite(&player->supemonList[i], sizeof(Supemon), 1, file);
        for (int j = 0; j < 2; j++) {
            fwrite(&player->supemonList[i].move[j], sizeof(Move), 1, file);
        }
    }
    for (int i = 0; i < 3; i++) {
        fwrite(&player->itemsList[i], sizeof(Items), 1, file);
    }
    fclose(file);
    printf("Game saved with success !\n");
}

void loadGame(Player *player, Supemon *supemon1, Supemon *supemon2, Supemon *supemon3, Supemon *supemonEnemy1, Supemon *supemonEnemy2, Supemon *supemonEnemy3, Items *item1, Items *item2, Items *item3, Move *move1, Move *move2, Move *move3, Move *move4, Move *move5, Move *move6, Move *move7, Move *move8, Move *move9, Move *move10) {
    FILE *file = fopen("savegame.dat", "rb");
    if (!file) {
        printf("No save found.\n");
        return;
    }
    fread(player, sizeof(Player), 1, file);
    for (int i = 0; i < 6; i++) {
        fread(&player->supemonList[i], sizeof(Supemon), 1, file);
        for (int j = 0; j < 2; j++) {
            fread(&player->supemonList[i].move[j], sizeof(Move), 1, file);
        }
    }
    for (int i = 0; i < 3; i++) {
        fread(&player->itemsList[i], sizeof(Items), 1, file);
    }
    fclose(file);
    printf("Jeu charge avec succes !\n");
    printf("You ran away\n");
    printf("+------------------------------+\n");
    printf("|You have %d supcoins         |\n", player->supcoins);
    printf("|Where do you want to go?      |\n|     1 - Into the Wild        |\n|     2 - To the shop          |\n|     3 - In the Supemon Center|\n|     4 - Leave the Game       |\n");
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
