/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "CokeMachine.h"
#include "CokeLib.h"

using namespace std;
int PrintCokeMachines(vector<CokeMachine>&);
int PrintMenu(void);
void get_command_line_params(int, char *[], string&, string&);
void Decision(CokeMachine&, int);

int main(int argc, char *argv[]) {
    int price, monchange, inventory, Choice, Choice2 = 0;
    int CokeChoice;
    string Name, iFileName, oFileName = ""; //Input and Output File Stirngs
    string CokeMachineLine; //To Grab InputFile name lines
    ifstream CokeInputFile; //Input and Output Files
    //ofstream CokeOutputFile; 
    try{
        get_command_line_params(argc, argv, iFileName, oFileName);
    }
    catch (invalid_argument& say) {
        cerr << "Error: " << say.what() << "\n\n";
        exit(1);
    }
    vector<CokeMachine> SetOfCokeMachines;
    vector<string> ConstructorValues (4);

    CokeInputFile.open(iFileName);
    if (CokeInputFile.is_open()){
        while (!CokeInputFile.eof()){
            getline(CokeInputFile, CokeMachineLine);
            ParseCokeLine(CokeMachineLine, ConstructorValues);
            CokeMachine TempMachine(ConstructorValues[0], stoi(ConstructorValues[1]), stoi(ConstructorValues[2]), stoi(ConstructorValues[3]));
            SetOfCokeMachines.push_back (TempMachine);
        }
    }
    else {
        cout << "Error: Unable to open file" << endl;
        exit(1);
    }
    ofstream CokeOutputFile(oFileName, ios::out);
    do{
        CokeChoice = PrintCokeMachines(SetOfCokeMachines);
        if (CokeChoice == -1) { //Finish for Coke Machine Menu Choice 
            if (CokeOutputFile.is_open()){
                int sz;
                for (sz = 0; sz < SetOfCokeMachines.size(); sz++){
                    string temp = CreateCokeOutputLine(SetOfCokeMachines[sz]);
                    CokeOutputFile << temp << endl;
                }
            }
            else {
                cout << "The file did not open" << endl;
            }
        }
        else if (CokeChoice == (SetOfCokeMachines.size())){
            CokeMachine NewCokeMachine;
            SetOfCokeMachines.push_back (NewCokeMachine);
            do{
                Choice2 = PrintMenu();
                cout << endl << endl;
                Decision(SetOfCokeMachines[CokeChoice], Choice2);
                cout << "\n\n" << endl;
            } while (Choice2);
        }
        else if ((CokeChoice < 0) | (CokeChoice > SetOfCokeMachines.size() + 2)) {
            cout << "You entered an invalid option. Please Reconsider." << endl;
        }
        else {
            do{
                Choice = PrintMenu();
                cout << endl;
                Decision(SetOfCokeMachines[CokeChoice], Choice);
                cout << "\n\n" << endl;
            } while (Choice);

        }
    } while (CokeChoice != -1);
    
    CokeInputFile.close();
    CokeOutputFile.close();
    return 0;
}

void Decision(CokeMachine& machine, int Choice){
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
            result = machine.buyACoke(payment, change, action);
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
                }
                else if (action == 4){
                    cout << "Here's your coke, and thank you for exact  change.\n" << endl;
                }
            }
            break;
        }
        case 2 :{
            int addProduct = 0;
            cout << "How much product are you adding to the machine?  ";
            cin >> addProduct;
            cout << "\n" << endl;
            if (machine.incrementInventory(addProduct) == 1){
                cout << "Your machine has been restocked.\n" << endl;
                cout << "Your inventory level is " << machine.getInventoryLevel() << "\n" << endl;
            }
            else{
                cout << "You have exceeded your machine's maximum capacity.\n" << endl;
                cout << "Your inventory level is " << machine.getInventoryLevel() << "\n" <<endl;
            }
            break;
        }
        case 3 :{
            int addChange = 0;
            cout << "How much change are you adding to the machine? ";
            cin >> addChange;
            cout << "\n" << endl;
            if (machine.incrementChangeLevel(addChange) == 1) {
                cout << "Your change has been updated.\n" << endl;
                cout << "Your change level is now " << machine.getChangeLevel() << "\n" << endl;
            }
            else{
                cout << "You have exceed your machine's maximum change capacity.\n" << endl;
                cout << "Your change level is " << machine.getChangeLevel() << "\n" << endl;
            }                
            break;
        }
        case 4 :{
            cout << machine << endl; // DIsable when complete
            break;          
        }
        case 5:{
            string NewName;
            cout << "Enter a new machine name: " << endl;
            getline (cin, NewName);
            machine.setMachineName(NewName);
            cout << "Machine name has been updated." << endl;
            break;
        }
        case 6: {
            int NewPrice;
            cout << "Enter a new coke price" << endl;
            cin >> NewPrice;
            machine.setCokePrice(NewPrice);
            cout << "Coke price has been updated." << endl;
            break;
        }
        default :{
            cout << "You did not select a proper menu choice. Please select a proper choice." << endl;
            break;
        }
    return;
    }
}

int PrintCokeMachines(vector<CokeMachine>& SetOfCokeMachines){
    int choice;
    int temp, size = SetOfCokeMachines.size();
    cout << "Pick a Coke Machine" << endl;
    cout << "0.\tExit" <<endl;
    for (temp = 0; temp < size; temp++ ){
        cout << temp + 1 << ".\t" << SetOfCokeMachines[temp].getMachineName() << endl;
    }
    cout << temp + 1 << ".\tAdd a new machine" << endl;
    cout << "Enter choice" << endl;
    cin >> choice;
    cout << "\n" << endl;
    return choice - 1; 
}

int PrintMenu (void){
    int Choice = 0;
    cout <<"0. Walk Away" << endl;
    cout <<"1. Buy A Coke" << endl;
    cout <<"2. Restock Machine" << endl;
    cout <<"3. Add Change" << endl;
    cout <<"4. Display Machine Info" << endl;
    cout <<"5. Update Machine Name" << endl;
    cout <<"6. Update Coke Price" << endl;
    cin >> Choice;
    getchar();
    return Choice;
}

void get_command_line_params(int argc, char *argv[], string& iFileName, string& oFileName){

	int i;
    string cla; 
	for (i = 1; i < argc; i++)
	{
		cla = argv[i];

		if (cla.substr(0, cla.find("=")) == "INPUTFILENAME")
		{
			iFileName = cla.substr(cla.find("=")+1, cla.length());
		}
		else if (cla.substr(0, cla.find("=")) == "OUTPUTFILENAME")
		{
			oFileName = cla.substr(cla.find("=")+1, cla.length());
		}
	}

	if (iFileName == "" | oFileName == ""){
        throw invalid_argument("Missing command line parameters - - Usage : INPUTFILENAME= OUTPUTFILENAME=");
        return;
    }
	
	return;
}