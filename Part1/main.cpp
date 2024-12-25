#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <vector>
#include <array>

bool isLevelValid(std::string level);

int main() {
    std::ifstream infile;

    infile.open("../testinput.txt");
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
            numSafeReports++;
        }
    }

    std::cout << "Safe reports: " << numSafeReports << std::endl;

}

bool isLevelValid(std::string level) {
    std::vector<char> levelChars = { level.c_str(), level.c_str() + level.length() };
    
    //*Check if the level is in ascending order
    if (!std::is_sorted(levelChars.begin(), levelChars.end())) {
        return false;
    }

    //*Check if the level is in descending order
    std::reverse(levelChars.begin(), levelChars.end());
    if (!std::is_sorted(levelChars.begin(), levelChars.end())) {
        return false;
    }
    std::reverse(levelChars.begin(), levelChars.end()); //Reverse back to normal

    //*Check 

    return true;
}
