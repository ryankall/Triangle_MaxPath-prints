/* 
 * File:   prettyPrint.h
 * Author: Ryan Kallicharran
 *
 * Created on May 29, 2016, 8:02 PM
 */

#ifndef PRETTYPRINT_H
#define	PRETTYPRINT_H
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>      //std::setw      
#include <utility>      // std::pair

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

class prettyPrint {
public:
    //default constructor
    prettyPrint();
   
    /**
     * Print triangle nicely
     * @param triangle pass by reference
     */
    void printTri(std::vector< std::vector<int> >  &triangle );
    
    /**
     * Print triangle nicely with path bold
     * @param triangle pass by reference
     * @param path vector holding pairs that has position and value
     */
    void printTriMaxPath(std::vector< std::vector<int> >  &triangle,
                                        std::vector<std::pair<int,int> > &path);
    /**
     * Simply prints vector of pairs
     * @param path vector holding pairs that has position and value
     */
    void printVector(std::vector<std::pair<int,int> > &path);
private:
    /**
     * counts number of digit in a number
     * @param num  
     * @return number of digit in num
     */
    int countDigit(int num);
    
    /**
     * add 0 in front of smaller that max number digit
     * @param num
     * @return string
     */
    std::string addDigits(int num, int max);

};
#include "prettyPrint.cpp"
#endif	/* PRETTYPRINT_H */

