

#ifndef CS700ASSIGNMENT4_SHAKERSORT_H
#define CS700ASSIGNMENT4_SHAKERSORT_H


class ShakerSort {
private:
    int SIZE_OF_ARRAY;
    int *array;
    void fillArrayWithRandomValues();
    void shakerSortAscending(int);
    void shakerSortDescending(int);
    void swap(int &, int &);
    int getArraySizeInput();

public:
    void start();
};


#endif //CS700ASSIGNMENT4_SHAKERSORT_H
