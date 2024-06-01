#include "Inventory.h"
#include <iostream>



void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

bool Inventory::removeItem(int id) {
    
   for(int i = 0; i < items.size(); i++){
    if(items[i].getId() == id){
        items.erase(items.begin()+i);
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
        if (item.getName() == name) {
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


