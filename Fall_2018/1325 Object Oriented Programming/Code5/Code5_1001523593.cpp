/* Aamir Mazumdar 1001523593 */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <map>
#include <gtkmm.h>
#include "VendingMachine.h"
#include "CokeMachine.h"
#include "CokeLib.h"

using namespace std;

int PrintCokeMachines(vector<CokeMachine>&);
int PrintMenu(void);
void get_command_line_params(int, char *[], string&, string&);
void Decision(CokeMachine&, int, map<string, int>&);
void PrintRecipt(const map<string, int>&);
int BuyCokeGtk (void);
int Restock(void);
int ChangeGtk(void);
string UpdateNameGtk(void);
int PriceGtk(void);

int main(int argc, char *argv[]) {
    Gtk::Main kit(argc, argv);
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

    map<string, int> Receipt;
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
                Decision(SetOfCokeMachines[CokeChoice], Choice2, Receipt);
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
                Decision(SetOfCokeMachines[CokeChoice], Choice, Receipt);
                cout << "\n\n" << endl;
            } while (Choice);

        }
    } while (CokeChoice != -1);
    
    CokeInputFile.close();
    CokeOutputFile.close();
    PrintRecipt(Receipt);
    return 0;
}
// Gtk Functions 

int BuyCokeGtk (void){
    string paid;
    Gtk::Dialog *Payment = new Gtk::Dialog {"Payment"};
    Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
    MyEntry->set_text("Enter Payment");
    MyEntry->set_max_length(50);
    MyEntry->show();
    Payment->add_button("Cancel", 0);
    Payment->add_button("OK", 1);
    Payment->get_vbox()->pack_start(*MyEntry);
    int choice = Payment->run();
    paid = MyEntry->get_text();
    Payment->close();
    delete Payment;
    int result = stoi(paid);
    return result;
}

int Restock(void){
    string stock;
    Gtk::Dialog *reStock1 = new Gtk::Dialog {"Restock"};
    Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
    MyEntry->set_text("Enter restock quantity");
    MyEntry->set_max_length(50);
    MyEntry->show();
    reStock1->add_button("Cancel", 0);
    reStock1->add_button("OK", 1);
    reStock1->get_vbox()->pack_start(*MyEntry);
    int choice = reStock1->run();
    stock = MyEntry->get_text();
    reStock1->close();
    delete reStock1;
    int result = stoi(stock);
    return result;
}

int ChangeGtk(void) {
    string change;
    Gtk::Dialog *ADDCHANGE = new Gtk::Dialog {"Add Change"};
    Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
    MyEntry->set_text("Enter change to be added to the Machine");
    MyEntry->set_max_length(50);
    MyEntry->show();
    ADDCHANGE->add_button("Cancel", 0);
    ADDCHANGE->add_button("OK", 1);
    ADDCHANGE->get_vbox()->pack_start(*MyEntry);
    int choice = ADDCHANGE->run();
    change = MyEntry->get_text();
    ADDCHANGE->close();
    delete ADDCHANGE;
    int result = stoi(change);
    return result;
}

string UpdateNameGtk(void){
    string name;
    Gtk::Dialog *NAMEGTK = new Gtk::Dialog {"New Name"};
    Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
    MyEntry->set_text("Enter new machine name");
    MyEntry->set_max_length(50);
    MyEntry->show();
    NAMEGTK->add_button("Cancel", 0);
    NAMEGTK->add_button("OK", 1);
    NAMEGTK->get_vbox()->pack_start(*MyEntry);
    int choice = NAMEGTK->run();
    name = MyEntry->get_text();
    NAMEGTK->close();
    delete NAMEGTK;
    return name;    
}

int PriceGtk(void){
    string newprice;
    Gtk::Dialog *PRICE = new Gtk::Dialog {"New Price"};
    Gtk::Entry *MyEntry = Gtk::manage(new Gtk::Entry());
    MyEntry->set_text("Enter the new price");
    MyEntry->set_max_length(50);
    MyEntry->show();
    PRICE->add_button("Cancel", 0);
    PRICE->add_button("OK", 1);
    PRICE->get_vbox()->pack_start(*MyEntry);
    int choice = PRICE->run();
    newprice = MyEntry->get_text();
    PRICE->close();
    delete PRICE;
    int result = stoi(newprice);
    return result;
}
void Decision(CokeMachine& machine, int Choice, map<string, int>& receipt){
    switch (Choice){
        case 0 : {
            //cout << "" << endl;
            string messageDlg = "Are you sure you aren't really THIRSTY and need a Coke?\n";
            Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
            MyMessageDialog->run();
            MyMessageDialog->close();
            delete MyMessageDialog;
            break;
        }
        case 1 : {
            int payment, action, result = 0;
            string change, messageDlg = "";
            payment = BuyCokeGtk();
            result = machine.buyACoke(payment, change, action);
            if (result == 0){
                if (action == 1){
                    messageDlg = "We are out of coke. Please try again at a later time.\n";
                    Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                    MyMessageDialog->run();
                    MyMessageDialog->close();
                    delete MyMessageDialog;
                }
                else if (action == 2){
                    messageDlg = "Unable to give change at this time... returning your payment.\n";
                    Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                    MyMessageDialog->run();
                    MyMessageDialog->close();
                    delete MyMessageDialog;
                }
                else if (action == 3){
                    messageDlg = "Insufficient payment... returning your payment.\n";
                    Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                    MyMessageDialog->run();
                    MyMessageDialog->close();
                    delete MyMessageDialog;
                }
            }
            else {
                if (action == 0){
                    messageDlg = "Here's your coke and your change of "; 
                    messageDlg += change; 
                    messageDlg +=" .\n";
                    receipt[machine.getMachineName()]++;
                    Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                    MyMessageDialog->run();
                    MyMessageDialog->close();
                    delete MyMessageDialog;
                }
                else if (action == 4){
                    messageDlg = "Here's your coke, and thank you for exact  change.\n";
                    Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                    MyMessageDialog->run();
                    MyMessageDialog->close();
                    delete MyMessageDialog;
                    receipt[machine.getMachineName()]++;
                }
            }
            break;
        }
        case 2 :{
            string messageDlg = "";
            int addProduct = Restock();
            if (machine.incrementInventory(addProduct) == 1){
                messageDlg = "Your machine has been restocked.\n";
                Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                MyMessageDialog->run();
                MyMessageDialog->close();
                delete MyMessageDialog;
            }
            else{
                messageDlg = "You have exceeded your machine's maximum capacity.\n";
                Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                MyMessageDialog->run();
                MyMessageDialog->close();
                delete MyMessageDialog;
            }
            break;
        }
        case 3 :{
            int addChange = ChangeGtk();
            string messageDlg = "";
            if (machine.incrementChangeLevel(addChange) == 1) {
                messageDlg = "Your change has been updated.\n";
                Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                MyMessageDialog->run();
                MyMessageDialog->close();
                delete MyMessageDialog;
            }
            else{
                messageDlg = "You have exceed your machine's maximum change capacity.\n";
                Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
                MyMessageDialog->run();
                MyMessageDialog->close();
                delete MyMessageDialog;
            }                
            break;
        }
        case 4 :{
            ostringstream temp;
            temp << machine << endl; // DIsable when complete
            string messageDlg = temp.str();
            Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
            MyMessageDialog->run();
            MyMessageDialog->close();
            delete MyMessageDialog;  
            break;          
        }
        case 5:{
            string NewName = UpdateNameGtk();
            machine.setMachineName(NewName);
            string messageDlg = "Machine name has been updated.\n";
            Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
            MyMessageDialog->run();
            MyMessageDialog->close();
            delete MyMessageDialog;             
            break;
        }
        case 6: {
            string messageDlg;
            int NewPrice = PriceGtk();
            machine.setCokePrice(NewPrice);
            messageDlg ="Coke price has been updated.\n";
            Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
            MyMessageDialog->run();
            MyMessageDialog->close();
            delete MyMessageDialog; 
            break;
        }
        default :{
            string messageDlg = "You did not select a proper menu choice. Please select a proper choice.\n";
            Gtk::MessageDialog *MyMessageDialog = new Gtk::MessageDialog{messageDlg, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false};
            MyMessageDialog->run();
            MyMessageDialog->close();
            delete MyMessageDialog; 
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
    /*for (temp = 0; temp < size; temp++ ){
        cout << temp + 1 << ".\t" << SetOfCokeMachines[temp].getMachineName() << endl;
    }*/
    temp = 0;
    for (auto it : SetOfCokeMachines){
        cout << temp + 1 << ".\t" << it.getMachineName() << endl;
        temp++;
    }
    cout << temp + 1 << ".\tAdd a new machine" << endl;
    cout << "Enter choice" << endl;
    cin >> choice;
    cout << "\n" << endl;
    return choice - 1; 
}

int PrintMenu (void){
    int i, Choice = 0;
/*    cout <<"0. Walk Away" << endl;
    cout <<"1. Buy A Coke" << endl;
    cout <<"2. Restock Machine" << endl;
    cout <<"3. Add Change" << endl;
    cout <<"4. Display Machine Info" << endl;
    cout <<"5. Update Machine Name" << endl;
    cout <<"6. Update Coke Price" << endl;
    cin >> Choice;
    getchar(); */
    Gtk::Dialog *MyDialog = new Gtk::Dialog();
    MyDialog->set_title("Choices");
    vector<string> buttons = {"Cancel","Buy A Coke", "Restock Machine", "Add Change", "Display Machine Info", "Update Machine Name", "Update Coke Price"};
    for (int i = 0; i < buttons.size(); i++){
        MyDialog->add_button(buttons[i], i);
    }
    MyDialog->set_default_response(0);
    Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("What do you want to do?"));
    MyDialog->get_vbox()->pack_start(*MyLabel);
    MyLabel->show();
    Choice = MyDialog->run();
    MyDialog->close();
    delete MyDialog;
    return Choice;
}

void PrintRecipt(const map<string, int>& receipt) {
    cout << "Here is your receipt: \n" << endl;
    for (auto it : receipt){
        cout << it.first << "\t" << it.second << endl;
    }
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