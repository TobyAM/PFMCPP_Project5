#include <iostream>
#include "ScooterRental.h"

ScooterRental::ScooterRental() :
distanceTraveled(0),
speed(0),
latitude(3),
longitude(-11),
rentalTime(0.0f),
balance(1.0f),
voltage(100.0f)
{
    std::cout << "\n+ ScooterRental constructed!" << std::endl; 
}

ScooterRental::~ScooterRental()
{
    std::cout << "\n- ScooterRental destructed!" << std::endl; 
}

void ScooterRental::accelerate(float throttle = 0.0f)
{
    voltage = voltage * throttle;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

void ScooterRental::brake(float brake = 0.0f)
{
    voltage -= brake;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

float ScooterRental::lock()
{
    voltage = 0.0f;
    std::cout << "The scooter voltage is " << voltage << std::endl;
    
    return balance;
}

void ScooterRental::cruiseControl(int targetSpeed)
{
    std::cout << "Engaging cruise control at speed " << targetSpeed << std::endl;
    for( ; speed < targetSpeed; ++speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    for( ; speed > targetSpeed; --speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    if( speed == targetSpeed) std::cout << "Cruisin' at " << speed << "\n";
}

void ScooterRental::printPosition()
{
    std::cout << "Scooter's position is " << this->latitude << ", " << this->longitude << std::endl;
}
