#ifndef TUT1_ITEM_H
#define TUT1_ITEM_H

#pragma once
#include <string>

class Item {
public:
    Item();
    Item(const std::string& name, int value);
    ~Item();

    // Getter
    std::string getName() const;
    int getValue() const;
    bool isValid() const;

    // Setter
    void setName(const std::string& name);
    void setValue(int value);
    void invalidate();

private:
    std::string name;
    int value;
    bool valid;
};

#endif //TUT1_ITEM_H