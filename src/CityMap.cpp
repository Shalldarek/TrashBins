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

        for (size_t i = 0; i < row.size(); i++) {
            if (row[i] == 'E') {
                entryPoints.push_back({static_cast<int>(cityGrid.size() - 1), static_cast<int>(i)});
            } else if (row[i] == 'P') {
                binPoints.push_back({static_cast<int>(cityGrid.size() - 1), static_cast<int>(i)});
            } 
        }
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