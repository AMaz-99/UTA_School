/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>
#include "CokeMachine.h"

//Friends
std::ostream& operator<<(std::ostream& output, const CokeMachine& machine){
    std::string name = machine.getMachineName();
    int inventory = machine.inventoryLevel;
    int maxInventory = machine.maxInventoryCapacity;
    std::string change = machine.displayMoney(machine.getChangeLevel());
    std::string maxChange = machine.displayMoney(machine.getMaxChangeCapacity());
    std::string price = machine.getCokePrice();

    output << "\nMachine name:\t\t" << name
           << "\nCurrent Inventory Level:" << inventory
           << "\nMax Inventory Capacity: " << maxInventory
           << "\n\nCurrent Change Level: \t" << change
           << "\nMax Change Capacity is: " << maxChange
           << "\n\n\nCurrent Coke Price is \t" << price << "\n";
    return output;
}


std::string CreateCokeOutputLine(const CokeMachine& machine){
    std::string outputline;
    std::string temp;
    temp = machine.getMachineName();
    outputline+=temp;
    outputline+="|";
    temp = machine.getCokePrice();
    outputline+= temp; 
    outputline+="|";
    temp = machine.displayMoney(machine.getChangeLevel());
    outputline+= temp;
    outputline+= "|"; 
    outputline+= std::to_string(machine.inventoryLevel);
    return outputline;
}

//Constructor
CokeMachine::CokeMachine (std::string name, int cost, int change,
 int inventory) : VendingMachine(name, change){
    setCokePrice(cost);
    inventoryLevel = inventory;
}

//Accessors

int CokeMachine::getInventoryLevel(){
    return inventoryLevel;
}

int CokeMachine::getMaxInventoryLevelCapacity(){
    return maxInventoryCapacity;
}

const std::string CokeMachine::getCokePrice() const{
    return displayMoney(CokePrice);
}

//Mutators

void CokeMachine::setCokePrice(int newCokePrice){
    CokePrice = newCokePrice;
}

bool CokeMachine::buyACoke(const int& payment, std::string& change, int& action) {
    enum ACTION {OK, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE};
    int moneyDisplay = 0;
    int pay = 0;
    ACTION result;
    int changeLevels = getChangeLevel();
    int maxChange = getMaxChangeCapacity();
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
    if (((changeLevels + payment - CokePrice) >= maxChange) || ((payment - CokePrice) > changeLevels) || (payment > maxChange)){
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

bool CokeMachine::incrementInventory(int amountToAdd) {
    if ((amountToAdd + inventoryLevel) <= maxInventoryCapacity) {
        inventoryLevel += amountToAdd;
        return 1;
    }
    else {
        return 0;                
    }
}


