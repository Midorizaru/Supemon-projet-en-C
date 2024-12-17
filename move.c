#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supemon.h"
#include "player.h"
#include "battle.h" 
#include "move.h"


void initMove(Move *move, const char *name, int damage, int attack, int defense, int evasion, int accuracy, int speed){
    strcpy(move->name, name);
    move->damage = damage;
    move->attack = attack;
    move->defense = defense;
    move->evasion = evasion;
    move->accuracy = accuracy;
    move->speed = speed;
}

