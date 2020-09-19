#ifndef CokeMachine_H
#define CokeMachine_H
#include <iostream>
#include <string>
#include <cmath>
class CokeMachine{
    public:
        CokeMachine (std::string name, int cost, int change, int inventory){
            machineName = name;
            CokePrice = cost;
            changeLevel = change;
            inventoryLevel = inventory;
        }

        const std::string getMachineName() const{
            return machineName;
        }
        bool buyACoke(const int& payment, std::string& change, int& action){
            enum ACTION {OK, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE};
            int moneyDisplay = 0;
            int pay = 0;
            ACTION result;
            if (getInventoryLevel() == 0){
                result = NOINVENTORY; // result = 1
                action = result;
                return 0;
            }
            if (payment < CokePrice) {
                result = INSUFFICIENTFUNDS; // result = 3
                action = result;
                return 0;
             }
            if (((changeLevel + payment - CokePrice) >= maxChangeCapacity) || ((payment - CokePrice) > changeLevel) || (payment > maxChangeCapacity)){
                result = NOCHANGE;  // result = 2
                action = result;
                return 0;
            }
            if (payment == CokePrice ){
                incrementChangeLevel(payment);
                change = "0";
                result = EXACTCHANGE;   // result = 4
                action = result;
                inventoryLevel--;
                return 1;
            }
            else if (payment > CokePrice){
                incrementChangeLevel(payment);
                change = displayMoney(payment - CokePrice);
                pay = (payment - CokePrice);
                //incrementChangeLevel(CokePrice - payment);
                incrementChangeLevel(-pay);
                result = OK;    // result = 0
                action = result;
                inventoryLevel--;
                return 1;
            }
        }
        int getInventoryLevel(){
            return inventoryLevel;
        }
        int getMaxInventoryLevelCapacity(){
            return maxInventoryCapacity;
        }
        bool incrementInventory(int amountToAdd){
            if ((amountToAdd + inventoryLevel) <= maxInventoryCapacity) {
                inventoryLevel += amountToAdd;
                return 1;

            }
            else {
                return 0;                
            }
        }
        const std::string getChangeLevel() const{
              return displayMoney(changeLevel);
        }
        bool incrementChangeLevel(int amountToAdd){
            if ((amountToAdd + changeLevel) <= maxChangeCapacity) {
                changeLevel = changeLevel + amountToAdd;
                return 1;
            }    
            else {
                return 0;
            }   
        }
        const std::string getMaxChangeCapacity() const{
             return displayMoney(maxChangeCapacity);
        }
        const std::string getCokePrice() const{
             return displayMoney(CokePrice);
        }
        const std::string displayMoney(int amount) const{
            std::string display;
            /* int dollar = amount / 100; 
             int cents = amount % 100 */; // Previous Attempt
            std::string dollars = std::to_string(amount / 100);
            std::string cents= std::to_string(amount % 100);
            display += "$";
            display += dollars;
            display += ".";
            display += cents; 
            /*display += std::to_string(money / 100);
            display += std::to_string(money % 100); */
            return display;
        }

    private:
        std::string machineName;
        int changeLevel{0};
        int maxChangeCapacity{5000};
        int CokePrice{0};
        int inventoryLevel{0};
        int maxInventoryCapacity{100};
};

#endif //CokeMachine_H
