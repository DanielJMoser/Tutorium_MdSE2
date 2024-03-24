
#include "item.h"
#include <iostream>


Item::Item(const std::string &name, int goldValue, bool isValid) : name(name), goldValue(goldValue), valid(isValid) {}

void Item::setValid(bool valid) {
    Item::valid = valid;
}

void Item::setName(const std::string &name) {
    this->name = name;
}
const std::string &Item::getName() const {
    return name;
}

void Item::setGoldValue(int goldValue) {
    this->goldValue = goldValue;
}

int Item::getGoldValue() const {
    return goldValue;
}

bool Item::isValid() const {
    return valid;
}

void Item::invalidate() {
    valid = false;
}



std::ostream& operator<<(std::ostream& os, const Item& item) {
    if (item.isValid()) {
        os << "Item: " << item.getName() << ", Goldwert: " << item.getGoldValue();
    } else {
        os << "Ungültiges Item.";
    }
    return os;
}



