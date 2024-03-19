#pragma once
#include <string>

class Item {
public:
    Item(); // Konstruktor
    Item(const std::string& name, int value); // Überladener Konstruktor
    ~Item(); // Destruktor

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
