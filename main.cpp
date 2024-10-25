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
// std::set does not need a function to sort since it does this automatically
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
// DESCRIPTION: this function reads data elements from the input file and adds them to the vector (using .push_back(), which adds elements to the end of the vector)
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
// DESCRIPTION: this function reads data elements from the input file and adds them to the list (using .push_back(), which adds elements to the end of the list)
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
// DESCRIPTION: this function reads data elements from the input file and inserts them into the set
// - using .insert(), which inserts elements into the set. Set ensures that elements are ordered/sorted automatically
// - the function ensures that the input file was successfully opened before proceeding
// ARGUMENTS: const string codesFile, which represents the input file to read data elements from. Using const to signify that the input file should not be modified
// - set<string>& set, which represents the set container that will hold string data elements
// - passing by reference because the set will be modified
// RETURNS: nothing, void function
void setRead(const string codesFile, set<string>& set)
{
    string setCodes; // to hold a code/ID from the input file
    ifstream fin(codesFile); // creation of an ifstream (input file) object

    if (!fin) // check if there was an error when opening the input file
    {
        cout << "ERROR: Could not open input file. Please make sure the file exists in the correct location & try again." << endl;
        return; // exit function
    }

    while (fin >> setCodes) // reading codes/IDs from the file into the set
    {
        set.insert(setCodes); // using .insert() member function to insert codes/IDs from the input file into the set container
    }

    fin.close(); // close input file
}

// void vectorSort(vector<string>& vector) function header
// DESCRIPTION: this function sorts the elements within the vector
// since the data elements are string codes/IDs, they will be sorted according to ASCII
// ARGUMENTS: vector<string>& vector, which represents the vector container that holds string data elements
// - passing by reference because the vector will be modified
// RETURNS: nothing, void function
void vectorSort(vector<string>& vector)
{
    sort(vector.begin(), vector.end()); // using sort member function to sort the contents of the vector from beginning to end
}

// void listSort(list<string>& list) function header
// DESCRIPTION: this function sorts the elements within the list
// since the data elements are string codes/IDs, they will be sorted according to ASCII
// ARGUMENTS: list<string>& list, which represents the list container that holds string data elements
// - passing by reference because the list will be modified
// RETURNS: nothing, void function
void listSort(list<string>& list)
{
    list.sort(); // using .sort() member function to sort the contents of the list
}

// void vectorInsert(vector<string>& vector, string value) function header
// DESCRIPTION: this function will insert a value into the middle of the vector
// ARGUMENTS: vector<string>& vector, which represents the vector container that holds string data elements
// - passing by reference because the vector will be modified
// - string value, which represents the value to be inserted
// RETURNS: nothing, void function
void vectorInsert(vector<string>& vector, string value)
{
    // using C++ "auto" keyword to create an iterator
    // the iterator starts at the beginning (.begin()) of the vector and progresses to the middle element
    // the middle element is calculated by taking the size (.size()) of the vector & dividing it by 2
    // this process causes the iterator to move to the middle position
    auto it = vector.begin() + vector.size() / 2;

    vector.insert(it, value); // using .insert() member function to insert the value at the position of the iterator
}

// void listInsert(list<string>& list, string value) function header
// DESCRIP