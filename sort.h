/**
 * @file sort.h
 * @author Chris Soto   
 * @brief Header File for struct and function protos
 * @version 0.1
 * @date 2023-09-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Student
{
    int id;
    string lastName;
    string firstName;
    string ssn;
    float test[4];
    float final;
    string letterGrade;
};
//function protos 
void openInputFile(ifstream &File, string name);
void readFileToVector(ifstream &File, vector<Student> &v);
void displayVector(vector<Student*> &v);
void displayMenu();
void pointToVector(vector<Student> &v,vector<Student *> &index);
void sortLast(vector<Student*> &p);
void swap(Student* &a, Student* &b);
void sortSsn(vector<Student*> &p);
void sortFirst(vector<Student*> &p);
void menuChoice(int input, vector<Student*> &p);
bool isFound(vector<Student*> &p, string data,int input);
int binarySearch(vector<Student*> &p, string data, int input);
void selectedBy(vector<Student*> &p, int input);
bool isGreater(string s1, string s2);
#endif