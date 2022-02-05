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


InvoiceWrapper::InvoiceWrapper( InvoiceManager::Invoice* ptr) : pointer( ptr) { }
InvoiceWrapper::~InvoiceWrapper()
{
    delete pointer;
}

InvoiceWrapper createInvoice(const std::string clientName, const float dueDate, const std::string workType, const float workTime);

InvoiceWrapper createInvoice(const std::string name, const float date, const std::string type = "post", const float time = 0.0f)
{
    InvoiceWrapper newInvoice( new InvoiceManager::Invoice(name) );
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