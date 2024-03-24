
#ifndef ITEM_H_
#define ITEM_H_

#include <string>


class Item {
public:
	Item(const std::string& name = "", int goldValue = 0, bool isValid = false);

    // Getter und Setter
    const std::string& getName() const;
    void setName(const std::string& name);
    int getGoldValue() const;
    void setGoldValue(int goldValue);
    bool isValid() const;

    void invalidate();

    void setValid(bool valid);

private:
	std::string name;
	int goldValue;
	bool valid;
};


#endif /* ITEM_H_ */
