#pragma once
#include "Item.h"
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);

    bool removeItem(int id);

    bool updateItem(int id, int quantity, double price);

    std::vector<Item> searchItemsByName(const std::string& name) const;

    std::vector<Item> searchItemsByQantity(const int quanntity) const;

    void displayReport() const;


    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

};