#pragma once
struct CoffeeShop;
struct InvoiceManager;
struct ScooterRental;
struct Studio;
struct Town;

struct CoffeeShopWrapper
{
    CoffeeShopWrapper(CoffeeShop* shop);
    ~CoffeeShopWrapper();
    CoffeeShop* pointerToShop = nullptr;
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
