#include <iostream>
#include <fstream>
#include<string>

using namespace std;

const int skip = 90000;

void mainMenu();

class Student
{
    string name, roll_num, age, contact, course, attendance, marks;
    int option;

public:
    void studentEnrolMenu();
    //void attendanceMenu();
    //void marksMenu();
    void Enrol();
    void Remove();
    void Edit();
    void display();
};

class Course
{
    int option;

public:
    void courseRegMenu();
    //void courseWithdrawMenu();
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
        //st.attendanceMenu();
        break;
    case 4:
        //st.marksMenu();
        break;
    case 5:
        //cr.courseWithdrawMenu();
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
    ofstream writeStudent("students.txt", ios::app); //opening file in append mode

    if (!writeStudent.is_open()) //checking if the file is successfully opened or not
        cout << "Error opening the file for writing!" << endl;

    cout << "Enter name, roll number, age, contact, course, attendance and marks (with spaces)\n";
    getline(cin, name, ' ');
    getline(cin, roll_num, ' ');
    getline(cin, age, ' ');
    getline(cin, contact, ' ');
    getline(cin, course, ' ');
    getline(cin, attendance, ' ');
    getline(cin, marks);

    writeStudent << name << " " << roll_num << " " << age << " " << contact << " " << course << " " << attendance << " " << marks;
    writeStudent.close();

    cout << "Student information added to the file successfully!" << endl;

    display();
}

void Student::Remove()
{
    int index;
    ifstream readStudent("students.txt");

    if (!readStudent.is_open()) //checking if the file is successfully opened or not
        cout << "Error while opening the file for writing!" << endl;

    else
    {
        display();

        cout << "\nEnter the index (starting from zero index) of the student you want to remove: ";
        cin >> index;

        for (int i = 0; i < index; ++i)
            readStudent.ignore(skip, '\n');

        getline(readStudent, name, ' ');
        getline(readStudent, roll_num, ' ');
        getline(readStudent, age, ' ');
        getline(readStudent, contact, ' ');
        getline(readStudent, course, ' ');
        getline(readStudent, attendance, ' ');
        getline(readStudent, marks);
        readStudent.close();

        cout << "Student to be removed:\nName: " << name << " Roll Number: " << roll_num << " Age: " << age << " Contact: " << contact << " Course: " << course << " Attendance: " << attendance << " Marks: " << marks << endl;

        ofstream writeStudentTemp("newfile.txt");
        if (writeStudentTemp.is_open())
        {
            ifstream readStudentTemp("students.txt");
            if (readStudentTemp.is_open())
            {
                string line;
                while (getline(readStudentTemp, line))
                    if (line != (name + ' ' + roll_num + ' ' + age + ' ' + contact + ' ' + course + ' ' + attendance + ' ' + marks))
                        writeStudentTemp << line << '\n';
                readStudentTemp.close();
            }
            writeStudentTemp.close();
        }

        if (remove("students.txt") == 0 && rename("newfile.txt", "students.txt") == 0)
            cout << "Student you selected has been successfully removed\n";
        else
            cout << "There is an Error while removing the student!\n";
    }
}

void Student::Edit()
{
    int index;
    ifstream readStudent("students.txt");
    string tempName, tempRoll_num, tempAge, tempContact, tempCourse, tempAttendance, tempMarks;
    if (!readStudent.is_open()) //checking if the file is successfully opened or not
        cout << "Error while opening the file for writing!" << endl;

    else
    {
        display();

        cout << "\nEnter the index (starting from zero index) of the student you want to Edit: ";
        cin >> index;

        for (int i = 0; i < index; ++i)
            readStudent.ignore(skip, '\n');

        getline(readStudent, name, ' ');
        getline(readStudent, roll_num, ' ');
        getline(readStudent, age, ' ');
        getline(readStudent, contact, ' ');
        getline(readStudent, course, ' ');
        getline(readStudent, attendance, ' ');
        getline(readStudent, marks);
        readStudent.close();

        cout << "Student to be Edited:\nName: " << name << " Roll Number: " << roll_num << " Age: " << age << " Contact: " << contact << " Course: " << course << " Attendance: " << attendance << " Marks: " << marks << endl;

        ofstream writeStudentTemp("newfile.txt");
        if (writeStudentTemp.is_open())
        {
            ifstream readStudentTemp("students.txt");
            if (readStudentTemp.is_open())
            {
                string line;
                while (getline(readStudentTemp, line))
                {
                    if (line != (name + ' ' + roll_num + ' ' + age + ' ' + contact + ' ' + course + ' ' + attendance + ' ' + marks))
                        writeStudentTemp << line << '\n';
                    else
                    {
                        cout << "Edit name, roll number, age, contact, course, attendance and marks (with spaces):\n";
                        getline(cin, tempName, ' ');
                        getline(cin, tempRoll_num, ' ');
                        getline(cin, tempAge, ' ');
                        getline(cin, tempContact, ' ');
                        getline(cin, tempCourse, ' ');
                        getline(cin, tempAttendance, ' ');
                        getline(cin, tempMarks);

                        line = tempName + ' ' + tempRoll_num + ' ' + tempAge + ' ' + tempContact + ' ' + tempCourse + ' ' + tempAttendance + ' ' + tempMarks;
                        writeStudentTemp << line << '\n';
                    }
                }
                readStudentTemp.close();
            }
            writeStudentTemp.close();
        }

        if (remove("students.txt") == 0 && rename("newfile.txt", "students.txt") == 0)
            cout << "Student information Edited successfully!" << endl;

        else
            cout << "There is an Error while removing the student!\n";
    }
}

void Course::courseRegMenu()
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