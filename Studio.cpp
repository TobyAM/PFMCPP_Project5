#pragma once
#include "Studio.h"

Studio::Studio() :
numInterns(4),
numAssistants(3),
balance(10000.0f)
{
    std::cout << "\n+ Constructed Studio!\n";
}

Studio::~Studio()
{
    std::cout << "\n- Destructing Studio!\n";
}

void Studio::orderRun(const std::string runner, const InvoiceManager::Invoice& invoice, const ScooterRental& scooter, const int latCoord, const int longCoord, const std::string order)
{
    std::cout << "Hey " << runner << " you need to go to grab " << order << " for " << invoice.clientName << ".\n";
    std::cout << "Here's a map, X marks the spot U need to go to:\n";
    int longRectified = longCoord + 18;
    int latRectified = latCoord + 18;
    int scooterLongRectified = scooter.longitude + 18;
    int scooterLatRectified = scooter.latitude + 18;
    
    for(int x = 1; x <= 37; ++x)
    {
        std::cout << "==";
    }
    std::cout << std::endl;

    for(int y = 1; y <= 36; ++y)
    {
        std::cout << "||";
        for(int x = 1; x <= 36; ++x)
        {
            if(x == longRectified && y == latRectified) std::cout << "X ";
            else if(x == scooterLongRectified && y == scooterLatRectified) std::cout << "U ";
            else if(x == 36) std::cout << "||";
            else std::cout << "  ";
        }
        
        std::cout << std::endl;
    }
    for(int x = 1; x <= 37; ++x)
    {
        std::cout << "==";
    }

    std::cout << std::endl;
 
    balance += scooter.balance;
   
}

void Studio::prepareCoffee(const std::string runner, const std::string clientName, const CoffeeShop::Coffee& coffeeType, const int size, const std::string brewType, const bool cream, const bool sugar)
{
    std::cout << "Hey " << runner << ", you need to make a " << brewType << " size " << size << " " << coffeeType.type << " coffee" << (cream && sugar ? " with cream and sugar" : (cream ? " with cream " : (sugar ? " with sugar" : ""))) << " for " << clientName << std::endl;
    theKitchen.brewCoffee(clientName, coffeeType, size, brewType, cream, sugar);
}

void Studio::printNumInterns()
{
    std::cout << "There are " << this->numInterns << " interns available.\n";
}
