
#ifndef TUT1_ITEM_H
#define TUT1_ITEM_H

struct Item_t {
    char name[50];
    int value;
    bool isValid;
};

void initItem(Item_t* item, const char* name, int value);
void invalidateItem(Item_t* item);

#endif //TUT1_ITEM_H
