#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "CoffeeShop.h"
#include "ScooterRental.h"
#include "InvoiceManager.h"

struct Studio
{
    Studio();
    ~Studio();
    int numInterns, numAssistants;
    float balance;
    CoffeeShop theKitchen;
    ScooterRental scooterA, scooterB;
    InvoiceManager invoices;

    void orderRun(const std::string runner, const InvoiceManager::Invoice& invoice, const ScooterRental& scooter, const int latCoord, const int longCoord, const std::string order);
    void prepareCoffee(const std::string runner, const std::string clientName, const CoffeeShop::Coffee& coffeeType, const int size, const std::string brewType, const bool cream = false, const bool sugar = false);
    void printNumInterns();

    JUCE_LEAK_DETECTOR(Studio)
};
