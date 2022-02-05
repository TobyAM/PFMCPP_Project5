#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

struct ScooterRental
{
    ScooterRental();
    ~ScooterRental();
    int distanceTraveled, speed, latitude, longitude;
    float rentalTime, balance, voltage;

    void accelerate(const float throttle);
    void brake(const float brake);
    float lock();
    void cruiseControl(const int targetSpeed);
    void printPosition();

    JUCE_LEAK_DETECTOR(ScooterRental)
};
