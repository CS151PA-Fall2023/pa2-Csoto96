/**
 * @file main.cpp
 * @author Chris Soto  
 * @brief Main file that runs program that reads file and sorts data in a interactive menu
 * @version 0.1
 * @date 2023-09-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <fstream>
#include "sort.h"
using namespace std;

int main()
{
    ifstream studentFile;
    vector<Student> studentData;
    vector<Student *>indexByLastName;
    vector<Student *>indexBySsn;
    vector<Student *>indexByFirstName;
    openInputFile(studentFile,"grades.csv");
    readFileToVector(studentFile,studentData);
    studentFile.close();
    pointToVector(studentData,indexByLastName);
    pointToVector(studentData,indexBySsn);
    pointToVector(studentData,indexByFirstName);
    sortLast(indexByLastName);
    sortSsn(indexBySsn);
    sortFirst(indexByFirstName);
    int input;
    while(1)
    {
        displayMenu();
        cout << "Select a Menu: ";
        do
        {
            cin >> input; 
            if(input > 7 || input < 1)
            {
                cout << "invalid input, please enter 1-7" << endl;
            }
        } while (input > 7 || input < 1);
        if(input == 7)
        {
            break;
        }
        if(input == 1 || input == 3)
        {
            menuChoice(input, indexByLastName);
        }
        if(input == 2 || input == 4)
        {
            menuChoice(input, indexBySsn);
        }
        if(input == 5 || input == 6)
        {
            menuChoice(input, indexByFirstName);
        }
    }
    return 0;
}