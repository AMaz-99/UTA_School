/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include "CokeMachine.h"
using namespace std;

int PrintMenu (void){
    int Choice = 0;
    cout <<"0. Walk Away" << endl;
    cout <<"1. Buy A Coke" << endl;
    cout <<"2. Restock Machine" << endl;
    cout <<"3. Add Change" << endl;
    cout <<"4. Display Machine Info" << endl;

    cin >> Choice;
    getchar();
    return Choice;
}


int main () {
    int price, monchange, inventory, Choice = 0;
    string Name;
    cout << "Enter a machine name" << endl;
    getline (cin, Name);
    cout << "Enter the price of a single coke" << endl;
    cin >> price;
    cout << "Enter the amount of change in the machine" << endl;     
    cin >> monchange;
    cout << "Enter the amount of coke already in the machine" << endl;
    cin >> inventory; 
    CokeMachine MyCokeMachine(Name, price, monchange, inventory);
    cout << "\n\n" << MyCokeMachine.getMachineName() << "\n\n" << endl;

    do {
        Choice = PrintMenu();
        cout << endl;
        switch (Choice){
            case 0 : {
                cout << "Are you sure you aren't really THIRSTY and need a Coke?" << endl;
                break;
            }
            case 1 : {
                int payment, action, result = 0;
                string change;
                cout << "Insert Payment (in cents)";
                cin >> payment;
                cout << endl;
                result = MyCokeMachine.buyACoke(payment, change, action);
                if (result == 0){
                    if (action == 1){
                        cout << "We are out of coke. Please try again at a later time.\n" <<endl;
                    }
                    else if (action == 2){
                        cout << "Unable to give change at this time... returning your payment.\n" << endl;
                    }
                    else if (action == 3){
                        cout << "Insufficient payment... returning your payment.\n" << endl;
                    }
                }
                else {
                    if (action == 0){
                        cout << "Here's your coke and your change of " << change << " .\n" << endl;
                        //MyCokeMachine.incrementChangeLevel(payment);
                    }
                    else if (action == 4){
                        cout << "Here's your coke, and thank you for exact  change.\n" << endl;
                        //MyCokeMachine.incrementChangeLevel(payment);
                    }
                }
                break;
            }
            case 2 :{
                int addProduct = 0;
                cout << "How much product are you adding to the machine?  ";
                cin >> addProduct;
                cout << "\n" << endl;
                if (MyCokeMachine.incrementInventory(addProduct) == 1){
                    cout << "Your machine has been restocked.\n" << endl;
                    cout << "Your inventory level is " << MyCokeMachine.getInventoryLevel() << "\n" << endl;
                }
                else{
                    cout << "You have exceeded your machine's maximum capacity.\n" << endl;
                    cout << "Your inventory level is " << MyCokeMachine.getInventoryLevel() << "\n" <<endl;
                }
		        break;
            }
            case 3 :{
                int addChange = 0;
                cout << "How much change are you adding to the machine? ";
                cin >> addChange;
                cout << "\n" << endl;
                if (MyCokeMachine.incrementChangeLevel(addChange) == 1) {
                    cout << "Your change has been updated.\n" << endl;
                    cout << "Your change level is now " << MyCokeMachine.getChangeLevel() << "\n" << endl;
                }
                else{
                    cout << "You have exceed your machine's maximum change capacity.\n" << endl;
                    cout << "Your change level is " << MyCokeMachine.getChangeLevel() << "\n" << endl;
                }                
                break;
            }
            case 4 :{
                cout << "Current Inventory Level: " << MyCokeMachine.getInventoryLevel() << endl;
                cout << "Max Inventory Capacity: " << MyCokeMachine.getMaxInventoryLevelCapacity() << endl;
                cout << "\n\nCurrent Change Level \t" << MyCokeMachine.getChangeLevel() << endl;
                cout << "Max Change Capacity is \t" << MyCokeMachine.getMaxChangeCapacity() << endl;
                cout << "\n\nCurrent Coke Price is \t" << MyCokeMachine.getCokePrice() << endl;     
                break;          
            }
            default :{
                cout << "You did not select a proper menu choice. Please select a proper choice." << endl;
                break;
            }
        }
        cout << "\n\n" << endl;
    } while (Choice);



    return 0;
}
