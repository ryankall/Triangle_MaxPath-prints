/* 
 * File:   checkFile.cpp
 * Author: Ryan Kallicharran
 * 
 * Created on May 29, 2016, 6:12 PM
 */



checkFile::checkFile() {
}


//passed triangle by reference to avoid large move cost
void checkFile::start_and_check(int argument, char* filename,
        std::vector< std::vector<int> > &triangle) {
    if (argument != 2) {
        std::cerr << "Error: Enter file name" << std::endl;
        return;
    }
    //check if file exist otherwise exit
    std::ifstream file;
    file.open(filename);
    if (!file.good()) {
        std::cerr << "File file does not exist";
        exit(1);
    }
    /*
     * build our vector while checking
     * if the file content is all numbers and 
     * it is a triangle structure
     */
    std::string line;
    int counter = 1; //keep track of line
    while (std::getline(file, line)) {
        std::vector<int> line_c;

        std::istringstream iss(line);
        std::istringstream convert(line);
        std::string num;
        int counter_l = 0; //keep track of numbers in line per instance of line
        while (iss >> num) {
            //check if string taken is an integer
            if (!isNumeric(num)) {
                std::cerr << "Error::In file:line " << counter << std::endl;
                exit(1);
            }
            //convert string to int
            int curr;
            convert >> curr;
            //add to line vector
            line_c.push_back(curr);
            counter_l++;
        }
        //check if we are forming a triangle as we go
        if (counter_l != counter) {
            std::cerr << "Error::In file:line " << counter << std::endl;
            exit(1);
        }
        //add line to triangle
        triangle.push_back(line_c);
        counter++;
    }
}

bool checkFile::isNumeric(std::string word) {
    if (word[0] == '-') {
		//handles negative numbers
        if (word.find_first_of("1234567890", 1) == -1)
            return false;
    } else {
		//handles postive numbers
        if (word.find_first_of("1234567890") == -1)
            return false;
    }

    return true;
}
