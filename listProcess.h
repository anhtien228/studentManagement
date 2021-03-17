#include "main.h"

template <typename S>
class Link {
    // Link's data
    public:
    S data;
    Link * next;

    // Create a new cell contain new data
    Link(const S& data_val, Link* nextdata = NULL) {
        data = data_val;
        next = nextdata;
    }
     // Create a new empty cell only
    Link(Link* nextdata = NULL) {
        next = nextdata;
    }
};
template <typename S>
class List {
public:	// Return: The number of elements in the list.
	List() {};
	virtual ~List() {};
	virtual int length() const = 0;
	virtual void insert(const S& data) = 0;
	virtual void append(const S& data) = 0;
	virtual void moveToStart() = 0;
	virtual void moveToEnd() = 0;
	virtual int currentPos() const = 0;
	virtual S& getValue() const = 0;
	virtual void remove() = 0;
    virtual void next() = 0;
	virtual void moveToPos(int pos) = 0;
    virtual void display(int colWidth) = 0;
};

template <typename S>
class LList : public List<S> {

    private:
    Link<S> * head;
    Link<S> * tail;
    Link<S> * curr;
    int count;

    public:
    // Constructor of new list
    LList() {
        curr = head = tail = new Link<S>();
        count = 0;
    }
    // Put current cursor link to this new cell (with new data)
    // IF THE CURSOR IS THE TAIL, let the pointer of the tail cell become the tail
    int length() const {
        return count;
    }
    
    void insert(const S& data) {
        curr->next = new Link<S>(data, curr->next);
        if (tail == curr) tail = curr->next;
        count++;
    }
    
    void append(const S& data) {
        tail = tail->next = new Link<S>(data, NULL);
        // It means the previous last cell will point to the new cell
        // that we just have inserted, and that new cell will become
        // the last cell, with its pointer point to NULL
        count++;
    }

    void moveToStart() { curr = head; }
    void moveToEnd() { curr = tail; }
    
    // Get the current pointer
    int currentPos() const {
        // Initialize the temperatore pointer at the head
        Link<S>* temp = head;
        //Traverse
        int i;
        for (i = 0; curr != temp; i++) {
            temp = temp->next;
            // Current cursor = next cell's cursor
        }
        return i;
    }
    // Get the data
    S& getValue() const {
        return curr->next->data;
    }

    void remove() {
        Link<S>* temp = curr->next; // Memorize the pointer

        if (tail == curr->next) tail == curr; // if we remove the tail, reset the tail position
        curr->next = curr->next->next; 
        delete temp;
        count--;
    }

    void next() { if (curr != tail) curr = curr->next; }

    void moveToPos(int pos) {
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
    }
    void display(int colWidth) {
        cout << setfill('_') << setw(3*colWidth) << "_" << endl;
        cout << setfill(' ') << fixed;
        cout << setw(colWidth) << "No." << setw(colWidth) << "Student" << setw(colWidth) << 
        "ID" << endl; 
        cout << setfill('_') << setw(3*colWidth) << "_" << endl; 
        cout << setfill(' ') << fixed;
    }
    

};

class Student {
    public:
    int id;
    string name;
    Student(){}
    Student(string name, int id) {
        this->name = name;
        this->id = id;
    }
    ~Student(){}
};

class studentProcess {
    private:
    LList<Student> * studentList;

    public:
    studentProcess();
    ~studentProcess();
    
    void insertStudent(string name, const int id);
    void displayList();
};