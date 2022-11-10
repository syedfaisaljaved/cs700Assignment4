
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
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
