#include "listProcess.h"

// Initialize the new list of student
studentProcess::studentProcess() {
    studentList = nullptr;
}
// Deconstructor
studentProcess::~studentProcess() {
    delete studentList;
}

// ------------ ADD STUDENT FUNCTION -------------- //
int studentProcess::insertStudent(string name, const int id){
    /*
    If there is no name inserted (which means false input), return error = 1 so the main
    program can check and print out the appropriate announcement
    */
   
    int error = 0;
    if (name.length() == 0 || to_string(id) == "") {
        cout << "User have not input the name!";
        error = 1;
    }
    else {
        // Create a cell contain student's information
        Student newStudent = Student(name, id);
        // If there is no student in the list, create new list
        if (studentList == nullptr) {
            studentList = new LList<Student>();
            studentList->append(newStudent);
        }
        else studentList->append(newStudent);
    }
    return error;
}

// ------------ REMOVE STUDENT FUNCTION -------------- //
int studentProcess::removeStudent(string name){
    /*
    If there is no name inserted (which means false input), return error = 1 so the main
    program can check and print out the appropriate announcement
    */
   
    int exist = 0;
    int index = 0;
    int verify = 0;

    if (name.length() == 0) {
        cout << "User have not input the name!";
        return exist;
    }

    if (studentList == nullptr) {
        return exist;
    }

    else {
        studentList->moveToStart(); // Move to the head for iterating the list again because the cursor always move to different
                                    // location, so if we do not move it to the start, it will mess up the later operations.
        while (index != studentList->length()) {
            string nameRm = studentList->getValue().name;
            // We convert all string name into lowercase for matching optimization
            if (lowerCase(nameRm) == lowerCase(name)) {
                studentList->remove();
                exist = 1;
                return exist;
            }

            index++;
            studentList->next();
        }
    }
    return exist;
}

// ------------ INITIALIZE STUDENT FUNCTION -------------- //
void studentProcess::initialize_ten_students() {
    string names[10] = {"Tyler Brooks", "Leonard Heptinstall", "Genevieve Love", "Eric Carroll", "Laurel Hayward", 
                        "Muriel Coleman", "Shirley Cannon", "Elmer Malone", "Madison Hunt", "Geogre Joyce"};
    int id[10] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int index = 0;

    // If there is no student in the list, create new list
    if (studentList == nullptr) {
        studentList = new LList<Student>();
        string firstUser = names[0];
        int firstID = id[0];
        Student newStudent = Student(firstUser, firstID);
        studentList->append(newStudent);

        while (index < 9) {

            string nameInit = names[index+1];
            int idInit = id[index+1];

            Student newStudent = Student(nameInit, idInit);
            studentList->append(newStudent);
            index++;
            studentList->next();
        }
    }
    else {
        while (index < 10) {

            string nameInit = names[index];
            int idInit = id[index];

            Student newStudent = Student(nameInit, idInit);
            studentList->append(newStudent);

            index++;
            studentList->next();
        }
    }

}

// ------------ DISPLAY STUDENT LIST FUNCTION -------------- // 
void studentProcess::displayList() {
    int index = 0;
    int tableWidth = 15;
    studentList->display(tableWidth);

    if (studentList == nullptr) {
        return;
    }
    else {
        studentList->moveToStart();
        while (index != studentList->length()) {
            string nameDsp = studentList->getValue().name;
            int idDsp = studentList->getValue().id;

            cout << setw(tableWidth) << index + 1 << 
            setw(2*tableWidth) << nameDsp << setw(tableWidth) << idDsp << endl;
            
            index++;
            studentList->next();
        }
    }
}

// ------------ LOWERCASE CONVERTER FUNCTION -------------- //
string studentProcess::lowerCase(string input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32; //convert to lowercase
        }
    }
    return input;
}
// ------------ UPPERCASE CONVERTER FUNCTION -------------- //
string studentProcess::upperCase(string input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 32; //convert to uppercase
        }
    }
    return input;
}