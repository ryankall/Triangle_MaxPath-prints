/* 
 * File:   main.cpp
 * Author: Ryan Kallicharran
 *
 * Created on May 26, 2016, 9:02 PM
 */
#include <iostream>
#include "checkFile.h"
#include "prettyPrint.h"
#include <utility>      // std::pair



/*Note the Printing large triangle that do not fit nicely in your console will 
 *overlap lines.
 */


int main(int argc, char** argv) {

    std::vector< std::vector<int> > triangle;
    checkFile checkAndBuild;
    prettyPrint print;
    
    checkAndBuild.start_and_check(argc, argv[1], triangle );
    
    //print.printTri(triangle);
    
    /*
     * copy vector structure ::complexity for this operation is linear
     * Did this to keep original change triangle
     */    
    std::vector< std::vector<int> > pathKeeper = triangle;
    
    ///////////////////////////////////////////////////////////////////////////
    //                     Finding maximum path                              //
    ///////////////////////////////////////////////////////////////////////////
    
    //path start at top
    for(int i = 1; i< triangle.size(); i++){
        
        
        for(int j = 0; j< triangle[i].size();j++){
            
            if(j == 0){
                /*
                 * if we are left edge of he triangle we must sum 
                 * the upper right
                 */
                int sum = pathKeeper[i-1][j] + pathKeeper[i][j];
                pathKeeper[i][j] = sum;
            }else if( (j+1) == triangle[i].size() ){
                /*
                 * if we are right edge of the triangle we must sum 
                 * the upper left
                 */
                int sum = pathKeeper[i-1][j-1] + pathKeeper[i][j];
                pathKeeper[i][j] = sum;
            }else{
                /*
                 *First two if statement are to handle boundary checking
                 * Now for the real magic
                 * 
                 */
                int sum1 = pathKeeper[i-1][j-1] + pathKeeper[i][j];
                int sum2 = pathKeeper[i-1][j] + pathKeeper[i][j];
                
                /*
                 * Here we compare previously computed best path sum
                 * and add to the following row giving the best path 
                 * at that point in time.
                 * Here you can just change the "< or >" to make 
                 * minimum or maximum path
                 */
                if(sum1 > sum2){
                    pathKeeper[i][j]= sum1;
                }else
                    pathKeeper[i][j]= sum2;
            }
            
        }
        
    }
    
    ///////////////////////////////////////////////////////////////////////////
    //                     Backtracking to find path                         //
    ///////////////////////////////////////////////////////////////////////////
    
   /*
    * print our answer now by simply print the maximum number in the bottom
    * pathKeeper triangle
    */
    
    int sizeA = pathKeeper.size() -1;
    int max = 0;
    for(int i = 0; i <= sizeA; i++){
        if( pathKeeper[sizeA][i] > max )
            max = pathKeeper[sizeA][i];
    }
    
    std::cout<< "The maximum path: " << max <<std::endl;
    
    /*
     *back track to find path
     */
    int sizeP = pathKeeper.size()-1;
    std::vector< std::pair< int, int > > path(sizeP +1);
    int posA;
    
    //find position
    for(int i = 0 ; i < sizeP+1; i++){
        if (max == pathKeeper[(sizeP)][i])
            posA = i;
    }
    
    /*
     * Loop that head backward up the triangle
     */
    for(int i = sizeP; i > 0 ; i--){
        
        if(posA == 0){//handles right bound
            int neg = pathKeeper[i][posA] - pathKeeper[i-1][posA];
            path[i].first= neg;
            path[i].second = i;
            
        }else if( posA == i){//handles left bound
            int neg = pathKeeper[i][posA] - pathKeeper[i-1][posA-1];
            path[i].first= neg;
            path[i].second = i+posA;
            posA--;
        }else{
            //handles middle traversal up
            int neg1 = pathKeeper[i][posA] - pathKeeper[i-1][posA-1];
            int neg2 = pathKeeper[i][posA] - pathKeeper[i-1][posA];
            
            if(neg1 == triangle[i][posA]){
                path[i].first= neg1;
            }else{
                path[i].first = neg2;  
            }
             path[i].second = i+posA;
             posA--;
        }
        
    }
    
    //set top of triangle because we always know we start there
    path[0].first = triangle[0][0];
    path[0].second = 0;
    
    print.printVector(path);
    
    //print.printTri(pathKeeper);
    //print.printTri(triangle);
    //print.printTriMaxPath(triangle, path);// **this function is only for linux Console, it prints the path red in down the triangle
    
    return 0;
}
