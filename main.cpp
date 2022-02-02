    /*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/

#if false
Axe axe;
std::cout << "axe sharpness: " << axe.sharpness << "\n";
#endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the  function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */


#include "LeakedObjectDetector.h"
#include <iostream>
/*
 copied UDT 1:
 */
struct CoffeeShop
{
    CoffeeShop();
    ~CoffeeShop();
    int numBaristas, numCoffeeMachines, numRegisters, numCustomers, numTables;
    float balance;
    std::string brewMethod;

    struct Coffee
    {
        Coffee();
        ~Coffee();
        std::string type, roast;
        int coarseness;
        JUCE_LEAK_DETECTOR(Coffee)
    };
    Coffee standardBrew;

    struct Customer
    {
        Customer();
        ~Customer();
        int customerID;
        bool rewardsMember;
        float customerPhoneNumber, rewardsBalance;
        std::string name;

        bool useRewardsPoints(float rewardsPoints);
        void newMemberPromotion(const float incentiveAmount);
        bool contactCustomer(const std::string msg);
        void printRewardsPoints();
        JUCE_LEAK_DETECTOR(Customer)
    };

    Coffee brewCoffee(const std::string customerName, const Coffee& coffeeType, const int size, const std::string brewType, const bool cream, const bool sugar);
    bool grindCoffee(const Coffee& coffeeType, const int coarseness, const Customer& customerA);
    void renameCustomer(Customer& customerA, const std::string newName); // changed to a reference to fix, IDK
    void pourCoffee(const Coffee& coffee, const int size);
    void printNumBaristas();
    JUCE_LEAK_DETECTOR(CoffeeShop)
};

CoffeeShop::CoffeeShop() :
numBaristas(2),
numCoffeeMachines(4),
numRegisters(2),
numCustomers(0),
numTables(12),
balance(0.0f),
brewMethod("pour over")
{
    std::cout << "\n+ CoffeeShop constructed!" << std::endl;  
}

CoffeeShop::~CoffeeShop()
{
    std::cout << "\n- CoffeeShop destructed!" << std::endl;
}

CoffeeShop::Coffee::Coffee() :
type("columbian"),
roast("dark"),
coarseness(1)
{
    std::cout << "\n+ CoffeeShop::Coffee constructed!" << std::endl;  
}

CoffeeShop::Coffee::~Coffee()
{
    std::cout << "\n- CoffeeShop::Coffee destructed!" << std::endl;  
}

CoffeeShop::Customer::Customer() :
customerID(1),
rewardsMember(false),
customerPhoneNumber(0.0f),
rewardsBalance(0.0f),
name("New Customer")
{
    std::cout << "\n+ CoffeeShop::Customer constructed!" << std::endl;  

}

CoffeeShop::Customer::~Customer()
{
    std::cout << "\n- CoffeeShop::Customer destructed!" << std::endl;  

}

struct CustomerWrapper
{
    CustomerWrapper( CoffeeShop::Customer* ptr) : pointer( ptr) { }
    ~CustomerWrapper()
    {
        delete pointer;
    }

    CoffeeShop::Customer* pointer = nullptr;
};

bool CoffeeShop::Customer::contactCustomer(std::string msg = "Your order is ready.")
{
    if( customerPhoneNumber > 0 )
    {
        if( msg.length() > 1 )
        {
            std::cout << "Texting " << name << ": \"" << msg << "\"" << std::endl;
            return true;
        }
        else std::cout << "Message is too short.\n";

    }
    else std::cout << name << " doesn't have a phone number saved.\n";

    return false;
}

bool CoffeeShop::Customer::useRewardsPoints(float rewardsPoints)
{
    if( rewardsMember == true )
    {
        if( rewardsBalance > rewardsPoints )
        {
            rewardsBalance -= rewardsPoints;
            std::cout << name << " used " << rewardsPoints << " points, leaving a balance of " << rewardsBalance << "\n";
            return true;
        }
        else std::cout << name << " doesn't have enough points.\n";

    }
    else std::cout << name << " is not a rewards member!\n";

    return false;
}

void CoffeeShop::Customer::printRewardsPoints()
{
    std::cout << "Toby's rewards's balance is now: " << this->rewardsBalance << std::endl;
}

void CoffeeShop::Customer::newMemberPromotion(float incentiveAmount)
{
    rewardsBalance += incentiveAmount;
    rewardsMember = true;
    contactCustomer("Welcome to the coffee club!");
}

CoffeeShop::Coffee CoffeeShop::brewCoffee(const std::string customerName, const Coffee& coffeeType, const int size, const std::string brewType, const bool cream = false, const bool sugar = false)
{
    std::cout << "New order for " << customerName << ": size " << size << ", " << brewType << ", " << coffeeType.type << ", " << coffeeType.roast;
    if( cream)
    {
        std::cout << ", with cream";
    }

    if( sugar)
    {
        std::cout << ", with sugar";
    }
    
    std::cout << std::endl;

    CoffeeShop::Coffee newCoffee;

    return newCoffee;
}

bool CoffeeShop::grindCoffee(const Coffee& coffeeType, const int coarseness, const Customer& customerA)
{
    for( int i = coffeeType.coarseness; i < coarseness; ++i)
    {
        std::cout << "... grinding coffee to coarseness " << i << std::endl;
    }
    std::cout << "Ground coffee to coarseness " << coarseness << ", " << coffeeType.type << ", " << coffeeType.roast << " for: " << customerA.name << "\n";
    return true;
}

void CoffeeShop::renameCustomer(Customer& customerA, std::string newName)
{
    if( newName.length() > 1)
    {
        std::cout << customerA.name;
        customerA.name = newName;
        std::cout << "'s name changed to: " << customerA.name << "\n";
    
    }
    else
    {
        std::cout << "New name too short.\n";
    }
}

void CoffeeShop::pourCoffee(const Coffee& coffee, const int size)
{
    std::cout << "Pouring coffee...\n";
    for( int i = 1; i < size; ++i)
    {
        if( i == size)
        {
            std::cout << "FULL!\n";
            return;
        }

        std::cout << "Volume at " << i << ", keep pouring... " << std::endl;
    }

    std::cout << "Size " << size << " " << coffee.roast << " " << coffee.type << " coffee poured.\n";
}

void CoffeeShop::printNumBaristas()
{
    std::cout << "There are " << this->numBaristas << " baristas working.\n";
}

struct CoffeeShopWrapper
{
    CoffeeShopWrapper( CoffeeShop* shop) : pointerToShop( shop) { }
    ~CoffeeShopWrapper()
    {
        delete pointerToShop;
    }

    CoffeeShop* pointerToShop = nullptr;
};

/*
 copied UDT 2:
 */
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
        void duplicate(const Invoice& invoiceA);

        JUCE_LEAK_DETECTOR(Invoice)
    };


    Invoice* createInvoice(const std::string clientName, const float dueDate, const std::string workType, const float workTime);
    bool checkOverdue(const Invoice& invoice);
    float checkBalance(const Invoice& invoice);
    void printHolidyCards();
    void printNumInvoices();

    JUCE_LEAK_DETECTOR(InvoiceManager)
};

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

struct InvoiceWrapper
{
    InvoiceWrapper( InvoiceManager::Invoice* ptr) : pointer( ptr) { }
    ~InvoiceWrapper()
    {
        delete pointer;
    }

    InvoiceManager::Invoice* pointer = nullptr;
};

void InvoiceManager::Invoice::download(std::string format = "pdf")
{
    std::cout << "https:\\\\my.freshbooks.com\\invoice." << format << "\n";
}

void InvoiceManager::Invoice::markAsPaid(Invoice& invoiceA)
{
    invoiceA.totalBalance = 0.0f;
    invoiceA.overdue = false;
}

void InvoiceManager::Invoice::duplicate(const Invoice& invoiceA)
{
    Invoice* invoiceB = new Invoice(invoiceA);
    ++invoiceB->invoiceNumber;
    std::cout << "Duplicated invoice " << invoiceA.invoiceNumber << " as " << invoiceB->invoiceNumber << std::endl;
}

InvoiceManager::Invoice* InvoiceManager::createInvoice(const std::string name, const float date, const std::string type = "post", const float time = 0.0f)
{
    Invoice* newInvoice = new Invoice(name);
    ++numInvoices;
    newInvoice->invoiceNumber = numInvoices;
    newInvoice->dueDate = date;
    newInvoice->workType = type;
    newInvoice->workTime = time;

    return newInvoice;
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

struct InvoiceManagerWrapper
{
    InvoiceManagerWrapper( InvoiceManager* pointer) : pointerToInvoiceManager( pointer) { }
    ~InvoiceManagerWrapper()
    {
        delete pointerToInvoiceManager;
    }

    InvoiceManager* pointerToInvoiceManager = nullptr;
};

/*
 copied UDT 3:
 */
struct ScooterRental
{
    ScooterRental();
    ~ScooterRental();
    int distanceTraveled, speed, latitude, longitude;
    float rentalTime, balance, voltage;

    void accelerate(const float throttle);
    void brake(const float brake);
    float lock();
    void cruiseControl(const int targetSpeed);
    void printPosition();

    JUCE_LEAK_DETECTOR(ScooterRental)
};

ScooterRental::ScooterRental() :
distanceTraveled(0),
speed(0),
latitude(3),
longitude(-11),
rentalTime(0.0f),
balance(1.0f),
voltage(100.0f)
{
    std::cout << "\n+ ScooterRental constructed!" << std::endl; 
}

ScooterRental::~ScooterRental()
{
    std::cout << "\n- ScooterRental destructed!" << std::endl; 
}

void ScooterRental::accelerate(float throttle = 0.0f)
{
    voltage = voltage * throttle;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

void ScooterRental::brake(float brake = 0.0f)
{
    voltage -= brake;
    std::cout << "The scooter voltage is " << voltage << std::endl;
}

float ScooterRental::lock()
{
    voltage = 0.0f;
    std::cout << "The scooter voltage is " << voltage << std::endl;
    
    return balance;
}

void ScooterRental::cruiseControl(int targetSpeed)
{
    std::cout << "Engaging cruise control at speed " << targetSpeed << std::endl;
    for( ; speed < targetSpeed; ++speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    for( ; speed > targetSpeed; --speed)
    {
        std::cout << "Current speed: " << speed << ".\n";
    }

    if( speed == targetSpeed) std::cout << "Cruisin' at " << speed << "\n";
}

void ScooterRental::printPosition()
{
    std::cout << "Scooter's position is " << this->latitude << ", " << this->longitude << std::endl;
}

struct ScooterRentalWrapper
{
    ScooterRentalWrapper( ScooterRental* ptr) : pointer( ptr) { }
    ~ScooterRentalWrapper()
    {
        delete pointer;
    }

    ScooterRental* pointer = nullptr;
};

/*
 new UDT 4:
 with 2 member functions
 */
struct Town         
{
    Town();
    ~Town();
    CoffeeShop coffeeShop;
    ScooterRental scooterRental;
    float totalTaxes;

    float collectTaxes();
    void quarantine();
    void printCoffeeShopBalance();

    JUCE_LEAK_DETECTOR(Town)
};

Town::Town()
{
    std::cout << "\n+ Building Town with coffeeShop and a scooter rental!\n";
}

Town::~Town()
{
    std::cout << "\n- Demolishing Town with coffeShop and a scooter rental which earned " << totalTaxes << "!\n";
}

float Town::collectTaxes()
{
float taxes = 0.0f;

std::cout << "Taxing:\n";
std::cout << "coffeeShop with balance of $" << coffeeShop.balance << " for $"<< coffeeShop.balance * 0.3f << std::endl;
std::cout << "scooterRental with balance of $" << scooterRental.balance << " for $" << scooterRental.balance * 0.3f << std::endl;

taxes += coffeeShop.balance * 0.3f + scooterRental.balance * 0.3f;
totalTaxes += taxes;

std::cout << "for a total haul of $" << taxes << (taxes < 1 ? "?" : "!") << std::endl;

coffeeShop.balance *= 0.7f;
scooterRental.balance *= 0.7f;

return taxes;
}

void Town::quarantine()
{
    std::cout << "! Quarantine in effect ! Stay home !\n";
    coffeeShop.numBaristas = 0;
    coffeeShop.numCustomers = 0;
    std::cout << "! Public transportation is free if you need to use it !\n";
    scooterRental.balance = 999999999.0f;
}

void Town::printCoffeeShopBalance()
{
    std::cout << "The town coffee shop has a balance of " << this->coffeeShop.balance << std::endl;
}

struct TownWrapper
{
    TownWrapper( Town* ptr) : pointer( ptr) { }
    ~TownWrapper()
    {
        delete pointer;
    }

    Town* pointer = nullptr;
};

/*
 new UDT 5:
 with 2 member functions
 */
struct Studio
{
    Studio();
    ~Studio();
    int numInterns, numAssistants;
    float balance;
    CoffeeShop theKitchen;
    ScooterRental scooterA, scooterB;
    InvoiceManager invoices;

    void orderRun(const std::string runner, const InvoiceManager::Invoice& invoice, const ScooterRental& scooter, const int latCoord, const int longCoord, const std::string order);
    void prepareCoffee(const std::string runner, const std::string clientName, const CoffeeShop::Coffee& coffeeType, const int size, const std::string brewType, const bool cream, const bool sugar);
    void printNumInterns();

    JUCE_LEAK_DETECTOR(Studio)
};

Studio::Studio() :
numInterns(4),
numAssistants(3),
balance(10000.0f)
{
    std::cout << "\n+ Constructed Studio!\n";
}

Studio::~Studio()
{
    std::cout << "\n- Destructing Studio!\n";
}

void Studio::orderRun(const std::string runner, const InvoiceManager::Invoice& invoice, const ScooterRental& scooter, const int latCoord, const int longCoord, const std::string order)
{
    std::cout << "Hey " << runner << " you need to go to grab " << order << " for " << invoice.clientName << ".\n";
    std::cout << "Here's a map, X marks the spot U need to go to:\n";
    int longRectified = longCoord + 18;
    int latRectified = latCoord + 18;
    int scooterLongRectified = scooter.longitude + 18;
    int scooterLatRectified = scooter.latitude + 18;
    
    for(int x = 1; x <= 37; ++x)
    {
        std::cout << "==";
    }
    std::cout << std::endl;

    for(int y = 1; y <= 36; ++y)
    {
        std::cout << "||";
        for(int x = 1; x <= 36; ++x)
        {
            if(x == longRectified && y == latRectified) std::cout << "X ";
            else if(x == scooterLongRectified && y == scooterLatRectified) std::cout << "U ";
            else if(x == 36) std::cout << "||";
            else std::cout << "  ";
        }
        
        std::cout << std::endl;
    }
    for(int x = 1; x <= 37; ++x)
    {
        std::cout << "==";
    }

    std::cout << std::endl;
 
    balance += scooter.balance;
   
}

void Studio::prepareCoffee(const std::string runner, const std::string clientName, const CoffeeShop::Coffee& coffeeType, const int size, const std::string brewType, const bool cream = false, const bool sugar = false)
{
    std::cout << "Hey " << runner << ", you need to make a " << brewType << " size " << size << " " << coffeeType.type << " coffee" << (cream && sugar ? " with cream and sugar" : (cream ? " with cream " : (sugar ? " with sugar" : ""))) << " for " << clientName << std::endl;
    theKitchen.brewCoffee(clientName, coffeeType, size, brewType, cream, sugar);
}

void Studio::printNumInterns()
{
    std::cout << "There are " << this->numInterns << " interns available.\n";
}

struct StudioWrapper
{
    StudioWrapper( Studio* ptr) : pointer( ptr) { }
    ~StudioWrapper()
    {
        delete pointer;
    }

    Studio* pointer = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    std::cout << "good to go!" << std::endl;

    std::cout << std::endl; // new UDT

    CoffeeShopWrapper broBucks( new CoffeeShop() );
    CustomerWrapper tobyMason( new CoffeeShop::Customer() );

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
    InvoiceWrapper testInvoice( new InvoiceManager::Invoice("test") );
    std::cout << "tobysInvoices has " << tobyInvoices.pointerToInvoiceManager->numInvoices << std::endl;
    tobyInvoices.pointerToInvoiceManager->printNumInvoices();
    // tobyInvoices.pointerToInvoiceManager->createInvoice("test invoice 2", 346255342.0f);
    testInvoice.pointer->invoiceNumber = 5;
    tobyInvoices.pointerToInvoiceManager->checkOverdue(*testInvoice.pointer);
    testInvoice.pointer->totalBalance = 543.21f;
    testInvoice.pointer->overdue = true;
    tobyInvoices.pointerToInvoiceManager->checkBalance(*testInvoice.pointer);
    tobyInvoices.pointerToInvoiceManager->printHolidyCards();
    testInvoice.pointer->download();
    testInvoice.pointer->markAsPaid(*testInvoice.pointer);
    std::cout << "Invoice " << testInvoice.pointer->invoiceNumber << " remaining balance: " << testInvoice.pointer->totalBalance << std::endl;
    // testInvoice.pointer->duplicate(testInvoice.pointer); don't know how to fix this for pointers

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
    InvoiceWrapper kiss( conway.pointer->invoices.createInvoice("Kiss", 999999.9f, "tracking") );
    conway.pointer->orderRun("Toby", *kiss.pointer, conway.pointer->scooterA, -5, 9, "a burger from Le Petite Trois");
    conway.pointer->prepareCoffee("Toby","Gene", conway.pointer->theKitchen.standardBrew, 2, "hot");
    conway.pointer->prepareCoffee("Seth","Paul", conway.pointer->theKitchen.standardBrew, 3, "cold", true, true);
    conway.pointer->prepareCoffee("Seth","Eric", conway.pointer->theKitchen.standardBrew, 3, "hot", false, true);
    std::cout << "There are " << conway.pointer->numInterns << " interns available.\n";
    conway.pointer->printNumInterns();


    std::cout << "\n\n# This is the end of main()\n\n";
}
