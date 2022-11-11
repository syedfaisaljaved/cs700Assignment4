/*****************************
 * @name Module Name: Shaker Sort. <br>
 * @author Faisal Javed <br>
 * @date 10th November, 2022 <br>
 * Purpose: CS-700 Assignment 4 <br>
 * Student ID: 200491169 <br>
 ****************************/

/// @brief user-defined header @file ShakerSort.h to propagate declarations to code file. <br>
#include "ShakerSort.h"

/*****************************
 * Module Name: Shaker Sort. <br>
 * Author: Faisal Javed <br>
 * Date of Creation: 10th November, 2022 <br>
 * Purpose: main() Function serves as the starting point for program execution.
 *          It has no arguments and returns 0 if the program is executed successfully. <br>
 *          @param [in] void
 *          @return [out] int
 *          @post Post Condition - int is returned.
 ****************************/
int main() {
    /// program execution starts here.

    ShakerSort shakerSort; /// creating an object of @a ShakerSort class
    shakerSort.start(); /// calling the @a ShakerSort::start() function of @a Shaker Sort class
    return 0; /// returns 0 if the program is executed successfully because main() has a return type of integer.

    /// program terminates here.
}
