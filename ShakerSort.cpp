
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include "ShakerSort.h"

void ShakerSort::fillArrayWithRandomValues() {

    srand(time(0));

    array = new int[SIZE_OF_ARRAY];

    for (int i = 0U; i < SIZE_OF_ARRAY; i++) {
        array[i] = rand() % SIZE_OF_ARRAY + 1;
    }
}

void ShakerSort::shakerSortAscending() {

}

void ShakerSort::shakerSortDescending() {

}

int ShakerSort::getArraySizeInput() {
    return 0;
}
