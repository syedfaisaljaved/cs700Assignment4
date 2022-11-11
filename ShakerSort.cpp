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
#include <sstream> /// library that implements high-level input/output operations on file based streams.
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
    getArraySizeInput(); /// calling @a getArraySizeInput to get the array size
    fillArrayWithRandomValues(); /// calling @a fillArrayWithRandomValues to fill the array with random values
    readArrayFromFile(); /// calling @a readArrayFromFile to read file and perform shaker sort and calculate execution time.
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
    cout << "Enter array size: "; /// printing a statement to console
    cin >> SIZE_OF_ARRAY; /// storing the size of array from input

    /**
     * returns [true] if either (or both) failbit or the badbit error state flags is set for the stream.
     * @if we encounter a string it will return true as it failed to parse it as an integer.
     * */
    if(cin.fail()){
        cout << endl << "Wrong input. Try again" << endl << endl;
        cin.clear(); /// we will clear the error state flags and re-parse the stream properly.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); /// function is used which is used to ignore or clear one or more characters from the input buffer.
        getArraySizeInput(); /// calling @a getArraySizeInput recursively
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

    /**
     * The pseudo-random number generator is initialized using the argument passed as seed. <br>
     * For every different seed value used in a call to srand, the pseudo-random number generator can be expected to generate
     * a different succession of results in the subsequent calls to rand.
     * passed time(0) function that returns the current time in seconds. <br>
     * */
    srand(time(0));

    int *array = new int[SIZE_OF_ARRAY]; /// creating an array pointer of integers of size @a SIZE_OF_ARRAY

    for (int i = 0U; i < SIZE_OF_ARRAY; i++) {
        array[i] = rand() % SIZE_OF_ARRAY + 1; /// using rand() function to generate a random value from 1 to SIZE_OF_ARRAY
    }

    saveArrayToFile(array, getFileName()); /// calling @a saveArrayToFile to save the array to a file.
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

    bool swapped; /// creating a bool flag to check base conditions of shaker sort

    auto startTime = high_resolution_clock::now(); /// storing the time point representing the current time in @c startTime variable.

    /// using for loop to iterate through array
    /// U as a suffix to 0 means only unsigned values
    for(int i = 0U; i < arraySize; i++){

        swapped = false; /// setting flag to false by default.

        /// using for loop to iterate through array
        for(int j = i; j < arraySize-1; j++){
            /// @if the current element is greater than the next element then swap
            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]); /// calling function @a swap to swap values of 2 integers.
            }
            swapped = true; /// setting flag to true if swap is occurred.
        }

        /// @if bool is set to false it means no swap is occurred so the loop will break as the array is already sorted.
        if(!swapped)
            break;

        arraySize--; /// reducing array size so as to not include the sorted element in next iteration.

        swapped = false; /// setting flag to false by default for another loop.

        /// using for loop to iterate through array
        for(int j = arraySize-1; j > i; j--){
            /// @if the previous element is greater than the current element then swap
            if(array[j] < array[j-1]){
                swap(array[j], array[j-1]);  /// calling function @a swap to swap values of 2 integers.
            }
            swapped = true; /// setting flag to true if swap is occurred.
        }

        /// @if bool is set to false it means no swap is occurred so the loop will break as the array is already sorted.
        if(!swapped)
            break;
    }

    auto endTime = high_resolution_clock::now(); /// storing the time point representing the current time in @c endTime variable.

    double executionTime = duration_cast<nanoseconds>(endTime - startTime).count(); /// calculating the elapsed time in millisecond from startTime and endTime.

    printExecutionTime(executionTime); /// calling @a printExecutionTime to print the execution time.

    saveArrayToFile(array, "shaker_sort_asc"); /// calling @a saveArrayToFile to save the array to a file.
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

    bool swapped; /// creating a bool flag to check base conditions of shaker sort

    auto startTime = high_resolution_clock::now(); /// storing the time point representing the current time in @c startTime variable.

    /// using for loop to iterate through array
    /// U as a suffix to 0 means only unsigned values
    for(int i = 0U; i < arraySize; i++){

        swapped = false; /// setting flag to false by default.

        /// using for loop to iterate through array
        for(int j = i; j < arraySize-1; j++){
            /// @if the current element is smaller than the next element then swap
            if(array[j] < array[j+1]){
                swap(array[j], array[j+1]); /// calling function @a swap to swap values of 2 integers.
            }
            swapped = true; /// setting flag to true if swap is occurred.
        }

        /// @if bool is set to false it means no swap is occurred so the loop will break as the array is already sorted.
        if(!swapped)
            break;

        arraySize--; /// reducing array size so as to not include the sorted element in next iteration.

        swapped = false; /// setting flag to false by default for another loop.

        /// using for loop to iterate through array
        for(int j = arraySize-1; j > i; j--){
            /// @if the previous element is smaller than the current element then swap
            if(array[j] > array[j-1]){
                swap(array[j], array[j-1]);  /// calling function @a swap to swap values of 2 integers.
            }
            swapped = true; /// setting flag to true if swap is occurred.
        }

        /// @if bool is set to false it means no swap is occurred so the loop will break as the array is already sorted.
        if(!swapped)
            break;
    }

    auto endTime = high_resolution_clock::now(); /// storing the time point representing the current time in @c endTime variable.

    double executionTime = duration_cast<nanoseconds>(endTime - startTime).count(); /// calculating the elapsed time in millisecond from startTime and endTime.

    printExecutionTime(executionTime); /// calling @a printExecutionTime to print the execution time.

    saveArrayToFile(array, "shaker_sort_desc"); /// calling @a saveArrayToFile to save the array to a file.
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
    int temp = item1; /// using a temporary variable to store the first value. <br>
    item1 = item2; /// assigning the value of 2nd variable to first variable. <br>
    item2 = temp; /// assigning the value of first variable stored in a temporary variable to the 2nd variable. <br>
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
void ShakerSort::saveArrayToFile(int array[], const string& fileName) const {

    /**
     * creating an object of output file stream to perform write operations.
     * takes @c filename as an argument.
     * */
    ofstream outputStream(fileName);

    /// Checks if the file is NOT opened then throw an error and stop the program.
    if (!outputStream.is_open()) {
        /**
         * throw is a keyword to define custom exceptions.
         * We will @throw runtime_error exception if the file is unable to open.
         * */
        throw invalid_argument("Unable to open a file to write operations.");
    }

    /// using for loop to iterate through array
    /// U as a suffix to 0 means only unsigned values
    for(int i = 0U; i < SIZE_OF_ARRAY; i++){
        outputStream << array[i] << " "; /// store the array value to file.
    }

    outputStream.close(); /// closing the @c outputStream after performing the write operations.
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

    int *shakerSortAscArray = new int[SIZE_OF_ARRAY]; /// creating an array for shaker sort ascending order
    int *shakerSortDescArray = new int[SIZE_OF_ARRAY]; /// creating an array for shaker sort descending order
    int arrayElement; /// creating a variable to store values from file after each iteration.
    int index = 0U; /// creating a variable to loop through the array
    while(fileStream >> arrayElement){
        shakerSortAscArray[index] = arrayElement; /// storing the value to array from stream
        shakerSortDescArray[index] = arrayElement; /// storing the value to array from stream
        index++; /// incrementing the index
    }

    shakerSortAscending(shakerSortAscArray, SIZE_OF_ARRAY); /// calling @a shakerSortAscending to sort the array
    shakerSortDescending(shakerSortDescArray, SIZE_OF_ARRAY); /// calling @a shakerSortDescending to sort the array

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
    return "shaker_sort_output"; /// return the file name
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
    printDashedLine(); /// print a * line to console.
    cout << "Execution time for Ascending Shaker sort is: " << getExecutionTime(executionTime) << endl; /// print execution time to console.
    printDashedLine(); /// print a * line to console.
    cout << endl; /// printing newline
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
    cout << "***********************************************************" << endl; /// printing * line to console
}

ShakerSort::ShakerSort() {
    SIZE_OF_ARRAY = 0; /// variable @a ShakerSort::SIZE_OF_ARRAY is initialized in the constructor.
}

string ShakerSort::getExecutionTime(double &executionTime) {
    ostringstream oss;
    oss << fixed << showpoint << setprecision(5);
    if(executionTime > 1000000.0){
        oss << executionTime/1000000.0 << " millisecond";
    } else if(executionTime > 1000.0) {
        oss << executionTime/1000.0 << " microseconds";
    } else {
        oss << executionTime << " nanoseconds";
    }
    return oss.str();
}
