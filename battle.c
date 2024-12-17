#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "supemon.h"
#include "player.h"
#include "battle.h"
#include "move.h"
#include "items.h"
#include "shop.h"
#include "supemon_center.h"
#include "save.h"

void initBattle(Battle *battle, Player *player, const Supemon *supemon1, const Supemon *supemon2, const Supemon *supemon3, const Supemon *supemonEnemy1, const Supemon *supemonEnemy2, const Supemon *supemonEnemy3, const Items *item1, const Items *item2, const Items *item3, const Move *move1, const Move *move2, const Move *move3, const Move *move4, const Move *move5, const Move *move6, const Move *move7, const Move *move8, const Move *move9, const Move *move10) {
    srand(time(NULL));
    int randomNumber = rand() % 3;
    int randomNumber2 = rand() % 3;

    int continuer = 1;
    while (continuer)
    {
        printf("Your turn...\n");
        printf("\n");
        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
        printf("--------------------------------\n");
        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
        printf("\n");
        printf("+----------------------------+\n");
        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
        printf("--------------------------------\n");
        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
        printf("--------------------------------\n");


        printf("+----------------------------+\n");
        printf("|What will you do?           |\n|     1 - Move               |\n|     2 - Change Supemon     |\n|     3 - Use item           |\n|     4 - Capture            |\n|     5 - Run away           |\n");
        printf("+----------------------------+\n");
        printf("1, 2, 3, 4 or 5 ? : ");
        scanf("%d", &battle->userGlobalChoise);

        switch (battle->userGlobalChoise)
        {
            case 1:
                printf("1 - %s\n2 - %s\n2 - Cancel\n", player->currentSupemon[0].move[0].name, player->currentSupemon[0].move[1].name);
                printf("1, 2 or 3 ? :\n");
                scanf("%d", &battle->moveChoise);
                if (battle->moveChoise == 1)
                {
                    if (player->currentSupemon[0].move[0].damage > 0) {
                        printf("Deals %d damage.\n", player->currentSupemon[0].move[0].damage);
                        int damageCalculation = player->currentSupemon[0].attack * player->currentSupemon[0].move[0].damage / player->supemonEnemyList[randomNumber].defense;
                        player->supemonEnemyList[randomNumber].hp -= damageCalculation;
                        printf("%d\n", damageCalculation);
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");

                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].damage > 0)
                        {
                            int damageCalculationEnemy = player->supemonEnemyList[randomNumber].attack * player->supemonEnemyList[randomNumber].move[randomNumber2].damage / player->currentSupemon[0].defense;
                            player->currentSupemon[0].hp -= damageCalculationEnemy;
                            printf("%d\n", damageCalculation);
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                        

                        
                    }
                    else if (player->currentSupemon[0].move[0].attack > 0) {
                        printf("Increase attack by %d.\n", player->currentSupemon[0].move[0].attack);
                        player->currentSupemon[0].attack += player->currentSupemon[0].move[0].attack;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].attack > 0)
                        {
                            printf("Increase attack by %d.\n", player->currentSupemon[0].move[0].attack);
                            player->supemonEnemyList[randomNumber].attack += player->supemonEnemyList[randomNumber].move[randomNumber2].attack;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    }
                    else if (player->currentSupemon[0].move[0].defense > 0) {
                        printf("Increase defense by %d.\n", player->currentSupemon[0].move[0].defense);
                        player->currentSupemon[0].defense += player->currentSupemon[0].move[0].defense;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].defense > 0)
                        {
                            printf("Increase defense by %d.\n", player->currentSupemon[0].move[0].defense);
                            player->supemonEnemyList[randomNumber].defense += player->supemonEnemyList[randomNumber].move[randomNumber2].defense;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }

                    }
                    else if (player->currentSupemon[0].move[0].evasion > 0) {
                        printf("Increase evasion by %d.\n", player->currentSupemon[0].move[0].evasion);
                        player->currentSupemon[0].evasion += player->currentSupemon[0].move[0].evasion;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].evasion > 0)
                        {
                            printf("Increase evasion by %d.\n", player->currentSupemon[0].move[0].evasion);
                            player->supemonEnemyList[randomNumber].evasion += player->supemonEnemyList[randomNumber].move[randomNumber2].evasion;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    } 
                    else if (player->currentSupemon[0].move[0].accuracy > 0) {
                        printf("Reduces enemy accuracy.\n");
                        player->supemonEnemyList[randomNumber].accuracy -= player->currentSupemon[0].move[0].accuracy;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].accuracy > 0)
                        {
                            printf("Reduces enemy accuracy.\n");
                            player->currentSupemon[0].accuracy -= player->supemonEnemyList[randomNumber].move[randomNumber2].accuracy;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    } 
                    else if (player->currentSupemon[0].move[0].speed > 0) { 
                        printf("Reduces enemy speed.\n");
                        player->supemonEnemyList[randomNumber].speed -= player->currentSupemon[0].move[0].speed;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].speed > 0)
                        {
                            printf("Reduces enemy speed.\n");
                            player->currentSupemon[0].speed -= player->supemonEnemyList[randomNumber].move[randomNumber2].speed;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    }    
                }
                else if (battle->moveChoise == 2)
                {
                    if (player->currentSupemon[0].move[1].damage > 0) {
                        printf("Deals %d damage.\n", player->currentSupemon[0].move[1].damage);
                        int damageCalculation = player->currentSupemon[0].attack * player->currentSupemon[0].move[1].damage / player->supemonEnemyList[randomNumber].defense;
                        player->supemonEnemyList[randomNumber].hp -= damageCalculation;
                        printf("%d\n", damageCalculation);
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].damage > 0)
                        {
                            int damageCalculationEnemy = player->supemonEnemyList[randomNumber].attack * player->supemonEnemyList[randomNumber].move[randomNumber2].damage / player->currentSupemon[0].defense;
                            player->currentSupemon[0].hp -= damageCalculationEnemy;
                            printf("%d\n", damageCalculation);
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    } 
                    else if (player->currentSupemon[0].move[1].attack > 0) {
                        printf("Increase attack by %d.\n", player->currentSupemon[0].move[1].attack);
                        player->currentSupemon[0].attack += player->currentSupemon[0].move[1].attack;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].attack > 0)
                        {
                            printf("Increase attack by %d.\n", player->currentSupemon[0].move[1].attack);
                            player->supemonEnemyList[randomNumber].attack += player->supemonEnemyList[randomNumber].move[randomNumber2].attack;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    }
                    else if (player->currentSupemon[0].move[1].defense > 0) {
                        printf("Increase defense by %d.\n", player->currentSupemon[0].move[1].defense);
                        player->currentSupemon[0].defense += player->currentSupemon[0].move[1].defense;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].defense > 0)
                        {
                            printf("Increase defense by %d.\n", player->currentSupemon[0].move[1].defense);
                            player->supemonEnemyList[randomNumber].defense += player->supemonEnemyList[randomNumber].move[randomNumber2].defense;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    }
                    else if (player->currentSupemon[0].move[1].evasion > 0) {
                        printf("Increase evasion by %d.\n", player->currentSupemon[0].move[1].evasion);
                        player->currentSupemon[0].evasion += player->currentSupemon[0].move[1].evasion;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].evasion > 0)
                        {
                            printf("Increase evasion by %d.\n", player->currentSupemon[0].move[1].evasion);
                            player->supemonEnemyList[randomNumber].evasion += player->supemonEnemyList[randomNumber].move[randomNumber2].evasion;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    } 
                    else if (player->currentSupemon[0].move[1].accuracy > 0) {
                        printf("Reduces enemy accuracy.\n");
                        printf("Reduces enemy accuracy.\n");
                        player->supemonEnemyList[randomNumber].accuracy -= player->currentSupemon[0].move[1].accuracy;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].accuracy > 0)
                        {
                            printf("Reduces enemy accuracy.\n");
                            player->currentSupemon[0].accuracy -= player->supemonEnemyList[randomNumber].move[randomNumber2].accuracy;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    } 
                    else if (player->currentSupemon[0].move[1].speed > 0) {
                        printf("Reduces enemy speed.\n");
                        player->supemonEnemyList[randomNumber].speed -= player->currentSupemon[0].move[1].speed;
                        printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                        printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                        printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                        printf("\n");
                        printf("+----------------------------+\n");
                        printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                        printf("--------------------------------\n");
                        printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                        printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                        printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                        printf("--------------------------------\n");
                        printf("Enemy's turn...\n");
                        if (player->supemonEnemyList[randomNumber].move[randomNumber2].speed > 0)
                        {
                            printf("Reduces enemy speed.\n");
                            player->currentSupemon[0].speed -= player->supemonEnemyList[randomNumber].move[randomNumber2].speed;
                            printf("%s (enemy)\n", player->supemonEnemyList[randomNumber].name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->supemonEnemyList[randomNumber].hp,player->supemonEnemyList[randomNumber].max_hp, player->supemonEnemyList[randomNumber].level);
                            printf("Atk: %d     Def: %d\n", player->supemonEnemyList[randomNumber].attack, player->supemonEnemyList[randomNumber].defense);
                            printf("Acc: %d     Eva: %d\n", player->supemonEnemyList[randomNumber].accuracy, player->supemonEnemyList[randomNumber].evasion);
                            printf("\n");
                            printf("+----------------------------+\n");
                            printf("%s (%s)\n", player->currentSupemon[0].name, player->name);
                            printf("--------------------------------\n");
                            printf("HP: %d/%d     Lvl: %d\n", player->currentSupemon[0].hp, player->currentSupemon[0].max_hp, player->currentSupemon[0].level);
                            printf("Atk: %d     Def: %d\n", player->currentSupemon[0].attack, player->currentSupemon[0].defense);
                            printf("Acc: %d     Eva: %d\n", player->currentSupemon[0].accuracy, player->currentSupemon[0].evasion);
                            printf("--------------------------------\n");
                        }
                    }
                }
                else if (battle->moveChoise == 3)
                {}
            break;
                
            case 2:
                printf("+--------------------------------+\n");
                printf("|which pokemon will you take?    |\n|     1 - %s              |\n|     2 - %s               |\n|     3 - %s               |\n|     4 - %s               |\n|     5 - %s               |\n|     6 - %s               |\n", player->supemonList[0].name, player->supemonList[1].name, player->supemonList[2].name, player->supemonList[3].name, player->supemonList[4].name, player->supemonList[5].name);
                printf("+--------------------------------+\n");
                printf("1, 2 or 3 ? : ");
                scanf("%d", &battle->SupemonChoise);
                if (battle->SupemonChoise == 1)
                {
                    printf("You choose %s\n", player->supemonList[0].name);
                    player->currentSupemon[0] = *supemon1;
                    printf("\n");
                }
                else if (battle->SupemonChoise == 2)
                {
                    printf("You choose %s\n", player->supemonList[1].name);
                    player->currentSupemon[0] = *supemon2;
                    printf("\n");
                }
                else if (battle->SupemonChoise == 3)
                {
                    printf("You choose %s\n", player->supemonList[2].name);
                    player->currentSupemon[0] = *supemon3;
                    printf("\n");
                }
                else if (battle->SupemonChoise == 4)
                {
                    printf("You choose %s\n", player->supemonList[3].name);
                    player->currentSupemon[0] = player->supemonList[3];
                    printf("\n");
                }
                else if (battle->SupemonChoise == 5)
                {
                    printf("You choose %s\n", player->supemonList[4].name);
                    player->currentSupemon[0] = player->supemonList[4];
                    printf("\n");
                }
                else if (battle->SupemonChoise == 6)
                {
                    printf("You choose %s\n", player->supemonList[5].name);
                    player->currentSupemon[0] = player->supemonList[5];
                    printf("\n");
                }
            break;

            case 3:
                printf("Here are items that you have:\n1 - %s\n2 - %s\n3 - %s\n", player->itemsList[0].name, player->itemsList[1].name, player->itemsList[2].name);
                printf("1, 2 or 3 ? :\n");
                scanf("%d", &battle->ItemChoise);
                if (battle->ItemChoise == 1)
                {
                    printf("You are using %s\n", player->itemsList[0].name);
                    player->currentSupemon[0].max_hp += player->itemsList[0].hpGain;
                    player->currentSupemon[0].hp += player->itemsList[0].hpGain;
                }
                else if (battle->ItemChoise == 2)
                {
                    printf("You are using %s\n", player->itemsList[1].name);
                    player->currentSupemon[0].max_hp += player->itemsList[1].hpGain;
                    player->currentSupemon[0].hp += player->itemsList[1].hpGain;
                }
                else if (battle->ItemChoise == 3)
                {
                    printf("You are using %s\n", player->itemsList[2].name);
                    player->currentSupemon[0].level += player->itemsList[2].levelGain;
                }
            break;

            case 4:
                {
                double chance = ((double)(player->supemonEnemyList[randomNumber].max_hp - player->supemonEnemyList[randomNumber].hp) / player->supemonEnemyList[randomNumber].max_hp);
                printf("+------------------------------------------------+\n");
                printf("|You have %lf chance to capture the supemon      |\n", chance);
                printf("+------------------------------------------------+\n");
                printf("|Are you sure you want to capture the supemon?   |\n|     1 - Yes                                    |\n|     2 - No                                     |\n");
                printf("+------------------------------------------------+\n");
                printf("1 or 2 ? : ");
                scanf("%d", &battle->captureChoise);
                if (battle->captureChoise == 1)
                {
                    if (chance >= 0.5)
                    {
                        printf("You captured %s\n", player->supemonEnemyList[randomNumber].name);
                        player->supemonList[3] = player->supemonEnemyList[randomNumber];
                        printf("+---------------------------------------+\n");
                        printf("|You now have all these supemons:       |\n|      1 - %s                    |\n|      2 - %s                     |\n|      3 - %s                     |\n|      4 - %s                     |\n|      5 - %s                            |\n|      6 - %s                            |\n", player->supemonList[0].name, player->supemonList[1].name, player->supemonList[2].name, player->supemonList[3].name, player->supemonList[4].name, player->supemonList[5].name);
                        printf("+---------------------------------------+\n");
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
                        continuer = 0;
                    }
                    else if (chance < 0.5)
                    {
                        printf("The supemon escaped\n");
                    }
                }
                else if (battle->captureChoise == 2)
                {
                    printf("You don't want to capture the supemon");
                }
                }
            break;

            case 5:
                {
                double chance = (player->currentSupemon[0].speed / (double)(player->currentSupemon[0].speed + player->supemonEnemyList[randomNumber].speed));
                printf("+------------------------------------------------+\n");
                printf("|You have %lf chance to capture the supemon      |\n", chance);
                printf("+------------------------------------------------+\n");
                printf("+----------------------------------+\n");
                printf("|Are you sure you want to run away?|\n|     1 - Yes                      |\n|     2 - No                       |\n");
                printf("+----------------------------------+\n");
                printf("1 or 2 ? : ");
                scanf("%d", &battle->runAwayChoise);
                if (battle->runAwayChoise == 1)
                {
                    if (chance >= 0.5)
                    {
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
                        continuer = 0;
                    }
                    else if (chance < 0.5)
                    {
                        printf("You couldn't run away\n");
                    }
                }
                else if (battle->runAwayChoise == 2)
                {}
                }
            break;    

            default:
                continuer = 0;
                break;
        }
    }
}