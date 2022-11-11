/*****************************
 * @name Module Name: Shaker Sort. <br>
 * @author Faisal Javed <br>
 * @date 10th November, 2022 <br>
 * Purpose: CS-700 Assignment 4 <br>
 * Student ID: 200491169 <br>
 ****************************/

/**
  * Code placed here is included only once per translation unit. <br>
  * '#pragma once' is non-standard preprocessor directive intended for implementing compiler-specific preprocessor instructions. <br>
  * It's purpose is to replace the include guards that you use in header files to avoid multiple inclusion. <br>
  * */
#pragma once

#include <iostream> /// library that controls reading from and writing to the standard streams. <br>

/**
 * <br><br> Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining @class ShakerSort which contains variables, methods and constructors.
 *          @var int SIZE_OF_ARRAY
 *          @fn fillArrayWithRandomValues
 *          @fn shakerSortAscending
 *          @fn shakerSortDescending
 *          @fn swap
 *          @fn getArraySizeInput
 *          @fn saveArrayToFile
 *          @fn readArrayFromFile
 *          @fn getFileName
 *          @fn printExecutionTime
 *          @fn printAsteriskLine
 *          @fn getExecutionTime
 *          @fn start
 * */
class ShakerSort {

    /// member variables and functions which are private
private:
    int SIZE_OF_ARRAY; /// stores size of array
    void fillArrayWithRandomValues(); /// fill array with random values
    void shakerSortAscending(int[], int); /// sort array using shaker sort algo in ascending order
    void shakerSortDescending(int[], int); /// sort array using shaker sort algo in descending order
    static void swap(int &, int &); /// swap 2 values
    void getArraySizeInput(); /// get array size from input
    void saveArrayToFile(int [], const std::string&) const; /// save array to file
    void readArrayFromFile(); /// read file and store into an array
    static std::string getFileName(); /// get file name
    static void printExecutionTime(long &, const std::string&); /// print execution time
    static void printAsteriskLine(); /// print * line
    static std::string getExecutionTime(long &); /// gets execution time in milliseconds, microseconds and nanoseconds

    /// member variables and functions which are public
public:
    /**
     * @brief Constructor taking no param
     * @param [in] void
     * @post Post Condition - initialize @a SIZE_OF_ARRAY to 0.
     * */
    ShakerSort();
    void start(); /// this is the base function to run the all other functions of this class after creating an object of this class.
};

