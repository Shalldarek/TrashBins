#pragma once

#include <vector>
#include <string>
#include "Point.h"

class CityMap {
    public:
        std::vector<std::vector<char>> cityGrid;
        std::vector<Point> entryPoints;
        std::vector<Point> binPoints;

        bool loadMap(const std::string& fileName);
        void printMap();
};
