#include "fileIO.h"

using namespace std;

fileIO::fileIO()
{
    filepath = "input.txt";
}
fileIO::fileIO(string fp)
{
    filepath = fp;
}
fileIO::~fileIO()
{
    //delete output;
}

double* fileIO::getArray()
{
    ifstream file (filepath);

    string line;
    int count = 0;


    if(file.is_open())
    {
        file.clear();
        file.seekg(0);

        getline(file,line);

        length = stoi(line);
        cout << "Sample size:" << endl;
        cout << length << endl;

        //Declare new array for double
        output = new double[length];

        while (getline (file, line))
        {
            output[count++] = stof(line);
        }

        file.close();
    }
    else
    {
        cout << "Invalid filepath" << endl;
    }

    return output;
}
