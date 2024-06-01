#include "Inventory.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "\nMenu\n";
    std::cout << "1. Add new item\n";
    std::cout << "2. Update item\n";
    std::cout << "3. Remove item\n";
    std::cout << "4. Search items by name\n";
    std::cout << "5. Search items by quantity\n";
    std::cout << "6. Display inventory report\n";
    std::cout << "7. Save inventory to file\n";
    std::cout << "8. Load inventory from file\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

void addItem(Inventory& inventory) {
    std::string name, supplier;
    int id, quantity;
    double price;

    std::cout << "Enter item ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter item name: ";
    getline(std::cin, name);
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter supplier: ";
    getline(std::cin, supplier);

    inventory.addItem(Item(name, id, quantity, price, supplier));
    std::cout << "Item added successfully.\n";
}

void updateItem(Inventory& inventory) {
    int id, quantity;
    double price;

    std::cout << "Enter item ID to update: ";
    std::cin >> id;
    std::cout << "Enter new quantity: ";
    std::cin >> quantity;
    std::cout << "Enter new price: ";
    std::cin >> price;

    if (inventory.updateItem(id, quantity, price)) {
        std::cout << "Item updated successfully.\n";
    }
    else {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}

void removeItem(Inventory& inventory) {
    int id;
    std::cout << "Enter item ID to remove: ";
    std::cin >> id;

    if (inventory.removeItem(id)) {
        std::cout << "Item removed successfully.\n";
    }
    else {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}

void searchItemsByName(Inventory& inventory) {
    std::string name;
    std::cout << "Enter item name to search: ";
    std::cin.ignore();
    getline(std::cin, name);

    std::vector<Item> results = inventory.searchItemsByName(name);
    if (results.empty()) {
        std::cout << "No items found with name " << name << ".\n";
    }
    else {
        for (const Item& item : results) {
            item.displayItem();
        }
    }
}

void searchItemsByQuantity(Inventory& inventory) {
    int quantity;
    std::cout << "Enter item quantity to search: ";
    std::cin >> quantity;

    std::vector<Item> results = inventory.searchItemsByQantity(quantity);
    if (results.empty()) {
        std::cout << "No items found with quantity " << quantity << ".\n";
    }
    else {
        for (const auto& item : results) {
            item.displayItem();
        }
    }
}

int main() {
    Inventory inventory;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addItem(inventory);
            break;
        case 2:
            updateItem(inventory);
            break;
        case 3:
            removeItem(inventory);
            break;
        case 4:
            searchItemsByName(inventory);
            break;
        case 5:
            searchItemsByQuantity(inventory);
            break;
        case 6:
            inventory.displayReport();
            break;
        case 7:
        {
            std::string filename;
            std::cout << "Enter filename to save inventory: ";
            std::cin >> filename;
            inventory.saveToFile(filename);
        }
        break;
        case 8:
        {
            std::string filename;
            std::cout << "Enter filename to load inventory: ";
            std::cin >> filename;
            inventory.loadFromFile(filename);
        }
        break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
