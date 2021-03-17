#include "main.h"
#include "listProcess.h"
#include "displayProcess.h"

using namespace std;

int main(int argc, char** argv) {

    studentProcess * studentData = new studentProcess();
	
    system("CLS");

    int check_exit = 0;

    do {
        string name;
        int id;
        int option;
        displaymenu_student();
        cin >> option;

        switch(option) {
            case 0:

                check_exit = 1;

            break;
            case 1:
                system("CLS");

                cout << "|      -> ADD STUDENT <-      |\n\n";
                Sleep(1000);
                cout << "Enter student's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student's ID: ";
                cin >> id;

                studentData->insertStudent(name, id);

                cout << "Student added successfully!";
                Sleep(2000);
                system("CLS");

                break;

            case 2:
                break;

            case 3:
                string exit;

                studentData->displayList();
                cout << "Press T to exit: ";
                cin.ignore();
                getline(cin, exit);

                if (exit == "T" || exit == "t") {
                    system("CLS");
                    continue;
                }
                break;

        }

    } while (check_exit != 1);

    cout << "Exiting...";
    Sleep(2000);
    exit(0);

    delete studentData;
}