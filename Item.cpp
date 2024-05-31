#include "Item.h"
#include <iostream>

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


void Item::setName(const std::string& name){
    this->name = name;
}
void Item::setPrice(double price){
    this->price = price;
}
void Item::setQuantity(int quantity){
    this->quantity = quantity;
}
void Item::setSupplier(const std::string& supplier){
    this->supplier = supplier;
}

void Item::displayItem() const{
    std::cout << "ID: " << id << ", Name: " << name << std::endl;
    std::cout << "Quantity: " << quantity << ", price: " << price<< std:: endl;
    std::cout << "Supplier: " << supplier << std::endl;
    std::cout << "---------" << std::endl;
}