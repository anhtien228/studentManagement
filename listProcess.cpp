#include "listProcess.h"

// Initialize the new list of student
studentProcess::studentProcess() {
    studentList = nullptr;
}
// Deconstructor
studentProcess::~studentProcess() {
    delete studentList;
}

void studentProcess::insertStudent(string name, const int id){
    if (name.length() == 0) {
        cout << "User have not input the name!";
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
}

void studentProcess::displayList() {
    int index = 0;
    int tableWidth = 15;
    studentList->display(tableWidth);

    studentList->moveToStart();
    while (index != studentList->length()) {
        string nameDsp = studentList->getValue().name;
        int idDsp = studentList->getValue().id;

        cout << setw(tableWidth) << index + 1 << 
        setw(tableWidth) << nameDsp << setw(tableWidth) << idDsp << endl;
        
        index++;
        studentList->next();

    }
}