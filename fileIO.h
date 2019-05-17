#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class fileIO
{
    public:
        // Default constructor
        fileIO();
        // Overloaded constructor
        fileIO(string filepath);
        // Desctructor
        ~fileIO();

        // Method to turn input into a queue
        double* getArray();

        string filepath;
        double *output;
        int length;
};
