/*****************************
 * @name Module Name: Shaker Sort. <br>
 * @author Faisal Javed <br>
 * @date 10th November, 2022 <br>
 * Purpose: CS-700 Assignment 4 <br>
 * Student ID: 200491169 <br>
 ****************************/

#include <iostream> /// library that controls reading from and writing to the standard streams. <br>
#include <chrono> /// A framework that relates a time point to real physical time. The library provides at least three clocks that provide means to express the current time.  <br>
#include <cstdlib> /// library that offers reliable and efficient functions for dynamic memory allocation, conversion between datatypes, pseudo-random number generation, process control, searching and sorting, math, and multibyte or wide characters. <br>
#include <iomanip> /// library which helps us in manipulating the output of the program. <br>
#include <fstream> /// library that implements high-level input/output operations on file based streams.
#include "ShakerSort.h" /// user-defined header @file ShakerSort.h to propagate declarations to code file.

/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std. <br>
 * */
using namespace std;
/**
 * 'namespace' is used to organise the names of program entities. <br>
 * The below statement declares that program will be accessing entities whose name are the part of namespace called std::chrono. <br>
 * */
using namespace std::chrono;

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the program starts from here, every function is called within this function for this program to work fine <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - multiple functions are called to completely run the program.
 ****************************/
void ShakerSort::start() {
    getArraySizeInput();
    fillArrayWithRandomValues();
    readArrayFromFile();
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function takes input for array size. it is a recursive function. it will re-run if wrong input is given <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - initialize the @a SIZE_OF_ARRAY var value.
 ****************************/
void ShakerSort::getArraySizeInput() {
    cout << "Enter array size: ";
    cin >> SIZE_OF_ARRAY;
    if(cin.fail()){
        cout << endl << "Wrong input. Try again" << endl << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getArraySizeInput();
    }
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: Array is filled with random values <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - array is filled with random values.
 ****************************/
void ShakerSort::fillArrayWithRandomValues() {

    srand(time(0));

    int *array = new int[SIZE_OF_ARRAY];

    for (int i = 0U; i < SIZE_OF_ARRAY; i++) {
        array[i] = rand() % SIZE_OF_ARRAY + 1;
    }

    saveArrayToFile(array, getFileName());
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: sort array bi-directionally using shaker sort technique in ascending order <br>
 *          @param [in] array
 *          @param [in] arraySize
 *          @return [out] void
 *          @pre Pre Condition - an array and an integer is passed.
 *          @post Post Condition - array is sorted using shaker sort in ascending order.
 ****************************/
void ShakerSort::shakerSortAscending(int array[], int arraySize) {

    bool swapped;
    auto startTime = steady_clock::now(); /// storing the time point representing the current time in @c startTime variable.

    for(int i = 0U; i < arraySize; i++){

        swapped = false;
        for(int j = i; j < arraySize-1; j++){
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
            }
            swapped = true;
        }

        if(!swapped)
            break;

        arraySize--;

        swapped = false;
        for(int j = arraySize-1; j > i; j--){
            if(array[j] < array[j-1]){
                swap(array[j], array[j-1]);
            }
            swapped = true;
        }

        if(!swapped)
            break;
    }

    auto endTime = steady_clock::now(); /// storing the time point representing the current time in @c endTime variable.

    double executionTime = duration_cast<microseconds>(endTime - startTime).count(); /// calculating the elapsed time in millisecond from startTime and endTime.

    printExecutionTime(executionTime);

    saveArrayToFile(array, "shaker_sort_asc");
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: sort array bi-directionally using shaker sort technique in descending order <br>
 *          @param [in] array
 *          @param [in] arraySize
 *          @return [out] void
 *          @pre Pre Condition - an array and an integer is passed.
 *          @post Post Condition - array is sorted using shaker sort in descending order.
 ****************************/
void ShakerSort::shakerSortDescending(int array[], int arraySize) {

    bool swapped;
    auto startTime = steady_clock::now(); /// storing the time point representing the current time in @c startTime variable.

    for(int i = 0U; i < arraySize; i++){

        swapped = false;
        for(int j = i; j < arraySize-i-1; j++){
            if(array[j] < array[j+1]){
                swap(array[j], array[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;

        arraySize--;

        swapped = false;
        for(int j = arraySize-i-1; j > i; j--){
            if(array[j] > array[j-1]){
                swap(array[j], array[j-1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }

    auto endTime = steady_clock::now(); /// storing the time point representing the current time in @c endTime variable.

    double executionTime = duration_cast<microseconds>(endTime - startTime).count(); /// calculating the elapsed time in millisecond from startTime and endTime.

    printExecutionTime(executionTime);

    saveArrayToFile(array, "shaker_sort_desc");

}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: swapping 2 values
 *          @param [in] item1
 *          @param [in] item2
 *          @return [out] void
 *          @pre Pre Condition - 2 integers are passed
 *          @post Post Condition - swaps the values
 ****************************/
void ShakerSort::swap(int &item1, int &item2) {
    int temp = item1;
    item1 = item2;
    item2 = temp;
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function saves the array onto a file <br>
 *          @param [in] array
 *          @param [in] fileName
 *          @return [out] void
 *          @pre Pre Condition - an array and a string is passed
 *          @post Post Condition - file is written and saved
 ****************************/
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

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function reads the file stores it in an array <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - file is read and an array is created
 ****************************/
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

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function returns the filename <br>
 *          @param [in] void
 *          @return [out] string
 *          @post Post Condition - returns the file name
 ****************************/
string ShakerSort::getFileName() {
    return "shaker_sort_output";
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function prints the argument to the console with other information <br>
 *          @param [in] executionTime
 *          @return [out] void
 *          @pre Pre Condition - a double value is passed
 *          @post Post Condition - prints to console
 ****************************/
void ShakerSort::printExecutionTime(double &executionTime) {
    printDashedLine();
    cout << "Execution time for Ascending Shaker sort is: " << fixed << showpoint << setprecision(5) << executionTime << " microseconds" << endl;
    printDashedLine();
    cout << endl;
}

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function prints a * line to console <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - print to console
 ****************************/
void ShakerSort::printDashedLine() {
    cout << "***********************************************************" << endl;
}

ShakerSort::ShakerSort() {
    SIZE_OF_ARRAY = 0; /// variable @a ShakerSort::SIZE_OF_ARRAY is initialized in the constructor.
}
