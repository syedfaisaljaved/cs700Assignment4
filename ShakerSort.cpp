
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "ShakerSort.h"

using namespace std;

void ShakerSort::fillArrayWithRandomValues() {

    srand(time(0));

    array = new int[SIZE_OF_ARRAY];

    for (int i = 0U; i < SIZE_OF_ARRAY; i++) {
        array[i] = rand() % SIZE_OF_ARRAY + 1;
    }
}

void ShakerSort::shakerSortAscending(int arraySize) {
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
}

void ShakerSort::shakerSortDescending(int arraySize) {
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

void ShakerSort::swap(int &item1, int &item2) {
    int temp = item1;
    item1 = item2;
    item2 = temp;
}

void ShakerSort::start() {
    getArraySizeInput();
    fillArrayWithRandomValues();
    saveArrayToFile();
    shakerSortAscending(SIZE_OF_ARRAY);
    shakerSortDescending(SIZE_OF_ARRAY);

}

void ShakerSort::saveArrayToFile() {
    ofstream outputStream(getFileName());
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

string ShakerSort::getFileName() {
    return "shaker_sort_output";
}
