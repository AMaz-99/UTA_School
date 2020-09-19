#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>

#ifndef COKEMACHINE_H
#define COKEMACHINE_H
class CokeMachine{
    friend std::ostream& operator<<(std::ostream&, const CokeMachine&);
    friend std::string CreateCokeOutputLine(const CokeMachine&);   
    public:
        CokeMachine (std::string name = "New Machine", int cost = 50, int change = 500, int inventory = 100);
        ~CokeMachine();
        //Accessors
        int getInventoryLevel();
        int getMaxInventoryLevelCapacity();
        const std::string getMaxChangeCapacity() const;
        const std::string getCokePrice() const;
        const std::string getMachineName() const;
        const std::string getChangeLevel() const;
        
        //Mutators
        bool buyACoke(const int& payment, std::string& change, int& action);
        bool incrementInventory(int amountToAdd);        
        bool incrementChangeLevel(int amountToAdd);
        void setMachineName(const std::string& newMachineName);
        void setCokePrice(int newCokePrice);

        //Other 
        const std::string displayMoney(int amount) const;
            //returns a string that displays the money in a Dollar.Cents format.
    private:
        std::string machineName;
        int changeLevel{0};
        int maxChangeCapacity{5000};
        int CokePrice{0};
        int inventoryLevel{0};
        int maxInventoryCapacity{100};
};

#endif //COKEMACHINE_H
