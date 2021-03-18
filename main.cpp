#include "main.h"
#include "listProcess.h"
#include "displayProcess.h"

using namespace std;

int main(int argc, char** argv) {

    studentProcess * studentData = new studentProcess();
	
    system("CLS");
    
    int check_exit = 0;
    int re_run = 0;
    int rejump;

    do {
        string name;
        int id;
        char exit_confirm;
        int option = -1;
        int check_func = -1;
        int load = 0;

        if (re_run == 1) option = rejump; //Run the function again when there is error in the previous run

        else { // Else run from start 
            displaymenu_student();
            cin >> option;
        }

        switch(option) {
            case 0:
                check_exit = 1;
                break;

            case 1:
                system("CLS");
                // INPUT USER INFORMATION
                display_addstudent();
                Sleep(1000);
                cout << "\n";
                cout << "Enter student's name: ";
                cin.clear();
                cin.ignore();
                getline(cin, name);
                cout << "Enter student's ID: ";
                cin.clear();
                cin.ignore();
                cin >> id;
                
                // ADD STUDENT
                check_func = studentData->insertStudent(name, id);
                
                while (load < 3) {
                    cout << "\n.";
                    Sleep(500);
                    load++;
                }
                // INFORM
                if (check_func == 1) {
                    cout << "\nPlease insert again.";
                    re_run = 1;
                    Sleep(2000);
                    system("CLS");
                    break;
                }
                else {
                    cout << "\nStudent added successfully!";
                    Sleep(1000);
                }

                cout << "\n\nDo you want to run again? (Y/N): ";
                cin >> exit_confirm;

                if (exit_confirm == 'Y' || exit_confirm == 'y') {
                    re_run = 1;
                    rejump = 1;
                    system("CLS");
                    break;
                }
                    
                else if (exit_confirm == 'N' ||exit_confirm == 'n') {
                    re_run = 0;
                    system("CLS");
                    break;
                }

                cout << "Error! Exting . . .";
                re_run = 0;
                Sleep(2000);
                system("CLS");
                break;

            case 2:
                system("CLS");
                // INPUT USER INFORMATION
                display_removestudent();
                Sleep(1000);
                
                cout << "\n";
                cout << "Enter student's name: ";
                cin.clear();
                cin.ignore();
                getline(cin, name);

                check_func = studentData->removeStudent(name);

                while (load < 3) {
                    cout << "\n.";
                    Sleep(500);
                    load++;
                }
                // INFORM
                if (check_func == 0) {
                    cout << "\nStudent information is not exist!";
                    Sleep(1000);
                }
                
                else {
                    cout << "\nStudent remove successfully!";
                    Sleep(1000);
                }

                cout << "\n\nDo you want to run again? (Y/N): ";
                cin >> exit_confirm;

                if (exit_confirm == 'Y' ||exit_confirm == 'y') {
                    re_run = 1;
                    rejump = 2;
                    system("CLS");
                    break;
                }
                    
                else if (exit_confirm == 'N' || exit_confirm == 'n') {
                    re_run = 0;
                    system("CLS");
                    break;
                }

                cout << "Error! Exting . . .";
                re_run = 0;
                Sleep(2000);
                system("CLS");
                break;

            case 3:
                system("CLS");
                studentData->displayList();
                cout << "\n\n";
                system("pause"); // Press any key to exit . . .
                system("CLS");
                break;

            case 4:
                system("CLS");
                cout << "Initializing ten students to the list . . .";
                studentData->initialize_ten_students();
                while (load < 3) {
                    cout << "\n.";
                    Sleep(500);
                    load++;
                }
                cout << "\n";
                system("pause");
                system("CLS");
                break; 
        }

    } while (check_exit != 1);

    cout << "Exiting...";
    Sleep(2000);

    delete studentData;

    system("CLS");
    exit(0);
}