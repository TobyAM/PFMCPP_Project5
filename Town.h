#pragma once
#include "LeakedObjectDetector.h"

struct Town         
{
    Town();
    ~Town();
    CoffeeShop coffeeShop;
    ScooterRental scooterRental;
    float totalTaxes;
    float collectTaxes();
    void quarantine();
    void printCoffeeShopBalance();
    JUCE_LEAK_DETECTOR(Town)
};
