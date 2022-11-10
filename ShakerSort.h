

#pragma once

#include <iostream>

class ShakerSort {
private:
    int SIZE_OF_ARRAY;
    void fillArrayWithRandomValues();
    void shakerSortAscending(int[], int);
    void shakerSortDescending(int[], int);
    void swap(int &, int &);
    void getArraySizeInput();
    void saveArrayToFile(int [], std::string);
    void readArrayFromFile();
    std::string getFileName();
    void printExecutionTime(double &);
    void printDashedLine();

public:
    ShakerSort();
    void start();
};

