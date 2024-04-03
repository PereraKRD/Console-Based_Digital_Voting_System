#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "Voter.h"
#include "Contester.h"
#include "List.h"

using namespace std;

int main() {                       

    system("cls");

    //login page
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\033[33m";
    cout << "\t\t\t\t\t\t    W E L C O M E\n\n\t\t\t\t\t\t         T O\n\n\t\t\t\t      D I G I T A L   V O T I N G   S Y S T E M !!\n\n\n\n\n\n";
    cout << "\033[90m";
    system("pause");



    List<Voter> voters;
    List<Contester> contesters;
    int voterID = 6;


    //pre-defined voters to the list 
    voters.add(Voter(1, "Bilbo", "Baggins", "01/02/1998", "address 01", 1111));
    voters.add(Voter(2, "Chris", "Barnes", "01/09/1993", "address 02", 1111));
    voters.add(Voter(3, "Holand", "Prego", "02/02/1992", "address 03", 1111));
    voters.add(Voter(4, "Thorin", "Evans", "03/08/1992", "address 04", 1111));
    voters.add(Voter(5, "Durin", "Dwarwen", "05/02/1958", "address 05", 1111));

    //pre-defined contesters to the list
    contesters.add(Contester(1, "Contester A"));
    contesters.add(Contester(2, "Contester B"));
    contesters.add(Contester(3, "Contester C"));
    contesters.add(Contester(4, "Contester D"));
    contesters.add(Contester(5, "Contester E"));


    bool running = true;
    while (running) {
        // Display Main Menu
        system("cls");
        cout << endl;
        cout << "\033[36m";
        cout << "\t\t\t\t\t\t\---M A I N   M E N U---\t\t\t\t\t\t\n\n\n\n\n\n";
        cout << "\033[37m";

        cout << "\t\t\t\t\t\t1. Add Voter\t\t\t\t\n\n";
        cout << "\t\t\t\t\t\t2. Display All Contesters\t\t\t\t\n\n";
        cout << "\t\t\t\t\t\t3. Give Vote\t\t\t\t\n\n";
        cout << "\t\t\t\t\t\t4. Admin Panel\t\t\t\t\n\n";
        cout << "\t\t\t\t\t\t5. Quit\t\t\t\t\n\n\n\n";

        int choice;
        cout << "Enter your choice: ";
        
        try {
            cin >> choice;
            if (cin.fail()) {
                cin.clear();   // clear the fail bit
                cin.ignore();  // discard the invalid input
                cout << endl;
                cout << "\033[31m";
                throw "Invalid input. Please enter an integer value";
                cout << "\033[37m";
            }
            // code to execute when input is valid
        }
        catch (const char* e) {
            cout << endl;
            cout << "\033[31m";
            cout << "Exception : " << e << endl;
            cout << "\033[90m";
            system("pause");
            cout << "\033[37m";
            system("cls");
            continue;
            // code to handle the exception
        }

        switch (choice) {
        case 1: {
            // Add Voter
            system("cls");
            string firstName, lastName, address;
            int pin;
            string dateOfBirth;

            cout << endl;
            cout << "\033[36m";
            cout << "\t\t\t\t\t\t---A D D   V O T E R---\t\t\t\t\t\t\n\n\n";
            cout << "\033[37m";

            cout << "Enter First Name: ";
            cin >> firstName;

            cout << "Enter Last Name: ";
            cin >> lastName;

            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            cin >> dateOfBirth;

            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, address);

            cout << "Enter 4-digit Pin: ";
            try {
                cin >> pin;
                if (cin.fail()) {
                    cin.clear();   // clear the fail bit
                    cin.ignore();  // discard the invalid input
                    cout << endl;
                    cout << "\033[31m";
                    throw "Invalid input. Please enter an integer value.";
                    cout << "\n\n\n";
                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                    break;
                }
                // code to execute when input is valid
            }
            catch (const char* e) {
                cout << "Error: " << e << endl;
                cout << "\033[90m";
                system("pause");
                cout << "\033[37m";
                system("cls");
                continue;
                // code to handle the exception
            }
            Voter voter(voterID, firstName, lastName, dateOfBirth, address, pin);
            voters.add(voter);
            cout << "\033[34m";
            cout << "\nVoter added Successfully..\n\n\n";
            cout << endl;
            cout << "Voter ID is : " << voterID;
            cout << "\033[37m";
            voterID++;
            cout << "\033[90m";
            system("pause");
            cout << "\033[37m";
            system("cls");
            break; }
        case 2:
            // Display All Contesters
        {
            system("cls");

            cout << "\033[36m";
            cout << "\n\t\t\t\t\t\t---C O N T E S T E R S---\t\t\t\t\t\n\n\n";
            cout << "\033[37m";

            contesters.contesterDisplay();

            cout << endl << endl;;

            cout << "\033[90m";
            system("pause");
            cout << "\033[37m";
            break;
        }
        case 3:
            // Give Vote
        {
            int voterID;

            system("cls");

            cout << endl;
            cout << "\033[36m";
            cout << "\t\t\t\t\t\t---V O T I N G   P A N E L---\t\t\t\t\t\t\n\n\n";
            cout << "\033[37m";

            cout << "Enter Voter ID: ";
            try {
                cin >> voterID;
                if (cin.fail()) {
                    cin.clear();   // clear the fail bit
                    cin.ignore();  // discard the invalid input
                    cout << endl;
                    cout << "\033[31m";
                    throw "Invalid input. Please enter an integer value.";
                    cout << "\033[37m";
                }
                // code to execute when input is valid
            }
            catch (const char* e) {
                cout << endl;
                cout << "\033[31m";
                cout << "Error: " << e << endl;
                cout << endl << endl << endl;
                cout << "\033[90m";
                system("pause");
                cout << "\033[37m";
                system("cls");
                continue;
                // code to handle the exception
            }
            int pin;
            cout << "Enter Pin: ";
            try {
                cin >> pin;
                if (cin.fail()) {
                    cin.clear();   // clear the fail bit
                    cin.ignore();  // discard the invalid input
                    cout << endl;
                    cout << "\033[31m";
                    throw "Invalid input. Please enter an integer value.";
                    cout << "\033[37m";
                }
                if (pin < 1000 || pin > 9999) {
                    cout << endl;
                    cout << "\033[31m";
                    throw "Invalid input. Please enter a 4-digit pin.";
                    cout << "\033[37m";
                }
                cout << endl;
                // code to execute after pin is entered
            }
            catch (const char* ex) {
                cout << endl;
                cout << "\033[31m";
                cout << "Exception : " << ex << endl;
                cout << "\n\n\n";
                cout << "\033[90m";
                system("pause");
                cout << "\033[37m";
                system("cls");
                continue;
            }

            Voter* voter = voters.findByID(voterID);
            if (voter->getPin() == pin) {

                Voter* votertemp = voters.findByID(voterID);

                if (!votertemp->getIsVoted()) {
                    contesters.contesterDisplay();
                    cout << "\n\nEnter Contester ID to give vote: ";
                    int contesterID;
                    try {
                        cin >> contesterID;
                        if (cin.fail())
                        {
                            cin.clear();   // clear the fail bit
                            cin.ignore();  // discard the invalid input
                            cout << endl;
                            cout << "\033[31m";
                            throw "Invalid input. Please enter an integer value.";
                            cout << "\033[37m";
                        }
                        // code to execute when input is valid
                    }
                    catch (const char* e)
                    {
                        cout << "\033[31m";
                        cerr << "Exception : " << e << endl;
                        cout << "\033[90m";
                        system("pause");
                        cout << "\033[37m";
                        system("cls");
                        continue;
                        // code to handle the exception
                    }

                    Contester* contestertemp = contesters.findByID(contesterID);
                    contestertemp->vote();
                    votertemp->vote();
                    cout << "\033[34m";
                    cout << "\nVote given successfully!\n\n" << endl;

                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                }
                else {
                    cout << "\033[31m";
                    cout << "\nYou have already given your vote.\n\n" << endl;

                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                }
            }
            else {
                cout << "\nIncorrect Pin!\n\n" << endl;
                cout << "\033[90m";
                system("pause");
                cout << "\033[37m";
            }
            break;
        }
        case 4:
            // Admin Panel
        {
            system("cls");

            string password;
            char c;
            cout << "Enter Admin Password: ";
            while ((c = _getch()) != '\r') {  // loop until the Enter key is pressed
                if (c == '\b') {  // handle backspace characters
                    if (password.size() > 0) {
                        password.pop_back();
                        cout << "\b \b";
                    }
                }
                else {
                    password += c;
                    cout << "*";
                }
            }
            cout << endl;

            if (password == "admin") {
                system("cls");

                cout << endl;
                cout << "\033[36m";
                cout << "\t\t\t\t\t\t---A D M I N   P A N E L---\t\t\t\t\t\n\n\n\n\n\n";
                cout << "\033[37m";

                cout << "\t\t\t\t\t\t1. Display All Voters\n\n";
                cout << "\t\t\t\t\t\t2. Final Result\n\n\n";

                cout << "Enter choice: ";
                int choice;
                try {
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();//   numeric_limits<streamsize>::max(), '\n'
                        cout << endl;
                        cout << "\033[31m";
                        throw "Invalid input. Please enter an integer value.";

                        cout << "\033[90m";
                        system("pause");
                        cout << "\033[37m";

                    }
                    // code to execute when input is valid
                }
                catch (const char* e) {
                    cout << "\033[37m";
                    cout << "Error: " << e << endl << endl;
                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                    system("cls");
                    continue;
                    // code to handle the exception
                }
                switch (choice) {
                case 1:
                {
                    system("cls");
                    cout << "\033[36m";
                    cout << "\n\t\t\t\t\t\t---V O T E R S---\t\t\t\t\t\n\n\n";
                    cout << "\033[37m";

                    voters.voterDisplay();
                    cout << "\n\n\n";
                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                    break;
                }
                case 2:
                    system("cls");
                    cout << "\033[36m";
                    cout << "\n\t\t\t\t\t\t---R E S U L T S---\t\t\t\t\t\n\n\n";
                    cout << "\033[37m";

                    contesters.finalResults();
                    cout << "\n\n\n";
                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                    break;
                default:
                    cout << "\033[31m";
                    cout << "\nInvalid choice\n\n\n";

                    cout << "\033[90m";
                    system("pause");
                    cout << "\033[37m";
                }
            }
            else {
                cout << "\033[31m";
                cout << "\nIncorrect Password!\n\n\n";

                cout << "\033[90m";
                system("pause");
                cout << "\033[37m";
            }
            break;
        }
        case 5:
            // Quit
            system("cls");
            cout << "\033[35m";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t    T H A N K S  F O R  V O T I N G ! !" << "\n\n\n\n\n\n";
            cout << "\033[90m";
            system("pause");
            running = false;
            break;
        default:
            cout << "\033[31m";
            cout << "Invalid choice\n\n";
            cout << "\033[90m";
            system("pause");
            cout << "\033[37m";
            break;
        }
    }
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\033[35m";
    cout << "Program Ended Successfully !!!!!" << endl;
    cout << "\033[37m";
    return 0;
}

