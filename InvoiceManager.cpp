#include "InvoiceManager.h"

InvoiceManager::InvoiceManager() :
numInvoices(234),
numClients(32),
numTemplates(4),
outBalance(10345.24f),
workType("mastering")
{
    std::cout << "\n+ InvoiceManager constructed!" << std::endl; 
}

InvoiceManager::~InvoiceManager()
{
    std::cout << "\n- InvoiceManager destructed!" << std::endl;
}

InvoiceManager::Invoice::Invoice(std::string name) :
clientName("unknown"),
workType("post"),
workTime(0.0f),
totalBalance(0.0f),
overdue(false)
{
    std::cout << "\n+ InvoiceManager::Invoice constructed:" << std::endl;
    std::cout << "Client name: " << (clientName = name) << std::endl;
    std::cout << "workType: " << workType << std::endl;
    std::cout << "workTime: " << workTime << std::endl;
    std::cout << "totalBalance: $" << totalBalance << std::endl;
    std::cout << "overdue: false\n";
    std::cout << "+++++++++++++++++\n";
    
}

InvoiceManager::Invoice::~Invoice()
{
    std::cout << "\n- InvoiceManager::Invoice destructed:" << std::endl;
    overdue ? std::cout << "overdue! guess you didn't need the $" << totalBalance << std::endl : std::cout << "not overdue!\n";
    std::cout << "-----------------\n";
}

void InvoiceManager::Invoice::download(std::string format = "pdf")
{
    std::cout << "https:\\\\my.freshbooks.com\\invoice." << format << "\n";
}

void InvoiceManager::Invoice::markAsPaid(Invoice& invoiceA)
{
    invoiceA.totalBalance = 0.0f;
    invoiceA.overdue = false;
}

bool InvoiceManager::checkOverdue(const Invoice& invoiceA)
{
    std::cout << "Invoice " << invoiceA.invoiceNumber << " is ";
    if( invoiceA.overdue == false)
    {
        std::cout <<  "not ";
    }
    std::cout << "overdue.\n";

    return invoiceA.overdue;
}

float InvoiceManager::checkBalance(const Invoice& invoiceA)
{
    std::cout << invoiceA.invoiceNumber << " balance is: " << invoiceA.totalBalance << std::endl;

    return invoiceA.totalBalance;

}

void InvoiceManager::printHolidyCards()
{
    std::cout << "Printing holiday cards for all " << numClients << " clients...\n";
    int i = 0;
    while( i < numClients )
    {
        ++i;
        std::cout << "Printing card # " << i << std::endl;
    }

}

void InvoiceManager::printNumInvoices()
{
    std::cout << "tobysInvoices has " << this->numInvoices << std::endl;
}
