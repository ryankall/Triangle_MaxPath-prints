
/* 
 * File:   checkFile.h
 * Author: Ryan Kallicharran
 *
 * Created on May 29, 2016, 6:12 PM
 */

#ifndef CHECKFILE_H
#define	CHECKFILE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <sstream>
#include <stdlib.h>

class checkFile {
public:
    checkFile();
    /**
     * check filename and argument and file content
     * @param argument number of arguments
     * @param filename is argument from user
     * @param empty vector of vector to fill
     */
    void start_and_check(int argument, char* filename, std::vector< std::vector<int> > &triangle);

private:
    /**
     * Check if the string only contains numbers
     * @param word this number in string
     * @return true if it is an integer otherwise false
     */
    bool isNumeric(std::string word);
   

};
#include "checkFile.cpp"
#endif	/* CHECKFILE_H */


 
