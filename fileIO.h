#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class fileIO
{
    //A class for parsing a text file containing a list of numbers into an array
    public:
        // Default constructor
        fileIO();
        // Overloaded constructor
        fileIO(string filepath);
        // Desctructor
        ~fileIO();

        // Method returns an array generated from the file given
        double* getArray();

        string filepath;
        double *output;
        int length;
};
