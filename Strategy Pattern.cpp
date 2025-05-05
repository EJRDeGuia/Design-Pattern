#include <iostream>
using namespace std;

// Base Class - PaymentStrategy

class PaymentStrategy {
    public:
        virtual void pay(int amount ) = 0;
        virtual ~PaymentStrategy() {}
};

// Derived Class - CreditCard

class CreditCardPayment : public PaymentStrategy { 
    private:
        string CreditCardNumber;

    public:
        CreditCardPayment(string CreditCardNumber) : CreditCardNumber(CreditCardNumber) {}

        void pay (int amount){
            cout << "Paid with credit card: " << CreditCardNumber << endl;
            cout << "Amount: " << amount << endl;
        }

};

// Derived Class - Paypal

class PaypalPayment : public PaymentStrategy {
    private:
        string email;

    public:
        PaypalPayment(string email) : email (email) {}

        void pay (int amount){
            cout << "Paid with Paypal: " << email << endl;
            cout << "Amount: " << amount << endl;
        }
};

// Derived Class - Gcash

class GcashPayment : public PaymentStrategy {
    private:
        string phoneNumber;
        int pin;
    public:
        GcashPayment(string phoneNumber, int pin) : phoneNumber(phoneNumber), pin(pin) {}

        void pay (int amount){
            cout << "Paid with Gcash: " << phoneNumber << endl;
            cout << "Pin: " << pin << endl;
            cout << "Amount: " << amount << endl;
        }
};

class Cart {
    private:
        PaymentStrategy *payment;

    public:
        Cart() : payment (nullptr) {}

        void setPayment (PaymentStrategy* pay){
            delete payment;
            payment = pay;
        }

        void pay (int amount){
            if (payment){
                payment->pay(amount);
            } else {
                cout << "Payment not set." << endl;
            }
        }

        ~Cart(){
            delete payment;
        }
};

int main() {
    Cart cart;
    cart.setPayment(new CreditCardPayment("1234-5678-9012-3456"));
    cart.pay(100);

    cart.setPayment(new PaypalPayment("example@example.com"));
    cart.pay(200); 

    cart.setPayment(new GcashPayment("09123456789", 1234));
    cart.pay(300); 

    return 0;
}