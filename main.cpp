/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
         
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include "LeakedObjectDetector.h"
#include <iostream>
#include "Wrappers.h"
#include "CoffeeShop.h"
#include "InvoiceManager.h"
#include "ScooterRental.h"
#include "Studio.h"
#include "Town.h"

int main()
{
    std::cout << "good to go!" << std::endl;

    std::cout << std::endl; // new UDT

    CoffeeShopWrapper broBucks( new CoffeeShop() );
    CoffeeShop::CustomerWrapper tobyMason( new CoffeeShop::Customer() );

    broBucks.pointerToShop->renameCustomer(*tobyMason.pointer, "Toby Mason");
    broBucks.pointerToShop->grindCoffee(broBucks.pointerToShop->standardBrew, 10, *tobyMason.pointer);
    broBucks.pointerToShop->brewCoffee("Toby Mason", broBucks.pointerToShop->standardBrew, 2, "cold brew", true, false);
    broBucks.pointerToShop->pourCoffee(broBucks.pointerToShop->standardBrew, 3);
    std::cout << "There are " << broBucks.pointerToShop->numBaristas << " baristas working.\n";
    broBucks.pointerToShop->printNumBaristas();

    std::cout << std::endl; // new UDT

    tobyMason.pointer->useRewardsPoints( 130.0f);
    tobyMason.pointer->newMemberPromotion( 3.0f);
    std::cout << "Toby's rewards's balance is now: " << tobyMason.pointer->rewardsBalance << std::endl;
    tobyMason.pointer->printRewardsPoints();
    tobyMason.pointer->useRewardsPoints( 12.0f);
    tobyMason.pointer->useRewardsPoints( 2.0f);
    tobyMason.pointer->contactCustomer();
    tobyMason.pointer->customerPhoneNumber = 3233933291;
    tobyMason.pointer->contactCustomer("k");
    tobyMason.pointer->contactCustomer();

    std::cout << std::endl; // new UDT

    InvoiceManagerWrapper tobyInvoices( new InvoiceManager() );
    InvoiceManager::InvoiceWrapper testInvoice( new InvoiceManager::Invoice("test") );
    std::cout << "tobysInvoices has " << tobyInvoices.pointerToInvoiceManager->numInvoices << std::endl;
    tobyInvoices.pointerToInvoiceManager->printNumInvoices();
    InvoiceManager::InvoiceWrapper testInvoice2( tobyInvoices.pointerToInvoiceManager->createInvoice("test invoice 2", 346255342.0f));
    testInvoice.pointer->invoiceNumber = 5;
    tobyInvoices.pointerToInvoiceManager->checkOverdue(*testInvoice.pointer);
    testInvoice.pointer->totalBalance = 543.21f;
    testInvoice.pointer->overdue = true;
    tobyInvoices.pointerToInvoiceManager->checkBalance(*testInvoice.pointer);
    tobyInvoices.pointerToInvoiceManager->printHolidyCards();
    testInvoice.pointer->download();
    testInvoice.pointer->markAsPaid(*testInvoice.pointer);
    std::cout << "Invoice " << testInvoice.pointer->invoiceNumber << " remaining balance: " << testInvoice.pointer->totalBalance << std::endl;
    
    std::cout << std::endl; // new UDT
    
    ScooterRentalWrapper tobysScooter( new ScooterRental() );

    tobysScooter.pointer->accelerate( 1.5f);
    tobysScooter.pointer->brake(100.0f);
    tobysScooter.pointer->cruiseControl(10);
    tobysScooter.pointer->cruiseControl(4);
    tobysScooter.pointer->lock();
    std::cout << "Scooter's position is " << tobysScooter.pointer->latitude << ", " << tobysScooter.pointer->longitude << std::endl;
    tobysScooter.pointer->printPosition();

    std::cout << std::endl; // new UDT

    TownWrapper weHo( new Town() );
    weHo.pointer->collectTaxes();
    weHo.pointer->quarantine();
    std::cout << "The town coffee shop has a balance of " << weHo.pointer->coffeeShop.balance << std::endl;
    weHo.pointer->printCoffeeShopBalance();

    std::cout << std::endl; // new UDT

    StudioWrapper conway( new Studio() );
    InvoiceManager::InvoiceWrapper kiss( conway.pointer->invoices.createInvoice("Kiss", 999999.9f, "tracking") );
    conway.pointer->orderRun("Toby", *kiss.pointer, conway.pointer->scooterA, -5, 9, "a burger from Le Petite Trois");
    conway.pointer->prepareCoffee("Toby","Gene", conway.pointer->theKitchen.standardBrew, 2, "hot");
    conway.pointer->prepareCoffee("Seth","Paul", conway.pointer->theKitchen.standardBrew, 3, "cold", true, true);
    conway.pointer->prepareCoffee("Seth","Eric", conway.pointer->theKitchen.standardBrew, 3, "hot", false, true);
    std::cout << "There are " << conway.pointer->numInterns << " interns available.\n";
    conway.pointer->printNumInterns();


    std::cout << "\n\n# This is the end of main()\n\n";
}
