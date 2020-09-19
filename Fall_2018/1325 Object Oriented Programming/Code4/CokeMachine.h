/* Aamir Mazumdar 1001523593 */
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>
#include "VendingMachine.h"

#ifndef COKEMACHINE_H
#define COKEMACHINE_H

class CokeMachine : public VendingMachine{
    friend std::ostream& operator<<(std::ostream&, const CokeMachine&);
    friend std::string CreateCokeOutputLine(const CokeMachine&);   
    public:
        CokeMachine (std::string name = "New Machine", int cost = 50, int change = 500, int inventory = 100);
        //Accessors
        int getInventoryLevel();
        int getMaxInventoryLevelCapacity();
        const std::string getCokePrice() const;
        
        
        //Mutators
        bool buyACoke(const int& payment, std::string& change, int& action);
        bool incrementInventory(int amountToAdd);        
        void setCokePrice(int newCokePrice);


    private:
        int CokePrice{0};
        int inventoryLevel{0};
        int maxInventoryCapacity{100};
};

#endif //COKEMACHINE_H
