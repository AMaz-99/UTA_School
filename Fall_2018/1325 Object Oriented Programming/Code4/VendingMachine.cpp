/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>
#include "VendingMachine.h"


//Constructor
VendingMachine::VendingMachine (std::string name, int change){
    machineName = name;
    changeLevel = change;
}


//Accessors
const std::string VendingMachine::getMachineName() const {
    return machineName;
}

const int VendingMachine::getChangeLevel() const {
    return changeLevel;
}

const int VendingMachine::getMaxChangeCapacity() const {
    return maxChangeCapacity;
}

//Mutators
void VendingMachine::setMachineName(const std::string& newMachineName){
    machineName = newMachineName;
}


bool VendingMachine::incrementChangeLevel(int amountToAdd){
    if ((amountToAdd + changeLevel) <= maxChangeCapacity) {
        changeLevel += amountToAdd;
        return 1;
    }
    else {
        return 0;
    }    
}

//Others
const std::string VendingMachine::displayMoney(int amount) const {
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
