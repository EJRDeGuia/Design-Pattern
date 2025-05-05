#include <iostream>
using namespace std;

// Base Class - DiscountStrategy
class discount {
public:
    virtual double applyDiscount(double price) = 0;
    virtual double getDiscount(double price) {
        return price - applyDiscount(price);
    }
    virtual ~discount() {}
};

// Derived Class - No Discount
class noDiscount : public discount {
    public:
        double applyDiscount(double price) override {
            return price;
        }
        
};

// Derived Class - 10% Discount
class tenPercent : public discount {
    public:
        double applyDiscount(double price) override {
            return price - (price * 0.1);
        }
        
        double getDiscount(double price) override {
            return price * 0.1;
        }
};

// Derived Class - 20% Discount
class twentyPercent : public discount {
    public:
        double applyDiscount(double price) override {
            return price - (price * 0.2);
        }
        
        double getDiscount(double price) override {
            return price * 0.2;
        }
};

class cart {
    private:
        discount* strategy;

    public:
        cart() : strategy(nullptr) {}

        void setDiscountStrategy(discount* strategy) {
            if (this->strategy) {
                delete this->strategy;
            }
            this->strategy = strategy;
        }

        double calculatePrice(double price) {
            if (strategy) {
                return strategy->applyDiscount(price);
            } else {
                cout << "No discount strategy set!" << endl;
                return price;
            }
        }

        double getDiscount(double price) {
            if (strategy) {
                return strategy->getDiscount(price);
            }
            return 0.0;
        }

        ~cart() {
            delete strategy;
        }
};

int main() {
    cart shoppingCart;
    double price;

    cout << "Enter the price of the item: ";
    cin >> price;

    cout << "Choose your discount: " << endl;
    cout << "1. No Discount" << endl;
    cout << "2. Voucher (10% off)" << endl;
    cout << "3. Senior Citizen (20% off)" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            shoppingCart.setDiscountStrategy(new noDiscount());
            cout << "Original price: Php " << price << endl;
            cout << "Discount amount: Php " << shoppingCart.getDiscount(price) << endl;
            cout << "Final price: Php " << shoppingCart.calculatePrice(price) << endl;
            break;
        case 2:
            shoppingCart.setDiscountStrategy(new tenPercent());
            cout << "Original price: Php " << price << endl;
            cout << "Discount amount: Php " << shoppingCart.getDiscount(price) << endl;
            cout << "Final price: Php " << shoppingCart.calculatePrice(price) << endl;
            break;
        case 3:
            shoppingCart.setDiscountStrategy(new twentyPercent());
            cout << "Original price: Php " << price << endl;
            cout << "Discount amount: Php " << shoppingCart.getDiscount(price) << endl;
            cout << "Final price: Php " << shoppingCart.calculatePrice(price) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    return 0;
}