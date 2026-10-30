#include <iostream>
#include "include/CityMap.h"

int main() {
    CityMap cityMap;
    if (!cityMap.loadMap("test-data/SampleCityMap.txt")) {
        return 1;
    }

    cityMap.printMap();
    
    return 0;
}