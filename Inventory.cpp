#include "Inventory.h"
#include <iostream>
#include <fstream>


void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

bool Inventory::removeItem(int id) {

    for (int i = 0; i < items.size(); i++) {
        if (items[i].getId() == id) {
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}

bool Inventory::updateItem(int id, int quantity, double price) {
    for (Item& item : items) {
        if (item.getId() == id) {
            item.setQuantity(quantity);
            item.setPrice(price);
            return true;
        }
    }
    return false;
}

std::vector<Item> Inventory::searchItemsByName(const std::string& name) const {
    std::vector<Item> result;
    for (const Item& item : items) {
        if (item.getName().find(name) != std::string::npos) {
            result.push_back(item);
        }
    }
    return result;
}

std::vector<Item> Inventory::searchItemsByQantity(const int quantity) const {
    std::vector<Item> result;
    for (const Item& item : items) {
        if (item.getQuantity() == quantity) {
            result.push_back(item);
        }
    }
    return result;
}

void Inventory::displayReport() const {
    for (const Item& item : items) {
        item.displayItem();
    }
}


void Inventory::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& item : items) {
        file << item.serialize() << std::endl;
    }
    std::cout << "Inventory saved to " << filename << ".\n";
    file.close();
}

void Inventory::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    items.clear();
    std::string line;
    while (std::getline(file, line)) {
        items.push_back(Item::deserialize(line));
    }

    std::cout << "Inventory loaded from " << filename << ".\n";
    file.close();
}