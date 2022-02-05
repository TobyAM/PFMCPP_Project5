#pragma once

#include <iostream>
#include "CoffeeShop.h"
#include "InvoiceManager.h"
#include "ScooterRental.h"
#include "Studio.h"
#include "Town.h"

struct CoffeeShopWrapper
{
    CoffeeShopWrapper(CoffeeShop* shop);
    ~CoffeeShopWrapper();

    CoffeeShop* pointerToShop = nullptr;
};

struct CustomerWrapper
{
    CustomerWrapper( CoffeeShop::Customer* ptr);
    ~CustomerWrapper();


    CoffeeShop::Customer* pointer = nullptr;
};

struct InvoiceManagerWrapper
{
    InvoiceManagerWrapper( InvoiceManager* pointer);
    ~InvoiceManagerWrapper();

    InvoiceManager* pointerToInvoiceManager = nullptr;
};

struct ScooterRentalWrapper
{
    ScooterRentalWrapper( ScooterRental* ptr);
    ~ScooterRentalWrapper();

    ScooterRental* pointer = nullptr;
};

struct StudioWrapper
{
    StudioWrapper( Studio* ptr);
    ~StudioWrapper();

    Studio* pointer = nullptr;
};

struct TownWrapper
{
    TownWrapper( Town* ptr);
    ~TownWrapper();

    Town* pointer = nullptr;
};
