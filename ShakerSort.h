/*****************************
 * @name Module Name: Shaker Sort. <br>
 * @author Faisal Javed <br>
 * @date 10th November, 2022 <br>
 * Purpose: CS-700 Assignment 4 <br>
 * Student ID: 200491169 <br>
 ****************************/

/**
 * @internal
  * Code placed here is included only once per translation unit. <br>
  * '#pragma once' is non-standard preprocessor directive intended for implementing compiler-specific preprocessor instructions. <br>
  * It's purpose is to replace the include guards that you use in header files to avoid multiple inclusion. <br>
  * */
#pragma once

/// @brief library that controls reading from and writing to the standard streams. <br>
#include <iostream>

/**
 * <br><br> Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: Class is a user-defined data type, which holds its own data members and member functions,
 *          which can be accessed and used by creating an instance of that class.
 *          Defining class ShakerSort which contains variables, methods and constructors.
 * */
class ShakerSort {

private:
    /**
     * @brief stores size of array <br>
     */
    int SIZE_OF_ARRAY;

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: Array is filled with random values <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - array is filled with random values.
 ****************************/
    void fillArrayWithRandomValues();

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
    void shakerSortAscending(int[], int);

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
    void shakerSortDescending(int[], int);

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
    static void swap(int &, int &);

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function takes input for array size. it is a recursive function. it will re-run if wrong input is given <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - initialize the @a ShakerSort::SIZE_OF_ARRAY var value.
 ****************************/
    void getArraySizeInput();

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
    void saveArrayToFile(int [], const std::string&) const;

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function reads the file stores it in an array <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - file is read and an array is created
 ****************************/
    void readArrayFromFile();

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function returns the filename <br>
 *          @param [in] void
 *          @return [out] string
 *          @post Post Condition - returns the file name
 ****************************/
    static std::string getFileName();

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function prints the argument to the console with other information <br>
 *          @param [in] executionTime
 *          @param [in] sortType
 *          @return [out] void
 *          @pre Pre Condition - a double value and a string is passed
 *          @post Post Condition - prints to console
 ****************************/
    static void printExecutionTime(long &, const std::string&);

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function prints a * line to console <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - print to console
 ****************************/
    static void printAsteriskLine();

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the function returns a string in formatted fashion <br>
 *          @param [in] executionTime
 *          @return [out] string
 *          @pre Pre Condition - a long value is passed
 *          @post Post Condition - returns a string
 ****************************/
    static std::string getExecutionTime(long &);

public:
    /**
     * @brief Constructor taking no param
     * @post Post Condition - initialized array size var to 0.
     * */
    ShakerSort();

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: the program starts from here, every function is called within this function for this program to work fine <br>
 *          @param [in] void
 *          @return [out] void
 *          @post Post Condition - multiple functions are called to completely run the program.
 ****************************/
    void start();
};

