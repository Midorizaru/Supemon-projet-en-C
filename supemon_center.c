#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "supemon.h"
#include "player.h"
#include "supemon_center.h"
#include "battle.h"
#include "items.h"

void initSupcenter(Supcenter *supcenter, Player *player, const Supemon *supemon1, const Supemon *supemon2, const Supemon *supemon3, const Supemon *supemonEnemy1, const Supemon *supemonEnemy2, const Supemon *supemonEnemy3, const Items *item1, const Items *item2, const Items *item3, const Move *move1, const Move *move2, const Move *move3, const Move *move4, const Move *move5, const Move *move6, const Move *move7, const Move *move8, const Move *move9, const Move *move10) {
    printf("+-----------------------------------+\n| Welcome to the Supemon Center!    |\n| Here are the services available:  |\n|      1 - Heal your Supemon        |\n|      2 - Leave                    |\n+-----------------------------------+\n");
    printf("1 or 2: ");
    scanf("%d", &supcenter->userChoise);
    if (supcenter->userChoise == 1)
    {
        int continuer = 1;
        Battle battle;
        
        while (continuer)
        {
            printf("Which Supemon do you want to heal?\n");
            printf("1 - %s\n2 - %s\n3 - %s\n4 - %s\n5 - %s\n6 - %s\n7 - Cancel`\n", player->supemonList[0].name, player->supemonList[1].name, player->supemonList[2].name, player->supemonList[3].name, player->supemonList[4].name, player->supemonList[5].name);
            printf("1, 2, 3, 4, 5, 6 or 7: ");
            scanf("%d", &supcenter->userChoise);

            switch (supcenter->userChoise)
            {
            case 1:
                player->supemonList[0].hp = player->supemonList[0].max_hp; 
                printf("%s has been healed\n", player->supemonList[0].name);
                continuer = 0;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
                break;

            case 2:
                player->supemonList[1].hp = player->supemonList[1].max_hp;
                printf("%s has been healed\n", player->supemonList[1].name);
                continuer = 0;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
                break;

            case 3:
                player->supemonList[2].hp = player->supemonList[2].max_hp;
                printf("%s has been healed\n", player->supemonList[2].name);
                continuer = 0;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
                break;

            case 4:
                player->supemonEnemyList[0].hp = player->supemonEnemyList[0].max_hp; 
                printf("%s has been healed\n", player->supemonEnemyList[0].name);
                continuer = 0;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
                break;

            case 5:
                player->supemonEnemyList[1].hp = player->supemonEnemyList[1].max_hp;
                printf("%s has been healed\n", player->supemonEnemyList[1].name);
                continuer = 0;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
                break;

            case 6:
                player->supemonEnemyList[2].hp = player->supemonEnemyList[2].max_hp;
                printf("%s has been healed\n", player->supemonEnemyList[2].name);
                continuer = 0;
                initBattle(&battle, player, supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
                break;

            case 7:
                break;
            
            default:
                break;
            }
        }
    }
    else if (supcenter->userChoise == 2)
    {
        printf("Goodbye\n");
        printf("\n");
        printf("You go back to the wild\n");
        Battle battle;
        Supemon supemon1, supemon2, supemon3, supemonEnemy1, supemonEnemy2, supemonEnemy3;
        initBattle(&battle, player, &supemon1, &supemon2, &supemon3, &supemonEnemy1, &supemonEnemy2, &supemonEnemy3, item1, item2, item3, move1, move2, move3, move4, move5, move6, move7, move8, move9, move10);
    }
}