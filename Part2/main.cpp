#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <vector>
#include <array>
#include <sstream>

bool isLevelValid(std::string level);
bool isNotInRange(int num1, int num2);

int main() {
    std::ifstream infile;

    infile.open("../input.txt");
    if (!infile.is_open()) {
        std::cout << "Input file opening failed." << std::endl;
    }

    std::vector<std::string> fileData;

    for (u_int i = 0; !infile.eof(); i++) {
        fileData.push_back("");
        getline(infile, fileData.at(i));
    }

    int numSafeReports = 0;
    for (std::string level : fileData) {
        if (isLevelValid(level)) {
            std::cout << "Safe" << std::endl;
            numSafeReports++;
        } else {
            std::cout << "Unsafe" << std::endl;
        }
    }

    std::cout << "Safe reports: " << numSafeReports << std::endl;

}

bool isLevelValid(std::string level) {

    std::stringstream ss(level);
    std::vector<int> levelNums;
    std::string currentNum;

    while (std::getline(ss, currentNum, ' ')) {
        levelNums.push_back(stoi(currentNum));
    }

    bool ascendingOrDescending = false;
    //*Check if the level is in ascending order
    if (std::is_sorted(levelNums.begin(), levelNums.end())) {
        ascendingOrDescending = true;
    }

    //*Check if the level is in descending order
    std::reverse(levelNums.begin(), levelNums.end());
    if (std::is_sorted(levelNums.begin(), levelNums.end())) {
        ascendingOrDescending = true;
    }
    std::reverse(levelNums.begin(), levelNums.end()); //Reverse back to normal

    if (ascendingOrDescending == false) {
        return false;
    }

    //*Check that no two values are the same
    if (std::adjacent_find(levelNums.begin(), levelNums.end()) != levelNums.end()) {
        return false;
    }

    //*Check that adjacent values differ by 1-3
    if (std::adjacent_find(levelNums.begin(), levelNums.end(), isNotInRange) != levelNums.end()) {
        return false;
    }

    //* If all tests pass, the level is safe
    return true;
}

bool isNotInRange(int num1, int num2) {
    if ((abs(num1 - num2) < 1) || (abs(num1 - num2) > 3)) {
        return true;
    }
    return false;
}