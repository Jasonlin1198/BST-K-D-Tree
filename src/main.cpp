//
// main.cpp
// CSE 100 Project 1
//
// Last modified by Heitor Schueroff on 01/10/2019
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#include "BST.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Check for Arguments
    if (argc != 2) {
        cout << "Invalid number of arguments.\n"
             << "Usage: ./main <input filename>.\n";
        return -1;
    }

    // Open file
    ifstream in;
    in.open(argv[1], ios::binary);

    // Check if input file was actually opened
    if (!in.is_open()) {
        cout << "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }

    // Check for empty file
    in.seekg(0, ios_base::end);
    unsigned int len = in.tellg();
    if (len == 0) {
        cout << "The file is empty. \n";
        return -1;
    }

    // Resets the stream to beginning of file
    in.seekg(0, ios_base::beg);

    // Construct a BST
    BST<string> tree; 
    string line;

    // Read in the actor names from file
    while (getline(in, line)) {
        tree.insert(line);
    }

    cout << "Size of tree: " << tree.size() << "\n";
    cout << "Height of tree: " << tree.height() << "\n";

    string name = "";
    char response = 'y';

    // Prompt user for an actor name
    while (response == 'y') {
        cout << "Enter actor/actress name: " << "\n";
        getline(cin, name);

        // Look for provided name in the BST
        BST<string>::iterator item = tree.find(name);
        if (item != 0 && item != tree.end()) {
            cout << name << " found!" << "\n";
        } else {
            cout << name << " NOT found" << "\n";
        }

        cout << "Search again? (y/n)" << "\n";
        cin >> response;
        cin.ignore();

        if (response != 'n' && response != 'y') {
            cout << "Invalid response, exiting..." << endl;
            break;
        }
    }

    // Close the file
    if (in.is_open()) {
        in.close();
    }

    return 0;
}
