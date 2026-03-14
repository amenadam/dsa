#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 10;
int std_count = 0;
class studentType
{
private:
    char std_name[50];
    int std_age;
    char std_id[10];
    char std_department[50];
    double std_gpa;

public:
    void setData(studentType &);
    void printData(studentType std[]);
    void sortStudentByName(studentType std[]);
    void sortStudentById(studentType std[]);
    int searchStudentById(studentType std[], char[]);
    void deleteStudentById(studentType std[], char[]);

    void setName(char[]);
    void setAge(int);
    void setId(char[]);
    void setDepartment(char[]);
    void setGpa(double);

    bool isValidGpa(double);

    char *getName();
    int getAge();
    char *getId();
    char *getDepartment();
    double getGpa();

    studentType();
    studentType(char[], int, char[], char[], double);
    ~studentType();
};

studentType::studentType()
{
    std_name[0] = '\0';
    std_age = 0;
    std_id[0] = '\0';
    std_department[0] = '\0';
    std_gpa = 0.0;
}

studentType::studentType(char name[], int age, char id[], char department[], double gpa)
{
    strcpy(std_name, name);
    std_age = age;
    strcpy(std_id, id);
    strcpy(std_department, department);
    std_gpa = gpa;
}

studentType::~studentType() {}

void studentType::setName(char newName[])
{
    strcpy(std_name, newName);
}

void studentType::setAge(int newAge)
{
    std_age = newAge;
}

void studentType::setId(char newId[])
{
    strcpy(std_id, newId);
}

void studentType::setDepartment(char newDepartment[])
{
    strcpy(std_department, newDepartment);
}

void studentType::setGpa(double newGpa)
{
    std_gpa = newGpa;
}

char *studentType::getName()
{
    return std_name;
}

int studentType::getAge()
{
    return std_age;
}

char *studentType::getId()
{
    return std_id;
}

char *studentType::getDepartment()
{
    return std_department;
}

double studentType::getGpa()
{
    return std_gpa;
}

bool studentType::isValidGpa(double gpa)
{
    if (gpa <= 4.00 && gpa >= 0.00)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void studentType::setData(studentType &student)
{
    cin.ignore();
NAME:
    cout << "\nEnter student's name: ";
    cin.getline(student.std_name, 50);
    for (int i = 0; i < strlen(student.std_name); i++)
    {
        if (!isalpha(student.std_name[i]))
        {
            cout << "\nPlease enter valid name:";
            goto NAME;
        }
    }

    cout << "\nEnter student's age: ";
    cin >> student.std_age;
    cin.ignore();
    cout << "\nEnter student's Id: ";
    cin.getline(student.std_id, 10);
    cout << "\nEnter student's department: ";
    cin.getline(student.std_department, 50);
GPA:
    cout << "\nEnter student's gpa: ";
    cin >> student.std_gpa;
    cin.ignore();
    if (!isValidGpa(student.std_gpa))
    {
        cout << "Please enter valid gpa (0.00 - 4.00)";
        goto GPA;
    }
    std_count++;

    cout << "\n Student successfully registered!";
}

void studentType::printData(studentType std[])
{
    if (std_count == 0)
    {
        cout << "\n No student registered yet! \n";
    }
    else
    {
        cout << "\n R.NO \t Name \t ID \t Age \t Department \t Gpa";

        for (int i = 0; i < std_count; i++)
        {
            cout << "\n " << i + 1 << "\t " << std[i].getName() << "\t " << std[i].getId() << "\t " << std[i].getAge() << "\t " << std[i].getDepartment() << "\t " << std[i].getGpa();
        }
        cout << "\n Students information printed successfully!\n";
    }
}

void studentType::sortStudentByName(studentType std[])
{
    studentType temp;
    bool flag = false;

    for (int i = 0; i < std_count; i++)
    {
        flag = false;
        for (int j = 0; j < std_count - i - 1; j++)
        {
            if (strcmp(std[j].std_name, std[j + 1].std_name) > 0)
            {
                temp = std[j];
                std[j] = std[j + 1];
                std[j + 1] = temp;
                flag = true;
            }
        }
    }
}

void studentType::sortStudentById(studentType std[])
{
    studentType temp;
    bool flag = false;

    for (int i = 0; i < std_count; i++)
    {
        flag = false;
        for (int j = 0; j < std_count - i - 1; j++)
        {
            if (strcmp(std[j].std_id, std[j + 1].std_id) > 0)
            {
                temp = std[j];
                std[j] = std[j + 1];
                std[j + 1] = temp;
                flag = true;
            }
        }
    }
}

int studentType::searchStudentById(studentType std[], char key[])
{
    int loc = -1;
    int i = 0;

    do
    {
        if (strcmp(key, std[i].std_id) == 0)
        {
            loc = i;
        }
        else
        {
            i++;
        }
    } while (loc == -1 && i < std_count);

    return loc;
}

void studentType::deleteStudentById(studentType std[], char key[])
{
    int loc = -1;
    for (int i = 0; i < std_count; i++)
    {
        if (strcmp(key, std[i].std_id) == 0)
        {
            loc = i;
        }
    }

    if (loc == -1)
    {
        cout << "\n Student not found!\n";
    }
    else
    {
        for (int i = loc; i < std_count; i++)
        {
            std[i] = std[i + 1];
        }
        std_count--;
        cout << "\nStudent information deleted successfully\n";
    }
}
void getDeveloperInformation()
{
    cout << "\n Developer Information ";
    cout << "\n\t Full Name: Amenadam Solomon ";
    cout << "\n\t ID: RU0238/17 ";
    cout << "\n\t Department: Software Engineering ";
    cout << "\n\t Year: 2 ";
    cout << "\n\t Section: 1 \n";
    cout << "\n Other Information ";
    cout << "\n\t Github:  http://github.com/amenadam/";
}

int main()
{
    studentType obj, student[SIZE];
    char search_key[50];
    char delete_key[10];
    char option;
    int location;

MENU:

    cout << "\n Main Menu:";
    cout << "\n 1. Enter Student Information";
    cout << "\n 2. Print Student Information";
    cout << "\n 3. Search Student By ID";
    cout << "\n 4. Sort Students By Name";
    cout << "\n 5. Sort Students By Id";
    cout << "\n 6. Delete Student";
    cout << "\n 7. Developer Information";
    cout << "\n 0. Exit";
    cout << "\n Enter the option: ";
    cin.ignore();
    cin >> option;
    switch (option)
    {
    case '1':
        obj.setData(student[std_count]);
        break;
    case '2':
        obj.printData(student);
        break;
    case '3':
        cout << "\n Enter student's id to search: ";
        cin.ignore();
        cin.getline(search_key, 10);
        location = obj.searchStudentById(student, search_key);
        if (location >= 0)
        {
            cout << "\n Name: " << student[location].getName();
            cout << "\n Id: " << student[location].getId();
            cout << "\n Age: " << student[location].getAge();
            cout << "\n Department: " << student[location].getDepartment();
            cout << "\n GPA: " << student[location].getGpa();
        }
        else
        {
            cout << "\n Student not found!\n";
        }
        break;
    case '4':
        obj.sortStudentByName(student);
        break;
    case '5':
        obj.sortStudentById(student);
        break;
    case '6':
        cout << "\n Enter student's id to delete: ";
        cin.ignore();
        cin.getline(delete_key, 10);
        obj.deleteStudentById(student, delete_key);
        break;
    case '7':
        getDeveloperInformation();
        break;
    case '0':
        return 0;
    default:
        cout << "\n Please select correct option\n";
        break;
    }
    goto MENU;
    return 0;
}