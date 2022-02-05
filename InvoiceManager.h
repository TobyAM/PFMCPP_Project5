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

        void download(const std::string format);
        void markAsPaid(Invoice& invoiceA);

        JUCE_LEAK_DETECTOR(Invoice)
    };

};
