/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include "CokeMachine.h"

CokeMachine::CokeMachine (std::string name, int cost, int change, int inventory){
    machineName = name;
    CokePrice = cost;
    changeLevel = change;
    inventoryLevel = inventory;
}

const std::string CokeMachine::getMachineName() const {
    return machineName;
}

bool CokeMachine::buyACoke(const int& payment, std::string& change, int& action) {
    enum ACTION {OK, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE};
    int moneyDisplay = 0;
    ACTION result;
    if (getInventoryLevel == 0){
        result = NOINVENTORY; // result = 1
        action = result;
        return 0;
    }
    if (payment < CokePrice) {
        result = INSUFFICIENTFUNDS; // result = 3
        action = result;
        return 0;
    }
    if ((payment - CokePrice) > changeLevel){
        result = NOCHANGE;  // result = 2
        action = result;
        return 0;
    }
    if (payment == CokePrice ){
        change = "0";
        result = EXACTCHANGE;   // result = 4
        action = result;
        return 1;
    }
    else if (payment > CokePrice){
        change = displayMoney(payment - CokePrice);
        result = OK;    // result = 0
        action = result;
        return 1;
    }
}

int CokeMachine::getInventoryLevel(){
    return inventoryLevel;
}

int CokeMachine::getMaxInventoryLevelCapacity(){
    return maxInventoryCapacity;
}

bool CokeMachine::incrementInventory(int amountToAdd) {
    if ((amountToAdd + InventoryLevel) > maxInventoryCapacity) {
        return 0;
    }
    else {
        InventoryLevel += amountToAdd;
        return 1;
    }
}

const std::string CokeMachine::getChangeLevel() const {
    return std::to_string(changeLevel);
}

bool CokeMachine::incrementChangeLevel(int amountToAdd){
    if ((amountToAdd + changeLevel) > maxChangeCapacity) {
        return 0;
    }
    else {
        changeLevel += amountToAdd;
        return 1;
    }    
}

const std::string CokeMachine::getMaxChangeCapacity() const {
    return std::to_string(maxChangeCapacity);
}

const std::string CokeMachine::getCokePrice() const{
    return std::to_string(CokePrice);
}

const std::string CokeMachine::displayMoney(int& amount) const {
    std::string display;
    int dollar = amount / 100;
    int cents = amount % 100;
    display += "$";
    display += std::to_string(dollar);
    display += "."
    display +- std::to_string(cents);
    return display;
}
