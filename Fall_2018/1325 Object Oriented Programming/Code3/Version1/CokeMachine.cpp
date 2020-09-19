/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>
#include "CokeMachine.h"

std::ostream& operator<<(std::ostream& output, const CokeMachine& machine){
    output << "\nMachine name:\t\t" << machine.machineName
           << "\nCurrent Inventory Level:" << machine.inventoryLevel
           << "\nMax Inventory Capacity: " << machine.maxInventoryCapacity
           << "\n\nCurrent Change Level: \t" << machine.getChangeLevel()
           << "\nMax Change Capacity is: " << machine.maxChangeCapacity
           << "\n\n\nCurrent Coke Price is \t" << machine.getCokePrice() << "\n";
    return output;
}

//Constructor
CokeMachine::CokeMachine (std::string name, int cost, int change, int inventory){
    machineName = name;
    CokePrice = cost;
    changeLevel = change;
    inventoryLevel = inventory;
}

//Destructor
CokeMachine::~CokeMachine(){
    std::cout << "Coke Machine " << machineName << " has been destroyed.\n" << std::endl; 
}

//Accessors
const std::string CokeMachine::getMachineName() const {
    return machineName;
}

int CokeMachine::getInventoryLevel(){
    return inventoryLevel;
}

int CokeMachine::getMaxInventoryLevelCapacity(){
    return maxInventoryCapacity;
}

const std::string CokeMachine::getChangeLevel() const {
    return displayMoney(changeLevel);
}

const std::string CokeMachine::getMaxChangeCapacity() const {
    return displayMoney(maxChangeCapacity);
}

const std::string CokeMachine::getCokePrice() const{
    return displayMoney(CokePrice);
}

//Mutators
void CokeMachine::setMachineName(const std::string& newMachineName){
    machineName = newMachineName;
}

void CokeMachine::setCokePrice(int newCokePrice){
    CokePrice = newCokePrice;
}

bool CokeMachine::buyACoke(const int& payment, std::string& change, int& action) {
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

bool CokeMachine::incrementInventory(int amountToAdd) {
    if ((amountToAdd + inventoryLevel) <= maxInventoryCapacity) {
        inventoryLevel += amountToAdd;
        return 1;
    }
    else {
        return 0;                
    }
}

    


bool CokeMachine::incrementChangeLevel(int amountToAdd){
    if ((amountToAdd + changeLevel) <= maxChangeCapacity) {
        changeLevel += amountToAdd;
        return 1;
    }
    else {
        return 0;
    }    
}

std::string CreateCokeOutputLine(const CokeMachine& machine){
    std::string outputline;
    outputline+=machine.machineName;
    outputline+="|";
    outputline+= std::to_string(machine.CokePrice); 
    outputline+="|";
    outputline+= std::to_string(machine.changeLevel);
    outputline+= "|"; 
    outputline+= std::to_string(machine.inventoryLevel);
    return outputline;
}
//Others
const std::string CokeMachine::displayMoney(int amount) const {
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
