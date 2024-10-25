// COMSC-210 | Lab 25 | Mira Anand
// Module 9, Lesson: std::list & std::set, Assignment: Data Structures Races
// IDE used: Visual Studio Code for Mac

// In this program, each of the 3 data structures will have its own separate function for each individual race task, for purposes of clarity
// To add new races, all you would need to do is create more functions for the race task you want to add + add more timing code blocks/output statements in main()

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
using namespace std::chrono; // to use time features

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
    string fileName = "codes.txt"; // to hold the name of the input file to read data elements from
    int durationSetSort = -1; // since std::set automatically sorts on its own, we are using -1 as a placeholder for the sort duration
    string value = "TESTCODE"; // this is the value we will be using for our inserting race

    // creation of the 3 data structure contestants for the races
    vector<string> vectorContestant;
    list<string> listContestant;
    set<string> setContestant;

    // code block #1, race #1: time how long it takes to read data elements into each data structure
    // contestant #1: vector
    auto startVectorRead = high_resolution_clock::now(); // start stopwatch
    vectorRead(fileName, vectorContestant); // vectorRead() function call, will read data elements from the input file into the vector
    auto endVectorRead = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationVectorRead = duration_cast<milliseconds>(endVectorRead - startVectorRead); // calculate the time it took
    // contestant #2: list
    auto startListRead = high_resolution_clock::now(); // start stopwatch
    listRead(fileName, listContestant); // listRead() function call, will read data elements from the input file into the list
    auto endListRead = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationListRead = duration_cast<milliseconds>(endListRead - startListRead); // calculate the time it took
    // contestant #3: set
    auto startSetRead = high_resolution_clock::now(); // start stopwatch
    setRead(fileName, setContestant); // setRead() function call, will read data elements from the input file into the set
    auto endsetRead = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationsetRead = duration_cast<milliseconds>(endsetRead - startSetRead); // calculate the time it took

    // code block #2, race #2: time how long it takes to sort each data structure
    // set will not be participating in this race because it already automatically sorts elements
    // set will have a placeholder of -1 for the sort duration when we output the results of the races
    // contestant #1: vector
    auto startVectorSort = high_resolution_clock::now(); // start stopwatch
    vectorSort(vectorContestant); // vectorSort() function call, will sort the data elements within the vector (according to ASCII)
    auto endVectorSort = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationVectorSort = duration_cast<milliseconds>(endVectorSort - startVectorSort); // calculate the time it took
    // contestant #2: list
    auto startListSort = high_resolution_clock::now(); // start stopwatch
    listSort(listContestant); // listSort() function call, will sort the data elements within the list (according to ASCII)
    auto endListSort = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationListSort = duration_cast<milliseconds>(endListSort - startListSort); // calculate the time it took

    // code block #3, race #3: time how long it takes to insert the value "TESTCODE" into the middle of the vector & list, & into the correct sorted position within the set
    // contestant #1: vector
    auto startVectorInsert = high_resolution_clock::now(); // start stopwatch
    vectorInsert(vectorContestant, value); // vectorInsert() function call, will insert the specified value into the middle of the vector
    auto endVectorInsert = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationVectorInsert = duration_cast<milliseconds>(endVectorInsert - startVectorInsert); // calculate the time it took
    // contestant #2: list
    auto startListInsert = high_resolution_clock::now(); // start stopwatch
    listInsert(listContestant, value); // listInsert() function call, will insert the specified value into the middle of the list
    auto endListInsert = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationListInsert = duration_cast<milliseconds>(endListInsert - startListInsert); // calculate the time it took
    // contestant #3: set
    auto startSetInsert = high_resolution_clock::now(); // start stopwatch
    setInsert(setContestant, value); // setInsert() function call, will insert the specified value into the correct sorted position within the set
    auto endsetInsert = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationsetInsert = duration_cast<milliseconds>(endsetInsert - startSetInsert); // calculate the time it took

    // code block #4, race #4: time how long it takes to delete the middle element of each data structure
    // contestant #1: vector
    auto startVectorDelete = high_resolution_clock::now(); // start stopwatch
    vectorDelete(vectorContestant); // vectorDelete() function call, will delete the middle element of the vector
    auto endVectorDelete = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationVectorDelete = duration_cast<milliseconds>(endVectorDelete - startVectorDelete); // calculate the time it took
    // contestant #2: list
    auto startListDelete = high_resolution_clock::now(); // start stopwatch
    listDelete(listContestant); // listDelete() function call, will delete the middle element of the list
    auto endListDelete = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationListDelete = duration_cast<milliseconds>(endListDelete - startListDelete); // calculate the time it took
    // contestant #3: set
    auto startSetDelete = high_resolution_clock::now(); // start stopwatch
    setDelete(setContestant); // setDelete() function call, will delete the middle element of the set
    auto endsetDelete = high_resolution_clock::now(); // stop stopwatch after function call
    auto durationsetDelete = duration_cast<milliseconds>(endsetDelete - startSetDelete); // calculate the time it took

    // output the results of the races

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
// DESCRIPTION: this function will insert a value into the middle of the list
// ARGUMENTS: list<string>& list, which represents the list container that holds string data elements
// - passing by reference because the list will be modified
// - string value, which represents the value to be inserted
// RETURNS: nothing, void function
void listInsert(list<string>& list, string value)
{
    // using C++ "auto" keyword to create an iterator
    // using .begin() member function to initialize the iterator to start at the beginning of the list
    auto it = list.begin(); 
    // declaration and initialization of a variable named "middle"
    // this variable holds the position of the middle element within the list
    // the middle element is calculated by taking the size (.size()) of the list & dividing it by 2
    int middle = list.size() / 2;

    for (int i = 0; i < middle; i++) // using a for loop to advance the iterator to the position where we want to insert the value
    {
        it++;
    }

    list.insert(it, value); // using .insert() member function to insert the value at the position of the iterator
}

// void setInsert(set<string>& set, string value) function header
// DESCRIPTION: this function will insert a value into the set
// - std::set orders/sorts automatically, so inserting into the middle position does not apply here. The value will be placed in the correct position automatically
// ARGUMENTS: set<string>& set, which represents the set container that holds string data elements
// - passing by reference because the set will be modified
// - string value, which represents the value to be inserted
// RETURNS: nothing, void function
void setInsert(set<string>& set, string value)
{
    set.insert(value); // using the .insert() member function to insert the value into the set
}

// void vectorDelete(vector<string>& vector) function header
// DESCRIPTION: this function deletes the middle element in the vector
// ARGUMENTS: vector<string>& vector, which represents the vector container that holds string data elements
// - passing by reference because the vector will be modified
// RETURNS: nothing, void function
void vectorDelete(vector<string>& vector)
{
    // using C++ "auto" keyword to create an iterator
    // the iterator starts at the beginning (.begin()) of the vector and progresses to the middle element
    // the middle element is calculated by taking the size (.size()) of the vector & dividing it by 2
    // this process causes the iterator to move to the middle position
    auto it = vector.begin() + vector.size() / 2;

    vector.erase(it); // using .erase() member function to delete the value at the position of the iterator
}

// void listDelete(list<string>& list) function header
// DESCRIPTION: this function deletes the middle element in the list
// ARGUMENTS: list<string>& list, which represents the list container that holds string data elements
// - passing by reference because the list will be modified
// RETURNS: nothing, void function
void listDelete(list<string>& list)
{
    // using C++ "auto" keyword to create an iterator
    // using .begin() member function to initialize the iterator to start at the beginning of the list
    auto it = list.begin(); 
    // declaration and initialization of a variable named "middle"
    // this variable holds the position of the middle element within the list
    // the middle element is calculated by taking the size (.size()) of the list & dividing it by 2
    int middle = list.size() / 2;

    for (int i = 0; i < middle; i++) // using a for loop to advance the iterator to the position where we want to delete the value
    {
        it++;
    }

    list.erase(it); // using .erase() member function to delete the value at the position of the iterator
}

// void setDelete(set<string>& set) function header
// DESCRIPTION: this function deletes the middle element in the set
// ARGUMENTS: set<string>& set, which represents the set container that holds string data elements
// - passing by reference because the set will be modified
// RETURNS: nothing, void function
void setDelete(set<string>& set)
{
    // using C++ "auto" keyword to create an iterator
    // using .begin() member function to initialize the iterator to start at the beginning of the set
    auto it = set.begin(); 
    // declaration and initialization of a variable named "middle"
    // this variable holds the position of the middle element within the set
    // the middle element is calculated by taking the size (.size()) of the set & dividing it by 2
    int middle = set.size() / 2;

    for (int i = 0; i < middle; i++) // using a for loop to advance the iterator to the position where we want to delete the value
    {
        it++;
    }

    set.erase(it); // using .erase() member function to delete the value at the position of the iterator
}