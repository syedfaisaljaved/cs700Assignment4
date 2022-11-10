
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include "ShakerSort.h"

using namespace std;
using namespace std::chrono;

void ShakerSort::start() {
    getArraySizeInput();
    fillArrayWithRandomValues();
    readArrayFromFile();
}

void ShakerSort::getArraySizeInput() {
    cout << "Enter array size: ";
    cin >> SIZE_OF_ARRAY;
    if(cin.fail()){
        cout << "Wrong input. Try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getArraySizeInput();
    }
}

void ShakerSort::fillArrayWithRandomValues() {

    srand(time(0));

    int *array = new int[SIZE_OF_ARRAY];

    for (int i = 0U; i < SIZE_OF_ARRAY; i++) {
        array[i] = rand() % SIZE_OF_ARRAY + 1;
    }

    saveArrayToFile(array, getFileName());
}

void ShakerSort::shakerSortAscending(int array[], int arraySize) {

    auto startTime = steady_clock::now(); /// storing the time point representing the current time in @c startTime variable.

    for(int i = 0U; i < arraySize; i++){
        for(int j = i; j < arraySize-1; j++){
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
        arraySize--;
        for(int j = arraySize-1; j > i; j--){
            if(array[j] < array[j-1]){
                swap(array[j], array[j-1]);
            }
        }
        i++;
    }

    auto endTime = steady_clock::now(); /// storing the time point representing the current time in @c endTime variable.

    double executionTime = duration_cast<nanoseconds>(endTime - startTime).count(); /// calculating the elapsed time in millisecond from startTime and endTime.

    printExecutionTime(executionTime);

    saveArrayToFile(array, "shaker_sort_asc");
}

void ShakerSort::shakerSortDescending(int array[], int arraySize) {

    auto startTime = steady_clock::now(); /// storing the time point representing the current time in @c startTime variable.

    for(int i = 0U; i < arraySize; i++){
        for(int j = i; j < arraySize-1; j++){
            if(array[j] < array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
        arraySize--;
        for(int j = arraySize-1; j > i; j--){
            if(array[j] > array[j-1]){
                swap(array[j], array[j-1]);
            }
        }
        i++;
    }

    auto endTime = steady_clock::now(); /// storing the time point representing the current time in @c endTime variable.

    double executionTime = duration_cast<nanoseconds>(endTime - startTime).count(); /// calculating the elapsed time in millisecond from startTime and endTime.

    printExecutionTime(executionTime);

    saveArrayToFile(array, "shaker_sort_desc");

}

void ShakerSort::swap(int &item1, int &item2) {
    int temp = item1;
    item1 = item2;
    item2 = temp;
}

void ShakerSort::saveArrayToFile(int array[], string fileName) {
    ofstream outputStream(fileName);
    if (!outputStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to open a file to write operations.");
    }

    for(int i = 0U; i < SIZE_OF_ARRAY; i++){
        outputStream << array[i] << " ";
    }

    outputStream.close();
}

void ShakerSort::readArrayFromFile() {
    /**
     * creating an object of input file stream to perform read operations.
     * takes @c getFileInputName() function as an argument which returns the file name.
     * */
    ifstream fileStream(getFileName());

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!fileStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to read file.");
    }

    int *shakerSortAscArray = new int[SIZE_OF_ARRAY];
    int *shakerSortDescArray = new int[SIZE_OF_ARRAY];
    int arrayElement;
    int index = 0U;
    while(fileStream >> arrayElement){
        shakerSortAscArray[index] = arrayElement;
        shakerSortDescArray[index] = arrayElement;
        index++;
    }

    shakerSortAscending(shakerSortAscArray, SIZE_OF_ARRAY);
    shakerSortDescending(shakerSortDescArray, SIZE_OF_ARRAY);

}

string ShakerSort::getFileName() {
    return "shaker_sort_output";
}

void ShakerSort::printExecutionTime(double &executionTime) {
    printDashedLine();
    cout << "Execution time for Ascending Shaker sort is: " << executionTime << "nanoseconds" << endl;
    printDashedLine();
}

void ShakerSort::printDashedLine() {
    cout << "***********************************************************" << endl;
}

ShakerSort::ShakerSort() {
    SIZE_OF_ARRAY = 0;
}
