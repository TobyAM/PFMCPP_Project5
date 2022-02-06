#pragma once
#include "LeakedObjectDetector.h"

struct CoffeeShop
{
    CoffeeShop();
    ~CoffeeShop();
    int numBaristas, numCoffeeMachines, numRegisters, numCustomers, numTables;
    float balance;
    std::string brewMethod;

    struct Coffee
    {
        Coffee();
        ~Coffee();
        std::string type, roast;
        int coarseness;
        JUCE_LEAK_DETECTOR(Coffee)
    };
    Coffee standardBrew;

    struct Customer
    {
        Customer();
        ~Customer();
        int customerID;
        bool rewardsMember;
        float customerPhoneNumber, rewardsBalance;
        std::string name;
        bool useRewardsPoints(float rewardsPoints);
        void newMemberPromotion(const float incentiveAmount);
        bool contactCustomer(const std::string msg = "Your order is ready.");
        void printRewardsPoints();
        JUCE_LEAK_DETECTOR(Customer)
    };

    struct CustomerWrapper
    {
        CustomerWrapper( Customer* ptr);
        ~CustomerWrapper();
        Customer* pointer = nullptr;
    };

    Coffee brewCoffee(const std::string customerName, const Coffee& coffeeType, const int size, const std::string brewType, const bool withCream, const bool withsugar);
    bool grindCoffee(const Coffee& coffeeType, const int coarseness, const Customer& customerA);
    void renameCustomer(Customer& customerA, const std::string newName);
    void pourCoffee(const Coffee& coffee, const int size);
    void printNumBaristas();
    JUCE_LEAK_DETECTOR(CoffeeShop)
};
