#include "item.h"

Item::Item() : value(0), valid(false) {}

Item::Item(const std::string& name, int value) : name(name), value(value), valid(true) {}

Item::~Item() {}

std::string Item::getName() const { return name; }
int Item::getValue() const { return value; }
bool Item::isValid() const { return valid; }

void Item::setName(const std::string& name) { this->name = name; }
void Item::setValue(int value) { this->value = value; }
void Item::invalidate() { valid = false; }