#include <iostream>
#include <fstream>
#include<string>
using namespace std;
void mainMenu();
class Student
{
    int option;
    string name, roll_num, age, contact, course, attendance, marks;

public:
    void studentEnrolMenu();
    void Enrol();
    void Remove();
    void Edit();
    void display();
};

class Course
{
public:
    void courseRegMenu();
};

class Attendance
{
public:
    void attendanceMenu();
};

class Marks
{
public:
    void marksMenu();
};

class Withdraw
{
public:
    void courseWithdrawMenu();
};

class System
{};

class FileHandler
{};

class Validator
{};

void mainMenu()
{
    int option;
    Student st;
    Course cr;
    Attendance at;
    Marks mk;
    Withdraw wd;

    cout << "Choose an option from the menu\n";
    cout << "1- Enroll a student\n2- Course Registration\n3- Attendance\n4- Marks\n5- Course Withdraw\n6- Exit\n";
    cout << "Option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        st.studentEnrolMenu();
        break;
    case 2:
        cr.courseRegMenu();
        break;
    case 3:
        at.attendanceMenu();
        break;
    case 4:
        mk.marksMenu();
        break;
    case 5:
        wd.courseWithdrawMenu();
        break;
    case 6:
        cout << "Program Terminated";
        return;
    default:
        cout << "\nInvalid option";
    }
}

void Student::studentEnrolMenu()
{
    cout << "1- Add a student\n2- Remove a student\n3- Edit student\n4- back";
    cout << "\nOption: ";
    cin >> option;

    if (option == 1)
        Enrol();

    else if (option == 2)
        Remove();

    else if (option == 3)
        Edit();

    else if (option == 4)
        mainMenu();
    else
        cout << "\nInvalid option";
}

void Student::Enrol()
{
    ofstream writeStudent("students.txt", ios::app); //open file in append mode

    if (!writeStudent.is_open())
        cout << "Error opening the file for writing!" << endl;

    cout << "Enter name, roll number, age, contact, course, attendance and marks (comma-separated)\n";
    getline(cin, name, ',');
    getline(cin, roll_num, ',');
    getline(cin, age, ',');
    getline(cin, contact, ',');
    getline(cin, course, ',');
    getline(cin, attendance, ',');
    getline(cin, marks);

    writeStudent << name << "," << roll_num << "," << age << "," << contact << "," << course << "," << attendance << "," << marks << "\n";
    writeStudent.close();

    cout << "Student information added to the file successfully!" << endl;

    display();
}

void Student::Remove()
{
    cout << "a";
}

void Student::Edit()
{
    cout << "a";
}

void Course::courseRegMenu()
{
    cout << "a";
}

void Attendance::attendanceMenu()
{
    cout << "a";
}

void Marks::marksMenu()
{
    cout << "a";
}

void Withdraw::courseWithdrawMenu()
{
    cout << "a";
}

// Function to display enrolled students
void Student::display()
{
    // Read and print the contents of the file
    ifstream readStudent("students.txt");
    if (readStudent.is_open())
    {
        cout << "\nContents of the file:\n";
        char ch;

        while (readStudent.get(ch))
            cout << ch;
        readStudent.close();
    }
    else
        cout << "Error opening the file for reading!" << endl;
}

int main()
{
    mainMenu();

    return 0;
}