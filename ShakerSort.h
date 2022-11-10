

#pragma once

#include <iostream>

class ShakerSort {
private:
    int SIZE_OF_ARRAY;
    int *array;
    void fillArrayWithRandomValues();
    void shakerSortAscending(int);
    void shakerSortDescending(int);
    void swap(int &, int &);
    void getArraySizeInput();
    void saveArrayToFile();
    std::string getFileName();

public:
    void start();
};

