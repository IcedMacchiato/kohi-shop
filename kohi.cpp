#include <iostream>
#include <string>
#include <vector>

// Base class for a coffee product
class CoffeeProduct {
public:
    CoffeeProduct(std::string name, double price) : name(name), price(price) {}

    virtual ~CoffeeProduct() {}

    virtual void display() const = 0; // Pure virtual function

    double getPrice() const {
        return price;
    }

protected:
    std::string name;
    double price;
};

// Derived class for a coffee drink
class CoffeeDrink : public CoffeeProduct {
public:
    CoffeeDrink(std::string name, double price, std::string size)
        : CoffeeProduct(name, price), size(size) {}

    void display() const override {
        std::cout << "Product: " << name << ", Size: " << size << ", Price: $" << price << std::endl;
    }

private:
    std::string size;
};

// Derived class for a coffee accessory
class CoffeeAccessory : public CoffeeProduct {
public:
    CoffeeAccessory(std::string name, double price, std::string type)
        : CoffeeProduct(name, price), type(type) {}

    void display() const override {
        std::cout << "Product: " << name << ", Type: " << type << ", Price: $" << price << std::endl;
    }

private:
    std::string type;
};

// Class for managing coffee transactions
class Kohi {
public:
    void addProductToCart(CoffeeProduct* product) {
        cart.push_back(product);
    }

    void displayProducts() const {
        std::cout << "Coffee Shop Products:" << std::endl;
        for (const auto& product : products) {
            product->display();
        }
    }

    void displayCart() const {
        std::cout << "Cart Items:" << std::endl;
        for (const auto& product : cart) {
            product->display();
        }
    }

    double calculateTotalCost() const {
        double totalCost = 0;
        for (const auto& product : cart) {
            totalCost += product->getPrice();
        }
        return totalCost;
    }

private:
    std::vector<CoffeeProduct*> products;
    std::vector<CoffeeProduct*> cart;
};

int main() {
    // Create coffee products
    CoffeeDrink coffee1("Latte", 3.99, "Medium");
    CoffeeDrink coffee2("Espresso", 2.49, "Small");
    CoffeeAccessory accessory1("Coffee Mug", 9.99, "Ceramic");
    CoffeeAccessory accessory2("Coffee Beans", 12.99, "Arabica");

    // Create a coffee shop (Kohi)
    Kohi kohi;

    // Add products to Kohi (coffee shop)
    kohi.addProductToCart(&coffee1);
    kohi.addProductToCart(&coffee2);
    kohi.addProductToCart(&accessory1);
    kohi.addProductToCart(&accessory2);

    // Display coffee shop products
    kohi.displayProducts();

    // Display cart items
    kohi.displayCart();

    // Calculate total cost
    double totalCost = kohi.calculateTotalCost();
    std::cout << "Total Cost: $" << totalCost << std::endl;

    return 0;
}
