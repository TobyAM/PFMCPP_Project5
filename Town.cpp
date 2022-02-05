#include <iostream>
#include "LeakedObjectDetector.h"
#include "CoffeeShop.h"
#include "ScooterRental.h"
#include "Town.h"

Town::Town()
{
    std::cout << "\n+ Building Town with coffeeShop and a scooter rental!\n";
}

Town::~Town()
{
    std::cout << "\n- Demolishing Town with coffeShop and a scooter rental which earned " << totalTaxes << "!\n";
}

float Town::collectTaxes()
{
    float taxes = 0.0f;

    std::cout << "Taxing:\n";
    std::cout << "coffeeShop with balance of $" << coffeeShop.balance << " for $"<< coffeeShop.balance * 0.3f << std::endl;
    std::cout << "scooterRental with balance of $" << scooterRental.balance << " for $" << scooterRental.balance * 0.3f << std::endl;

    taxes += coffeeShop.balance * 0.3f + scooterRental.balance * 0.3f;
    totalTaxes += taxes;

    std::cout << "for a total haul of $" << taxes << (taxes < 1 ? "?" : "!") << std::endl;

    coffeeShop.balance *= 0.7f;
    scooterRental.balance *= 0.7f;

    return taxes;
}

void Town::quarantine()
{
    std::cout << "! Quarantine in effect ! Stay home !\n";
    coffeeShop.numBaristas = 0;
    coffeeShop.numCustomers = 0;
    std::cout << "! Public transportation is free if you need to use it !\n";
    scooterRental.balance = 999999999.0f;
}

void Town::printCoffeeShopBalance()
{
    std::cout << "The town coffee shop has a balance of " << this->coffeeShop.balance << std::endl;
}
