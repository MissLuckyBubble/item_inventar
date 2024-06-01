#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

Item::Item(std::string name, int id, int quantity, double price, std::string supplier)
    : name(name), id(id), quantity(quantity), price(price), supplier(supplier) {}

std::string Item::getName() const
{
    return name;
}
int Item::getId() const
{
    return id;
}
int Item::getQuantity() const {
    return quantity;
}
double Item::getPrice() const {
    return price;
}
std::string Item::getSupplier() const {
    return supplier;
}


void Item::setName(const std::string& name) {
    this->name = name;
}
void Item::setPrice(double price) {
    this->price = price;
}
void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}
void Item::setSupplier(const std::string& supplier) {
    this->supplier = supplier;
}

void Item::displayItem() const {
    std::cout << "ID: " << id << ", Name: " << name << std::endl;
    std::cout << "Quantity: " << quantity << ", price: " << price << std::endl;
    std::cout << "Supplier: " << supplier << std::endl;
    std::cout << "---------" << std::endl;
}


std::string Item::serialize() const {
    return std::to_string(id) + ";" + name + ";" + std::to_string(quantity) + ";" +
        std::to_string(price) + ";" + supplier;
}

Item Item::deserialize(const std::string& data) {
    size_t pos = 0;
    std::vector<std::string> tokens;
    std::string token;
    std::string s = data;

    while ((pos = s.find(';')) != std::string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    tokens.push_back(s);

    int id = std::stoi(tokens[0]);
    std::string name = tokens[1];
    int quantity = std::stoi(tokens[2]);
    double price = std::stod(tokens[3]);
    std::string supplier = tokens[4];

    return Item(name, id, quantity, price, supplier);
}