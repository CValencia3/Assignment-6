#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>

#include "fileIO.h"

using namespace std;

void analyze(string filepath);
void copyArrays(double * master, double * cloneA,
    double * cloneB, double * cloneC, double * cloneD, int size);

void bubbleSort(double array[], int length);
void insertionSort(double array[], int length);
void quickSort(double array[], int lo, int hi);
int partition(double array[], int lo, int hi);
void shellSort(double array[], int length);

int main(int argc, char const *argv[])
{
    bool debug = true;
    if(debug)
    {
        analyze("input.txt");
    }
    else
    {
        if((argc > 0) && (argv[1] != NULL))
        {
            string filepath = argv[1];
            try
            {
                analyze(filepath);
            }
            catch(const invalid_argument& message)
            {
                cout << message.what() << endl;
                cout << "Invalid file." << endl;
            }
        }
        else
        {
            cout << "Please provide the file path for a text document" << endl;
        }

        cout << "\nThe program exited successfully." << endl;
    }
    return 0;

}

void analyze(string filepath)
{
    int length;
    clock_t time;

    cout << "Creating fileIO" << endl << endl;
    fileIO in = fileIO(filepath);


    cout << "Reading from file..." << endl << endl;
    double * master = in.getArray();
    length = in.length;

    double * copyOne = new double[length];
    double * copyTwo = new double[length];
    double * copyThree = new double[length];
    double * copyFour = new double[length];

    cout << "Copying master for testing" << endl << endl;
    copyArrays(master, copyOne, copyTwo, copyThree, copyFour, length);

    cout<< "-----Begin testing-----" << endl << endl;

    cout << "Bubble Sort" << endl;
    cout << "   Start" << endl;
    time = clock();
    bubbleSort(copyOne, length);
    time = clock() - time;
    cout << "   Process completed in " << (double)time/CLOCKS_PER_SEC << " seconds" << endl << endl;

    cout << "Insertion Sort" << endl;
    cout << "   Start" << endl;
    time = clock();
    insertionSort(copyTwo, length);
    time = clock() - time;
    cout << "   Process completed in " << (double)time/CLOCKS_PER_SEC << " seconds" << endl << endl;

    cout << "Quick Sort" << endl;
    cout << "   Start" << endl;
    cout << "   Working..." << endl;
    time = clock();
    quickSort(copyThree, 0, length);
    time = clock() - time;
    cout << "   Process completed in " << (double)time/CLOCKS_PER_SEC << " seconds" << endl << endl;

    cout << "Shell Sort" << endl;
    cout << "   Start" << endl;
    time = clock();
    shellSort(copyFour, length);
    time = clock() - time;
    cout << "   Process completed in " << (double)time/CLOCKS_PER_SEC << " seconds" << endl << endl;

    cout << "Testing complete. Thank you." << endl << endl;

    //cout << "Deleting dynamically allocated copies..." << endl << endl;

    //delete [] copyOne;

    cout << "Done" << endl << endl;
}

void copyArrays(double * master, double * cloneA,
    double * cloneB, double * cloneC, double * cloneD, int size)
{
    for (int i = 0; i < size; i++)
    {
        cloneA[i] = master[i];
        cloneB[i] = master[i];
        cloneC[i] = master[i];
        cloneD[i] = master[i];
    }
}

void bubbleSort(double array[], int length)
{
    cout << "   Working..." << endl;
    for(int i = 0; i<length; ++i)
    {
        int temp = 0;
        for(int j = i; j < length-1; ++j)
        {
            if(array[j] > array[j+i])
            {
                temp = array[j+i];
                array[j+i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void insertionSort(double array[], int length)
{
    cout << "   Working..." << endl;
    for(int j = 1; j < length; ++j)
    {
        double temp = array[j];
        int k = j;
        while(k>0 && array[k-1] >= temp)
        {
            array[k] = array[k-1];
            --k;
        }
        array[k] = temp;
    }
}

void quickSort(double array[], int lo, int hi)
{
    if(lo < hi)
    {
        int pi = partition(array, lo, hi);

        quickSort(array, lo, pi - 1);
        quickSort(array, pi + 1, hi);
    }
}
int partition(double array[], int lo, int hi)
{
    double temp;
    double pivot = array[hi];

    int i = lo - 1;

    for(int j = lo; j <= hi-1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;

        }
    }
    temp = array[hi];
    array[hi] = array[i + 1];
    array[i + 1] = temp;
    return i + 1;
}

void shellSort(double array[], int length)
{
    cout << "   Working..." << endl;
    for (int gap = length/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < length; i += 1)
        {
            int temp = array[i];
            int j;
            for(j=i; j>=gap && array[j-gap] > temp; j -=gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}
