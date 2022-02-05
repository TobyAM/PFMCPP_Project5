#include "Wrappers.h"

CoffeeShopWrapper::CoffeeShopWrapper( CoffeeShop* shop) : pointerToShop( shop) { }

CoffeeShopWrapper::~CoffeeShopWrapper()
{
    delete pointerToShop;
}

CustomerWrapper::CustomerWrapper( CoffeeShop::Customer* ptr) : pointer( ptr) { }
CustomerWrapper::~CustomerWrapper()
{
    delete pointer;
}


InvoiceManager::InvoiceWrapper::InvoiceWrapper( InvoiceManager::Invoice* ptr) : pointer( ptr) { }
InvoiceManager::InvoiceWrapper::~InvoiceWrapper()
{
    delete pointer;
}

InvoiceManager::InvoiceWrapper createInvoice(const std::string name, const float date, const std::string type = "post", const float time = 0.0f)
{
    InvoiceManager::InvoiceWrapper newInvoice( new InvoiceManager::Invoice(name) );
    // ++numInvoices;
    // newInvoice.pointer->invoiceNumber = numInvoices;
    newInvoice.pointer->dueDate = date;
    newInvoice.pointer->workType = type;
    newInvoice.pointer->workTime = time;

    return newInvoice;
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
