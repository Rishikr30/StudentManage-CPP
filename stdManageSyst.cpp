#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    char name[50];
    int rollNumber;
    char course[50];
    float marks;

    void getStudent()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void displayStudent()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
    }
};

class StudentManageSystem
{
private:
    Student students[10];
    int studentNum;

public:
    StudentManageSystem()
    {
        studentNum = 0;
    }

    void addStudent()
    {
        if (studentNum < 10)
        {
            students[studentNum].getStudent();
            studentNum++;
            cout << "Student added successfully!" << endl;
        }
        else
        {
            cout << "Student database is full." << endl;
        }
    }

    void displayStudentsList()
    {
        if (studentNum == 0)
        {
            cout << "No students in the college." << endl;
            return;
        }
        cout << "\n---Students List---" << endl;
        for (int i = 0; i < studentNum; i++)
        {
            cout << "Student " << i + 1 << ":" << endl;
            students[i].displayStudent();
            cout << endl;
        }
    }

    void searchStudent()
    {
        int rollNumber;
        cout << "Enter roll number to search: ";
        cin >> rollNumber;

        for (int i = 0; i < studentNum; i++)
        {
            if (students[i].rollNumber == rollNumber)
            {
                cout << "Student found:" << endl;
                students[i].displayStudent();
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void updateStudent()
    {
        int rollNumber;
        cout << "Enter roll number to update: ";
        cin >> rollNumber;

        for (int i = 0; i < studentNum; i++)
        {
            if (students[i].rollNumber == rollNumber)
            {
                students[i].getStudent();
                cout << "Student updated successfully!" << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }

    void deleteStudent()
    {
        int rollNumber;
        cout << "Enter roll number to delete: ";
        cin >> rollNumber;

        for (int i = 0; i < studentNum; i++)
        {
            if (students[i].rollNumber == rollNumber)
            {
                for (int j = i; j < studentNum - 1; j++)
                {
                    students[j] = students[j + 1];
                }
                studentNum--;
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }

        cout << "Student not found." << endl;
    }
};

int main()
{
    StudentManageSystem sms;

    while (true)
    {
        cout << "\n---Student Management System---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sms.addStudent();
            break;
        case 2:
            sms.displayStudentsList();
            break;
        case 3:
            sms.searchStudent();
            break;
        case 4:
            sms.updateStudent();
            break;
        case 5:
            sms.deleteStudent();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice.Try again." << endl;
            break;
        }
    }

    return 0;
}