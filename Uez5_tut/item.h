#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item {
public:
    Item(const std::string& name = "", int gold = 0, bool isValid = false);

    // Getter und Setter
    const std::string& getName() const;
    void setName(const std::string& name);
    int getGoldValue() const;
    void setGoldValue(int goldValue);
    bool isValid() const;
    void invalidate(); // Setzt das Item als ungültig

    // Überladung des Output-Stream Operators
    friend std::ostream& operator<<(std::ostream& os, const Item& item);

private:
    std::string name;
    int goldValue;
    bool valid;
};

#endif /* ITEM_H_ */
