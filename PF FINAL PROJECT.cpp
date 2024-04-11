#include <iostream>
#include <cstdlib> // For system() function
using namespace std;

// Global arrays to store student data
string name[10], program[10];
int rollNo[10], class0[10], contactNo[10];
//string arr1[10], arr2[10], arr3[10], arr4[10], arr5[10];
int total = 0; // Total number of students

// Function to set console text color based on user choice
int color() {
    int x;

    cout << "\n\t1. Green" << endl;
    cout << "\t2. Blue" << endl;
    cout << "\t3. Red" << endl;
    cout << "\t4. White" << endl;
    cout << "\t5. Default" << endl;
    cout << "\n\tSELECT BACKGROUND COLOR OF YOUR CHOICE: ";
    cin >> x;
    cout<<"\n";
    
    switch (x) {
        case 1:
            system("color a0"); // Change text color to green
            break;
        case 2:
            system("color b0"); // Change text color to blue
            break;
        case 3:
            system("color c0"); // Change text color to red
            break;
        case 4:
            system("color f0"); // Change text color to white
            break;
        default:
            system("color 00"); // Reset text color to default
            break;
    }
    return 0;
}

// Function to enter student data
void enterStudentData() {
    int choice;
    cout << "\n\tHow many students' data do you want to enter? ";
    cin >> choice;
    cout<<"\n";

    // If there are no existing students, directly input data
    if (total == 0) {
        total += choice;
        for (int i = 0; i < total; i++) {
            cout << "\tStudent number " << (i + 1) << ":" << endl;
            cout << "\tEnter the name of student: ";
            cin >> name[i];
            cout << "\tEnter the roll number of student: ";
            cin >> rollNo[i];
            
            cout << "\tEnter the class of student: ";
            cin >> class0[i];
            cout << "\tEnter the program of student: ";
            cin >> program[i];
            cout << "\tEnter the contact number of student: ";
            cin >> contactNo[i];
            cout<<"\n";
        }
    } else { // If there are existing students, append new data
        for (int i = total; i < total + choice; i++) {
            cout << "\tStudent number " << (i + 1) << ":" << endl;
            cout << "\tEnter the name of student: ";
            cin >> name[i];
            cout << "\tEnter the roll number of student: ";
            cin >> rollNo[i];
            
            cout << "\tEnter the class of student: ";
            cin >> class0[i];
            cout << "\tEnter the program of student: ";
            cin >> program[i];
            cout << "\tEnter the contact number of student: ";
            cin >> contactNo[i];
        }
        total += choice;
    }
}

// Function to display student data
void showStudentData() {
    if (total == 0) { // Check if there are any students
        cout << "\tNo student data available." << endl;
        return;
    }
    // Iterate through the stored data and display it
    for (int i = 0; i < total; i++) {
        cout << "\n\tSHOWING DATA OF STUDENT NO. " << (i + 1) << ":\n" << endl;
        cout << "\n\t****************\n";
        cout << "\tName: " << name[i] << endl;
        cout << "\tRoll number: " << rollNo[i] << endl;
        cout << "\tClass: " << class0[i] << endl;
        cout << "\tProgram: " << program[i] << endl;
        cout << "\tContact number: " << contactNo[i] << endl;
        cout << "\t****************\n\n";
    }
}

// Function to delete all student data
void deleteStudentData() {
    char confirm;
    cout << "\n\tAre you sure you want to delete all data? (Y/N): ";
    cin >> confirm;
    if (confirm == 'Y' || confirm == 'y') {
        total = 0;
        cout << "\n\tAll data deleted successfully.\n\n";
    }
}

// Function to update student data
void updateStudentData() {
    int roll;
    cout << "\n\tEnter the roll number of the student whose data you want to update: ";
    cin >> roll;
    cout<<"\n";
    // Search for the student with the specified roll number
    for (int i = 0; i < total; i++) {
        if (roll == rollNo[i]) {
            // Display previous data and input new data
            cout << "\tPREVIOUS DATA:\n\n";
            cout << "\tName: " << name[i] << endl;
            cout << "\tRoll number: " << rollNo[i] << endl;
            cout << "\tClass: " << class0[i] << endl;
            cout << "\tProgram: " << program[i] << endl;
            cout << "\tContact number: " << contactNo[i] << endl;

            cout << "\n\tENTER NEW DATA:\n\n";
            cout << "\tEnter the name of student: ";
            cin >> name[i];
            cout << "\tEnter the roll number of student: ";
            cin >> rollNo[i];
            cout << "\tEnter the class of student: ";
            cin >> class0[i];
            cout << "\tEnter the program of student: ";
            cin >> program[i];
            cout << "\tEnter the contact number of student: ";
            cin >> contactNo[i];
            cout << "\tData updated successfully.\n\n";
            return;
        }
    }
    cout << "\tStudent with roll number " << roll << " not found.\n\n";
}

// Function to search for student data by roll number
void searchStudentData() {
    int roll;
    cout << "\n\tEnter the roll number you want to search for: ";
    cin >> roll;
    cout<<"\n";
    // Search for the student with the specified roll number
    for (int i = 0; i < total; i++) {
        if (roll == rollNo[i]) {
            // Display the data of the found student
            cout << "\tDATA OF STUDENT NO. " << roll << ":\n";
            cout << "\tName: " << name[i] << endl;
            cout << "\tRoll number: " << rollNo[i] << endl;
            cout << "\tClass: " << class0[i] << endl;
            cout << "\tProgram: " << program[i] << endl;
            cout << "\tContact number: " << contactNo[i] << endl;
            return;
        }
    }
    cout << "\tStudent with roll number " << roll << " not found.\n\n";
}

int main() {
    color(); // color function call for implementing colors
    int choice;
    do {
        // Display menu options
        cout << "\t------------------------\n\n";
        cout << "\t1. Enter student's data\n";
        cout << "\t2. Show student's data\n";
        cout << "\t3. Delete student's data\n";
        cout << "\t4. Update student's data\n";
        cout << "\t5. Search for student's data\n";
        cout << "\t0. Exit\n";
        cout << "\t------------------------\n\n";
        cout << "\tEnter your choice: ";
        cin >> choice;

        // following functions will get called based on user choice
        switch (choice) {
            case 1:
                enterStudentData();
                break;
            case 2:
                showStudentData();
                break;
            case 3:
                deleteStudentData();
                break;
            case 4:
                updateStudentData();
                break;
            case 5:
                searchStudentData();
                break;
            case 0:
                cout << "\tExiting program...\n";
                break;
            default:
                cout << "\tInvalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0); // Continue loop until user chooses to exit

    return 0;
}