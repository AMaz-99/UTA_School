/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>

#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

class VendingMachine{
    public:
        VendingMachine (std::string, int);
        //Accessors
        virtual int getInventoryLevel() {return 0;};
        virtual int getMaxInventoryLevelCapacity(){return 0;};
        const int getMaxChangeCapacity() const;
        const std::string getMachineName() const;
        const int getChangeLevel() const;
        
        //Mutators
        //>>> bool buyACoke(const int& payment, std::string& change, int& action);
        virtual bool incrementInventory(){return 0;};        
        bool incrementChangeLevel(int amountToAdd);
        void setMachineName(const std::string& newMachineName);

        //Other 
        const std::string displayMoney(int amount) const;
            //returns a string that displays the money in a Dollar.Cents format.
    private:
        std::string machineName;
        int changeLevel{0};
        int maxChangeCapacity{5000};
};

#endif //VENDINGMACHINE_H
