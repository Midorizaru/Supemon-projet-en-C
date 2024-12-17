#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supemon.h"
#include "player.h"
#include "battle.h"
#include "move.h" 
#include "items.h"
#include "save.h"


int main() 
{
    Supemon supemon1;
    Supemon supemon2;
    Supemon supemon3;
    Supemon supemonEnemy1;
    Supemon supemonEnemy2;
    Supemon supemonEnemy3;

    Items item1;
    Items item2;
    Items item3;

    Move move1;
    Move move2;
    Move move3;
    Move move4;
    Move move5;
    Move move6;
    Move move7;
    Move move8;
    Move move9;
    Move move10;

    Player player;
    Battle battle; 


    initMove(&move1, "Scratch", 3, 0, 0, 0, 0, 0);
    initMove(&move2, "Grawl", 0, 1, 0, 0, 0, 0);
    initMove(&move3, "Pound", 2, 0, 0, 0, 0, 0);
    initMove(&move4, "Foliage", 0, 0, 0, 1, 0, 0);
    initMove(&move5, "Shell", 0, 0, 1, 0, 0, 0);
    initMove(&move6, "Tackle", 2, 0, 0, 0, 0, 0);
    initMove(&move7, "TailWhip", 0, 0, 1, 0, 0, 0);
    initMove(&move8, "Gust", 2, 0, 0, 0, 0, 0);
    initMove(&move9, "SandAttack", 0, 0, 0, 0, 1, 0);
    initMove(&move10, "StringShot", 0, 0, 1, 0, 0, 1);


    initSupemon(&supemon1, "Supmander", 1, 10, 10, 1, 1, 1, 2, 1, &move1, &move2); 
    initSupemon(&supemon2, "Supasaur", 1, 9, 9, 1, 1, 3, 2, 2, &move3, &move4); 
    initSupemon(&supemon3, "Supirtle", 1, 11, 11, 1, 2, 2, 1, 2, &move3, &move5);
    initSupemon(&supemonEnemy1, "Supttata", 1, 8, 8, 2, 1, 1, 1, 2, &move6, &move7);
    initSupemon(&supemonEnemy2, "Supcool", 1, 10, 10, 1, 1, 2, 2, 2, &move8, &move9);
    initSupemon(&supemonEnemy3, "Supnipan", 1, 9, 9, 1, 1, 1, 2, 2, &move6, &move10); 


    itemInit(&item1, "Potion", 100, 5, 0);
    itemInit(&item2, "Super Potion", 300, 10, 0);
    itemInit(&item3, "Rare candy", 700, 0, 1);

    printf("If you have already saved beforehand, you can load a game otherwise no\n");
    printf("Welcome, would you like to load your previous game?\n");
    printf("1 - Yes\n2 - No\n");
    scanf("%d", &player.loadGame);
    if (player.loadGame == 1)
    {
        loadGame(&player, &supemon1, &supemon2, &supemon3, &supemonEnemy1, &supemonEnemy2, &supemonEnemy3, &item1, &item2, &item3, &move1, &move2, &move3, &move4, &move5, &move6, &move7, &move8, &move9, &move10);
    }
    else if (player.loadGame == 2)
    {
        initPlayer(&player, &supemon1, &supemon2, &supemon3, &supemonEnemy1, &supemonEnemy2, &supemonEnemy3, &item1, &item2, &item3, &move1, &move2, &move3, &move4, &move5, &move6, &move7, &move8, &move9, &move10);
    }
    

    

    return 0;
}