#include "InvoiceManager.h"
#include "CoffeeShop.h"
#include "ScooterRental.h"
#include "Studio.h"
#include "Town.h"
#include "Wrappers.h"


CoffeeShopWrapper::CoffeeShopWrapper( CoffeeShop* shop) : pointerToShop( shop) { }

CoffeeShopWrapper::~CoffeeShopWrapper()
{
    delete pointerToShop;
}

InvoiceManager::InvoiceWrapper::InvoiceWrapper( InvoiceManager::Invoice* ptr) : pointer( ptr) { }
InvoiceManager::InvoiceWrapper::~InvoiceWrapper()
{
    delete pointer;
}

InvoiceManagerWrapper::InvoiceManagerWrapper( InvoiceManager* pointer) : pointerToInvoiceManager( pointer) { }
InvoiceManagerWrapper::~InvoiceManagerWrapper()
{
    delete pointerToInvoiceManager;
}

ScooterRentalWrapper::ScooterRentalWrapper( ScooterRental* ptr) : pointer( ptr) { }
ScooterRentalWrapper::~ScooterRentalWrapper()
{
    delete pointer;
}

StudioWrapper::StudioWrapper( Studio* ptr) : pointer( ptr) { }
StudioWrapper::~StudioWrapper()
{
    delete pointer;
}

TownWrapper::TownWrapper( Town* ptr) : pointer( ptr) { }
TownWrapper::~TownWrapper()
{
    delete pointer;
}
