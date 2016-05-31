/* 
 * File:   prettyPrint.cpp
 * Author: Ryan kallicharran
 * 
 * Created on May 29, 2016, 8:02 PM
 */



prettyPrint::prettyPrint() {
}

void prettyPrint::printTri(std::vector< std::vector<int> >  &triangle ){
    
    int sizeD;
    int max = 0;
    
    //find largest number in triangle
    for(int i = 0; i< triangle.size(); i++){
        for(int j = 0; j< triangle[i].size();j++){
            if(triangle[i][j] > max)
                max = triangle[i][j];
        }     
    }
       
    sizeD = countDigit(max);
    int sizeOfTri = (triangle.size()-1)*sizeD;
    
    //formatting output
    for(int i = 0; i< triangle.size(); i++){
       std::string value;
       
       for(int j = 0; j< triangle[i].size();j++){
           std::string digitsH;
           digitsH = digitsH + addDigits(countDigit(triangle[i][j]),sizeD);

           if( j== 0){
               std::cout<< std::setw(sizeOfTri+ sizeD)<< digitsH<<triangle[i][j] <<" ";
           }else
               std::cout<< digitsH << triangle[i][j]<<" ";
       }
        sizeOfTri-=sizeD;
        std::cout<<std::endl;
    }
}

void prettyPrint::printTriMaxPath(std::vector< std::vector<int> >  &triangle,
                                                    std::vector<std::pair<int,int> >  &path ){
    
    int sizeD;
    int max = 0;
    
    //find largest number in triangle
    for(int i = 0; i< triangle.size(); i++){
        for(int j = 0; j< triangle[i].size();j++){
            if(triangle[i][j] > max)
                max = triangle[i][j];
        }     
    }
    
    sizeD = countDigit(max);
    int sizeOfTri = (triangle.size()-1)*sizeD;
    //formatting output
    for(int i = 0; i< triangle.size(); i++){   
       std::string value;

       for(int j = 0; j< triangle[i].size();j++){
           std::string digitsH;
           digitsH = digitsH + addDigits(countDigit(triangle[i][j]),sizeD);

           if((triangle[i][j] == path[i].first) && ((i+j) == path[i].second) ){
               if( j== 0){     
                   std::cout<< RED << std::setw(sizeOfTri + sizeD) << 
                               digitsH << triangle[i][j] << RESET <<" ";
               }else
                   std::cout<< RED <<digitsH << triangle[i][j]<< RESET <<" ";
           }else{
               if( j== 0){     
                   std::cout<< std::setw(sizeOfTri +sizeD)<< digitsH<<triangle[i][j] <<" ";
               }else
                   std::cout<< digitsH << triangle[i][j]<<" ";
           }
       }
       sizeOfTri-= sizeD; 
       std::cout<<std::endl;
   }
}

void prettyPrint::printVector(std::vector<std::pair<int,int> > &path){
    std::cout<<"Path: ";
    for(int i = 0; i< path.size(); i++){
        std::cout<< path[i].first<< " ";
    }
    std::cout<<std::endl;
}

///////////////////////////////////////////////////////////////////////////
//                     Private functions                                 //
///////////////////////////////////////////////////////////////////////////
int prettyPrint::countDigit(int num){
    
    int digits = 1;
    while( num >= 10 ){
        num = num/10;
        digits++;
    }   
    return digits;
}

std::string prettyPrint::addDigits(int num, int max){
    num = max - num;
    std::string zeros;
    for(int i = 0 ; i < num; i++)
        zeros = zeros + "0";
    return zeros;      
}
