#include "CoffeeShop.h"

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
