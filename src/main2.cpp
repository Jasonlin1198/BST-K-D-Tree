//
// main2.cpp
// CSE 100 Project 1
//
// Last modified by Heitor Schueroff on 01/10/2019
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#include "KDT.hpp"

using namespace std;

/*
 * IMPORTANT!! YOU MUST FORMAT PROMPTS AND OUTPUTS AS FOLLOWS: 
 *
 *      To output size of tree: 
 *          cout << "Size of tree: " << size << "\n"; 
 *
 *      To output height of tree: 
 *          cout << "Height of tree: " << height << "\n"; 
 *
 *      To prompt the user to enter a coordinate: 
 *          cout << "Enter coordinate (x y): " << "\n";
 *
 *      To output the result of the nearest neighbor search: 
 *          cout << "Nearest point in tree: " << nearestNeighbor << "\n"; 
 *
 *      To prompt the user to try again: 
 *          cout << "Search again? (y/n)" << "\n";
 *
 * Use cin to process user input.
 *
 * You MUST output size, then height, then prompt the user to search, as above.
 *
 * You MUST have the prompt for entering the name appear if and only if
 * the user input for trying again is "y" followed by the return key
 *
 * You MUST have the program exit (exiting the prompt loop) if and only if
 * the user input for trying again is "n" followed by the return key
 *
 * You should handle other inputs for the retry prompt,
 * but we will not be testing them.
 *
 * Note that size, height, and nearestNeighbor are local variables in main that
 * you should update accordingly.
 */

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

    // 
    // TODO your main2 implementation should go here
    //

    if (in.is_open()) {
        in.close();
    }

    return 0;
}
