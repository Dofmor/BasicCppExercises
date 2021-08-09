/*
 * ReadToVector.cpp
 * @author Daniel Morales
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
 * reads textfile into a vector
 * @param fileName name of file to be read
 * @param num vector where file contents are to be inputted
 */
void readFile(std::string fileName, std::vector<int>& num){
    std::ifstream inputFile;
    inputFile.open(fileName);

    if(inputFile.is_open()){
        std::cout << "File found\n";

        int fileInput;
        while(inputFile >>  fileInput){
            num.push_back(fileInput);
        }
    }
    else
        std::cout << "File not found\n";
}

/*
 * prints vector
 * @param num the vector to be printed
 */
void printVector(const std::vector<int>& num){
    for (int e : num)
        std::cout << e << "\n";

}

/*
 * empties vector
 * @param num the vector to be emptied
 */
void emptyVector(std::vector<int>& num){
    num.clear();
    std::cout << "Vector is now empty\n";
}

int linearSearch(const std::vector<int>& num, int value){
    int index = 0, position = -1;
    bool found = false;

    while (found == false){
        if (num[index] == value){
            position = index;
            found = true;
        }
        else
            index ++;
    }


    return position;
}

int main() {
    std::vector<int> numbers;
    std::string fileName;

    std::cout << "Please enter a file name\n";
    std::cin >> fileName;

    readFile(fileName, numbers);
    printVector(numbers);

    std::cout << "Search for a number\n";

    int value;
    std::cin >> value;
    std::cout << linearSearch(numbers, value) << "\n";

    std::cout << "Goodbye\n";

}








