#include <string>

class Item {
private:
    std::string name;
    int id;
    int quantity;
    double price;
    std::string supplier;

public:
    Item(std::string name, int id, int quantity, double price, std::string supplier);

    std::string getName() const;
    int getId() const;
    int getQuantity() const;
    double getPrice() const;
    std::string getSupplier() const;

    void setName(const std::string& newName);
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);
    void setSupplier(const std::string& newSupplier);

    void displayItem() const;

    std::string serialize() const;
    static Item deserialize(const std::string& data);

};