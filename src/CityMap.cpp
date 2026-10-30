#include <fstream>
#include <iostream>
#include "include/CityMap.h"

bool CityMap::loadMap(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "[ERROR]: Could not open file " << fileName << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row(line.begin(), line.end());
        cityGrid.push_back(row);
    }

    file.close();
    return true;
}

void CityMap::printMap() {
    for (const auto& row : cityGrid) {
        for (const auto& cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}