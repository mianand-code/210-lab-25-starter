// COMSC-210 | Lab 25 | Mira Anand
// Module 9, Lesson: std::list & std::set, Assignment: Data Structures Races
// IDE used: Visual Studio Code for Mac

// In this program, each of the 3 data structures will have its own separate function for each individual race task, for purposes of clarity
// To add new races, all you would need to do is create more functions for the race task you want to add and add more timing code blocks/output statements in main()

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

#include <algorithm> // to use std::vector member functions
#include <chrono> // to use time features
#include <fstream> // needed for file operations
#include <iostream>
#include <list> // to use std::list
#include <set> // to use std::set
#include <string>
#include <vector> // to use std::vector
using namespace std;

// function prototypes
// race task #1: reading
void vectorRead(const string, vector<string>&);
void listRead(const string, list<string>&);
void setRead(const string, set<string>&);
// race task #2: sorting
void vectorSort(vector<string>&);
void listSort(list<string>&);
// race task #3: inserting
void vectorInsert(vector<string>&, string);
void listInsert(list<string>&, string);
void setInsert(set<string>&, string);
// race task #4: deleting
void vectorDelete(vector<string>&);
void listDelete(list<string>&);
void setDelete(set<string>&);

int main() 
{
    

    return 0;
}

// void vectorRead(const string codesFile, vector<string>& vector) function header
// DESCRIPTION: this function reads data elements from the input file into the vector (using .push_back(), which adds elements to the end of the vector)
// - the function ensures that the input file was successfully opened before proceeding
// ARGUMENTS: const string codesFile, which represents the input file to read data elements from. Using const to signify that the input file should not be modified
// - vector<string>& vector, which represents the vector container that will hold string data elements
// - passing by reference because the vector will be modified
// RETURNS: nothing, void function
void vectorRead(const string codesFile, vector<string>& vector)
{
    string vectorCodes; // to hold a code/ID from the input file
    ifstream fin(codesFile); // creation of an ifstream (input file) object

    if (!fin) // check if there was an error when opening the input file
    {
        cout << "ERROR: Could not open input file. Please make sure the file exists in the correct location & try again." << endl;
        return; // exit function
    }

    while (fin >> vectorCodes) // reading codes/IDs from the file into the vector
    {
        vector.push_back(vectorCodes); // using .push_back() member function to add codes/IDs from the input file to the end of the vector container
    }

    fin.close(); // close input file
}

// void listRead(const string codesFile, list<string>& list) function header
// DESCRIPTION: this function reads data elements from the input file into the list (using .push_back(), which adds elements to the end of the list)
// - the function ensures that the input file was successfully opened before proceeding
// ARGUMENTS: const string codesFile, which represents the input file to read data elements from. Using const to signify that the input file should not be modified
// - list<string>& list, which represents the list container that will hold string data elements
// - passing by reference because the list will be modified
// RETURNS: nothing, void function
void listRead(const string codesFile, list<string>& list)
{
    string listCodes; // to hold a code/ID from the input file
    ifstream fin(codesFile); // creation of an ifstream (input file) object

    if (!fin) // check if there was an error when opening the input file
    {
        cout << "ERROR: Could not open input file. Please make sure the file exists in the correct location & try again." << endl;
        return; // exit function
    }

    while (fin >> listCodes) // reading codes/IDs from the file into the list
    {
        list.push_back(listCodes); // using .push_back() member function to add codes/IDs from the input file to the end of the list container
    }

    fin.close(); // close input file
}

// void setRead(const string codesFile, set<string>& set) function header
// DESCRIPTION: this function reads data elements from the input file
// - the function ensures that the input file was successfully opened before proceeding
// ARGUMENTS: const string codesFile, which represents the input file to read data elements from. Using const to signify that the input file should not be modified
// - set<string>& set, which represents the set container that will hold string data elements
// - passing by reference because the set will be modified
// RETURNS: nothing, void function
void setRead(const string codesFile, set<string>& set)
{

}