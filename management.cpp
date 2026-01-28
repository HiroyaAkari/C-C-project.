#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int Max_student = 100;

struct Student {

    int id;
    string name;
    string classname;
    int grade;
};

Student schooldatabase[Max_student];
int currentcount = 0;


void addStudent();
void displayAllStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main(){
    int choice;

    cout << "=====================================" << endl;
    cout << " Welcome to LY MINH's School System " << endl;
    cout << "=====================================" << endl;

    while(true){
        cout << "\n--- Main Menu ---\n" << endl;
        cout << "1. View All Students" << endl;
        cout << "2. Search Student by ID" << endl;
        cout << "3. Update Student List" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Add New Student" << endl; 
        cout << "6. Exit " << endl;
        cout << "Please enter your choice: ";

        cin >> choice;
        
        switch(choice){
            case 1: displayAllStudents(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: addStudent(); break;
            case 6: 
                cout << "\nThank you for using the School System. Goodbye!" << endl;
                return 0;
            default: 
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }
    return 0;
}

// --- FUNCTION DEFINITIONS ---

void addStudent(){
    if (currentcount >= Max_student){
        cout << "\nThe school is full. Please enroll next time." << endl;
        return;
    }
    cout << "\n--- Add New Student ---" << endl;


    cout << "Enter Student ID: ";
    cin >> schooldatabase[currentcount].id;

    cin.ignore(); 

    cout << "Enter Student Name: ";
    getline(cin, schooldatabase[currentcount].name);

    cout << "Enter Class (e.g., 10-A): ";
    getline(cin, schooldatabase[currentcount].classname);

    cout << "Enter Grade (0-100): ";
    cin >> schooldatabase[currentcount].grade;

    currentcount++;
    cout << "Student added successfully!" << endl;
}

void displayAllStudents(){
    if (currentcount == 0){
        cout << "\nNo students found." << endl;
        return;
    }
     cout << "\n--- Student List (" << currentcount << "/" << Max_student << ") ---" << endl;


     cout << left << setw(8) << "ID" 
         << setw(25) << "Name" 
         << setw(12) << "Class" 
         << "Grade" << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < currentcount; i++) {
        cout << left << setw(8) << schooldatabase[i].id 
             << setw(25) << schooldatabase[i].name 
             << setw(12) << schooldatabase[i].classname 
             << schooldatabase[i].grade << endl;
    }
}

void searchStudent() {
    int searchId;
    bool found = false;

    if (currentcount == 0) {
        cout << "\nNo students to search." << endl;
        return;
    }

    cout << "\n--- Search Student ---" << endl;
    cout << "Enter Student ID: ";
    cin >> searchId;

    for (int i = 0; i < currentcount; i++) {
        if (schooldatabase[i].id == searchId) {
            cout << "\nStudent Found:" << endl;
            cout << "ID: " << schooldatabase[i].id << endl;
            cout << "Name: " << schooldatabase[i].name << endl;
            cout << "Class: " << schooldatabase[i].classname << endl;
            cout << "Grade: " << schooldatabase[i].grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found." << endl;
    }
}

void updateStudent() {
    int updateId;
    bool found = false;

    if (currentcount == 0) return;

    cout << "\n--- Update Student ---" << endl;
    cout << "Enter Student ID to update: ";
    cin >> updateId;

    for (int i = 0; i < currentcount; i++) {
        if (schooldatabase[i].id == updateId) {
            found = true;
            cin.ignore(); 

            cout << "Enter new Name: ";
            getline(cin, schooldatabase[i].name);

            cout << "Enter new Class: ";
            getline(cin, schooldatabase[i].classname);

            cout << "Enter new Grade: ";
            cin >> schooldatabase[i].grade;

            cout << "Student updated successfully!" << endl;
            break;
        }
    }

    if (!found) cout << "Student ID " << updateId << " not found." << endl;
}

void deleteStudent() {
    int deleteId;
    bool found = false;

    if (currentcount == 0) return;

    cout << "\n--- Delete Student ---" << endl;
    cout << "Enter Student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < currentcount; i++) {
        if (schooldatabase[i].id == deleteId) {
            found = true;

            for (int j = i; j < currentcount - 1; j++) {
                schooldatabase[j] = schooldatabase[j + 1];
            }
            currentcount--; 
            cout << "Student deleted successfully!" << endl;
            break;
        }
    }
    if (!found) cout << "Student ID " << deleteId << " not found." << endl;
}