#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
// struct InvoiceWrapper;

struct InvoiceManager
{
    InvoiceManager();
    ~InvoiceManager();
    int numInvoices, numClients, numTemplates;
    float outBalance;
    std::string workType;

    struct Invoice
    {
        Invoice(std::string name);
        ~Invoice();
        std::string clientName, workType;
        int invoiceNumber;
        float workTime, totalBalance, dueDate;
        bool overdue;

        void download(const std::string format);
        void markAsPaid(Invoice& invoiceA);

        JUCE_LEAK_DETECTOR(Invoice)
    };

bool checkOverdue(const Invoice& invoice);
float checkBalance(const Invoice& invoice);
void printHolidyCards();
void printNumInvoices();

JUCE_LEAK_DETECTOR(InvoiceManager)
};
