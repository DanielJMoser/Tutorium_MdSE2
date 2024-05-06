#include "item.h"
#include <iostream>

Item::Item(const std::string& name, int goldValue, bool isValid) : name(name), goldValue(goldValue), valid(isValid) {}

const std::string& Item::getName() const {
    return name;
}

void Item::setName(const std::string& name) {
    this->name = name;
}

int Item::getGoldValue() const {
    return goldValue;
}

void Item::setGoldValue(int goldValue) {
    this->goldValue = goldValue;
}

bool Item::isValid() const {
    return valid;
}

void Item::invalidate() {
    valid = false;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    if (item.valid) {
        os << "Item: " << item.name << ", Goldwert: " << item.goldValue;
    } else {
        os << "Ungültiges Item";
    }
    return os;
}

