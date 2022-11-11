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
 *          @fn printDashedLine
 *          @fn start
 * */
class ShakerSort {

    /// member variables and functions which are private
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

    /// member variables and functions which are public
public:
    /**
     * @brief Constructor taking no param
     * @param [in] void
     * @post Post Condition - initialize @a SIZE_OF_ARRAY to 0.
     * */
    ShakerSort();
    void start();
};

