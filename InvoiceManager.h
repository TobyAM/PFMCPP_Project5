#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

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

        void download(const std::string format = "pdf");
        void markAsPaid(Invoice& invoiceA);

        JUCE_LEAK_DETECTOR(Invoice)
    };

    struct InvoiceWrapper
    {
        InvoiceWrapper( Invoice* ptr);
        ~InvoiceWrapper();

        Invoice* pointer = nullptr;
    };

    InvoiceWrapper createInvoice(const std::string clientName, const float dueDate,  const std::string type = "post", const float time = 0.0f );
    bool checkOverdue(const Invoice& invoice);
    float checkBalance(const Invoice& invoice);
    void printHolidyCards();
    void printNumInvoices();

    JUCE_LEAK_DETECTOR(InvoiceManager)
};
