#include <cstring>
#include "item.h"


void initItem(Item_t* item, const char* name, int value) {
    strncpy(item->name, name, sizeof (item->name) - 1);
    item->name[sizeof (item->name) - 1] = '\0';
    item->value = value;
    item->isValid = true;
}

void invalidateItem(Item_t* item) {
    item->isValid = false;
}
