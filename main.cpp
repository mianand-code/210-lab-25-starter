// COMSC-210 | Lab 25 | Mira Anand
// Module 9, Lesson: std::list & std::set, Assignment: Data Structures Races
// IDE used: Visual Studio Code for Mac

// In this program, each of the 3 data structures will have its own separate function for each individual race task, for purposes of clarity
// To add new races, all you would need to do is create more functions for the race task you want to add and add more timing code blocks/output statements in main()

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
// race task #4:

int main() 
{
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/