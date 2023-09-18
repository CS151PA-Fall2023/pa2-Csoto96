/**
 * @file sort.cpp
 * @author Chris Soto
 * @brief Functions file that holds all functions program executes from main.cpp
 * @version 0.1
 * @date 2023-09-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "sort.h"
/**
 * @brief Opens file and checks if any errors occur
 * 
 * @param File 
 * @param name 
 */
void openInputFile(ifstream &File, string name)
{
    File.open(name);
    //error block
    if(!File)
    {
        cout << "Error opening file!" << endl;
        exit(1);
    }
}
/**
 * @brief Reads input file and stores it in a vector of student structures
 * 
 * @param File 
 * @param v 
 */
void readFileToVector(ifstream &File, vector<Student> &v)
{
    string skip;
    char delim = ',';
    getline(File, skip);
    while(File.peek()!= EOF)
    {
            Student newStudent;
            File>>newStudent.id;
            getline(File,skip,delim);
            getline(File,newStudent.lastName,delim);    
            getline(File,newStudent.firstName,delim);
            getline(File,newStudent.ssn,delim);
            for(int i = 0; i < 4;i++)
            {
                File>>newStudent.test[i];
                getline(File,skip,delim);
            }
            File>>newStudent.final;
            getline(File,skip,delim);
            File>>newStudent.letterGrade;
            File.get();         
            v.push_back(newStudent);    
        
    }
}
/**
 * @brief displays specified pointer vector from main
 * 
 * @param v 
 */
void displayVector(vector<Student*> &v)
 {
    for(int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i]->id << " " << v[i]->lastName << " " << v[i]->firstName << " " << v[i]->ssn << " "
        << v[i]->test[0] << " " << v[i]->test[1] << " " << v[i]->test[2] << " " << v[i]->test[3] << " "
        << v[i]->final << " " << v[i]->letterGrade << endl;
    }
    cin.ignore();
    cout << "Press enter to continue...";
    cin.get();
 }
/**
 * @brief displays menu to user
 * 
 */
 void displayMenu()
 {
    cout << "1. Print data in ascending order by last name" << endl;
    cout << "2. Print data in ascending order by SSN" << endl;
    cout << "3. Search by last name" << endl;
    cout << "4. Search by SSN" << endl;
    cout << "5. Print data in ascending order by first name" << endl;
    cout << "6. Search by first name" << endl;
    cout << "7. Exit" << endl;
 }
/**
 * @brief points individual pointers in vector to the original vector of students
 * 
 * @param v 
 * @param index 
 */
 void pointToVector(vector<Student> &v,vector<Student *> &index)
 {
    for(int i = 0; i < (int)v.size(); i++)
    {
        Student* p1 = &v[i];
        index.push_back(p1);
    }
 }
/**
 * @brief takes user input and chooses appropriate action from menu
 * 
 * @param input 
 * @param p 
 */
 void menuChoice(int input, vector<Student*> &p)
 {
    switch(input)
    {
        case 1: displayVector(p);
                break;
        case 2: displayVector(p);
                 break;
        case 3: selectedBy(p,input);
                 break;
        case 4: selectedBy(p,input);
                 break;
        case 5: displayVector(p);
                 break;
        case 6: selectedBy(p,input);
                 break;
        default: cout << "menu choice is invalid" << endl;
    }
 }
/**
 * @brief sorts the vector of pointers by last name
 * 
 * @param p 
 */
 void sortLast(vector<Student*> &p)
 {
    int size = p.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
                if(isGreater(p[i]->lastName , p[i + 1]->lastName))
                swap(p[i], p[i + 1]);
            
       }
    }
 }
/**
 * @brief swaps elements from sorting algorithm
 * 
 * @param a 
 * @param b 
 */
 void swap(Student* &a, Student* &b)
 {
   Student* temp;
   temp = a;
    a = b;
    b = temp;
 }
/**
 * @brief sorts pointer vector by SSN
 * 
 * @param p 
 */
 void sortSsn(vector<Student*> &p)
 {
    int size = p.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (p[i]->ssn > p[i + 1]->ssn)
             swap(p[i], p[i + 1]);
       }
    }
 }
/**
 * @brief sorts pointer vector by First name
 * 
 * @param p 
 */
 void sortFirst(vector<Student*> &p)
 {
    int size = p.size()-1;
    for (int maxElement = size; maxElement > 0; maxElement--)
    {
       for (int i = 0; i < maxElement; i++)
       {
          if (isGreater(p[i]->firstName , p[i + 1]->firstName))
             swap(p[i], p[i + 1]);
       }
    }
 }
/**
 * @brief searches by user input by either last or first name or ssn then displays info to user
 * 
 * @param p 
 * @param input 
 */
void selectedBy(vector<Student*> &p, int input)
 {
    string search;
    if(input == 3)
    {
        cout << "Enter Last Name: ";   
    }
    if(input == 4)
    {
        cout << "Enter SSN with dashes: ";     
    }
    if(input == 6)
    {
        cout << "Enter First Name: "; 
    }
    cin.ignore();
    do
    {
        getline(cin,search);
        if(!isFound(p,search,input))
        {
            cout << "Input not found, please enter again " << endl;
        }
    } while (!isFound(p,search,input));
    int choice = binarySearch(p,search,input);
    if(input == 3)
    {
       for(int i = choice; i < (int)p.size(); i++)
        {
            if(p[i]->lastName == search)
            {
                cout << p[i]->id << " " << p[i]->lastName << " " << p[i]->firstName << endl;
                cout << "------------------------------" << endl;
                cout << p[i]->ssn << " " << p[i]->test[0] << " " << p[i]->test[1] << " " <<
                        p[i]->test[2] << " " << p[i]->test[3] << " " << p[i]->final << " " <<
                        p[i]->letterGrade << endl;
            }
        }
    }
    if(input == 4)
    {
        for(int i = choice; i < (int)p.size(); i++)
        {
            if(p[i]->ssn == search)
            {
                cout << p[i]->id << " " << p[i]->lastName << " " << p[i]->firstName << endl;
                cout << "------------------------------" << endl;
                cout << p[i]->ssn << " " << p[i]->test[0] << " " << p[i]->test[1] << " " <<
                        p[i]->test[2] << " " << p[i]->test[3] << " " << p[i]->final << " " <<
                        p[i]->letterGrade << endl;
            }
        }
    }
    if(input == 6)
    {
        for(int i = choice; i < (int)p.size(); i++)
        {
            if(p[i]->firstName == search)
            {
                cout << p[i]->id << " " << p[i]->lastName << " " << p[i]->firstName << endl;
                cout << "------------------------------" << endl;
                cout << p[i]->ssn << " " << p[i]->test[0] << " " << p[i]->test[1] << " " <<
                        p[i]->test[2] << " " << p[i]->test[3] << " " << p[i]->final << " " <<
                        p[i]->letterGrade << endl;
            }
        }
    }
    cout << "Press enter to continue...";
    cin.get();
 }
/**
 * @brief uses binary search to look for info user provided
 * 
 * @param p 
 * @param data 
 * @param input 
 * @return int 
 */
 int binarySearch(vector<Student*> &p, string data, int input)
{
    int first = 0, // First array element
    last = p.size() - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag
    if(input == 3)
    {
    while (!found && first <= last)
        {   
            middle = (first + last) / 2; // Calculate midpoint
            if (p[middle]->lastName == data) // If value is found at mid
                {
                    found = true;
                    position = middle;
                }
        else if ((isGreater(p[middle]->lastName , data))) // If value is in lower half
            {
                last = middle - 1;
            }
        else
            {
                first = middle + 1; // If value is in upper half
            }
        }
    }
    if(input == 4)
    {
    while (!found && first <= last)
        {   
            middle = (first + last) / 2; // Calculate midpoint
            if (p[middle]->ssn == data) // If value is found at mid
                {
                    found = true;
                    position = middle;
                }
        else if (p[middle]->ssn > data) // If value is in lower half
            {
                last = middle - 1;
            }
        else
            {
                first = middle + 1; // If value is in upper half
            }
        }
    }
    if(input == 6)
    {
    while (!found && first <= last)
        {   
            middle = (first + last) / 2; // Calculate midpoint
            if (p[middle]->firstName == data) // If value is found at mid
                {
                    found = true;
                    position = middle;
                }
        else if ((isGreater(p[middle]->firstName , data))) // If value is in lower half
            {
                last = middle - 1;
            }
        else
            {
                first = middle + 1; // If value is in upper half
            }
        }
    }
    return position;
}
/**
 * @brief checks if what user enters exists in the vector
 * 
 * @param p 
 * @param data 
 * @param input 
 * @return true 
 * @return false 
 */
bool isFound(vector<Student*> &p, string data,int input)
{
    if(input == 1 || input == 3)
    {
        for(int i = 0; i < (int)p.size(); i++)
        {
            if(p[i]->lastName == data)
            {
                return true;
            }
        }
        return false;
    }
    if(input == 2 || input == 4)
    {
        for(int i = 0; i < (int)p.size(); i++)
        {
            if(p[i]->ssn == data)
            {
                return true;
            }
        }
        return false;
    }
    if(input == 5 || input == 6)
    {
        for(int i = 0; i < (int)p.size(); i++)
        {
            if(p[i]->firstName == data)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}
/**
 * @brief compares elements from 2 strings to see if they are equal or greater than.
 * 
 * @param s1 
 * @param s2 
 * @return true 
 * @return false 
 */
bool isGreater(string s1, string s2)
{
    if(toupper(s1[0]) == toupper(s2[0]))
    {
        if(toupper(s1[1]) == toupper(s2[1]))
        {
            if(toupper(s1[2]) == toupper(s2[2]))
            {
                if(toupper(s1[3]) == toupper(s2[3]))
                {
                    if(toupper(s1[4]) == toupper(s2[4]))
                    {
                        return true;
                    }
                    
                    if(toupper(s1[4]) > toupper(s2[4]))
                    {
                        return true;
                    }
                        
                }
                if(toupper(s1[3]) > toupper(s2[3]))
                    {
                        return true;
                    }
            
            }
            if(toupper(s1[2])>toupper(s2[2]))
                {
                    return true;
                }
        }
        if(toupper(s1[1])>toupper(s2[1]))
        {
            return true;
        } 
    }
    if(toupper(s1[0])>toupper(s2[0]))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}