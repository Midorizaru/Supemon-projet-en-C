#ifndef ITEMS_H
#define ITEMS_H

typedef struct {
    char name[50];
    int price;
    int hpGain;
    int levelGain;
} Items;

void itemInit(Items *item, const char *name, int price, int hpGain, int levelGain);

#endif