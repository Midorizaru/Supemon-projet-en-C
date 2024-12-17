#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"


void itemInit(Items *item, const char *name, int price, int hpGain, int levelGain){
    strcpy(item->name, name);
    item->price = price;
    item->hpGain = hpGain;
    item->levelGain = levelGain;
}