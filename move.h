#ifndef MOVE_H
#define MOVE_H

typedef struct {
    char name[50];
    int damage;
    int attack;
    int defense;
    int evasion;
    int accuracy;
    int speed;
} Move ;

void initMove(Move *move, const char *name, int damage, int attack, int defense, int evasion, int accuracy, int speed);

#endif