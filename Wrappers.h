#pragma once

#include <iostream>
#include "CoffeeShop.h"
#include "InvoiceManager.h"
#include "ScooterRental.h"
#include "Studio.h"
#include "Town.h"

struct CoffeeShopWrapper
{
    CoffeeShopWrapper( CoffeeShop* shop) : pointerToShop( shop) { }
    ~CoffeeShopWrapper()
    {
        delete pointerToShop;
    }

    CoffeeShop* pointerToShop = nullptr;
};

struct CustomerWrapper
{
    CustomerWrapper( CoffeeShop::Customer* ptr) : pointer( ptr) { }
    ~CustomerWrapper()
    {
        delete pointer;
    }

    CoffeeShop::Customer* pointer = nullptr;
};

InvoiceManager::InvoiceWrapper InvoiceManager::createInvoice(const std::string name, const float date, const std::string type = "post", const float time = 0.0f)
{
    InvoiceWrapper newInvoice( new Invoice(name) );
    ++numInvoices;
    newInvoice.pointer->invoiceNumber = numInvoices;
    newInvoice.pointer->dueDate = date;
    newInvoice.pointer->workType = type;
    newInvoice.pointer->workTime = time;

    return newInvoice;
}

struct InvoiceManagerWrapper
{
    InvoiceManagerWrapper( InvoiceManager* pointer) : pointerToInvoiceManager( pointer) { }
    ~InvoiceManagerWrapper()
    {
        delete pointerToInvoiceManager;
    }

    InvoiceManager* pointerToInvoiceManager = nullptr;
};

struct InvoiceWrapper
    {
        InvoiceWrapper( Invoice* ptr) : pointer( ptr) { }
        ~InvoiceWrapper()
        {
            delete pointer;
        }

        Invoice* pointer = nullptr;
    };

    InvoiceWrapper createInvoice(const std::string clientName, const float dueDate, const std::string workType, const float workTime);
    bool checkOverdue(const Invoice& invoice);
    float checkBalance(const Invoice& invoice);
    void printHolidyCards();
    void printNumInvoices();

    JUCE_LEAK_DETECTOR(InvoiceManager)

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

