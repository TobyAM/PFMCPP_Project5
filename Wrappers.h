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

struct InvoiceWrapper
{
    InvoiceWrapper( InvoiceManager::Invoice* ptr);

    InvoiceWrapper createInvoice(const std::string clientName, const float dueDate, const std::string workType, const float workTime);

    InvoiceManager::Invoice* pointer = nullptr;
};

struct InvoiceManagerWrapper
{
    InvoiceManagerWrapper( InvoiceManager* pointer) : pointerToInvoiceManager( pointer) { }
    ~InvoiceManagerWrapper()
    {
        delete pointerToInvoiceManager;
    }

    InvoiceManager* pointerToInvoiceManager = nullptr;
};

struct ScooterRentalWrapper
{
    ScooterRentalWrapper( ScooterRental* ptr) : pointer( ptr) { }
    ~ScooterRentalWrapper()
    {
        delete pointer;
    }

    ScooterRental* pointer = nullptr;
};

struct StudioWrapper
{
    StudioWrapper( Studio* ptr) : pointer( ptr) { }
    ~StudioWrapper()
    {
        delete pointer;
    }

    Studio* pointer = nullptr;
};

struct TownWrapper
{
    TownWrapper( Town* ptr) : pointer( ptr) { }
    ~TownWrapper()
    {
        delete pointer;
    }

    Town* pointer = nullptr;
};
