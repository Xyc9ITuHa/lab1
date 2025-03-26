//
// Created by хус on 25.03.2025.
//

#ifndef MAPOPERATIONS_H
#define MAPOPERATIONS_H
#include <map>
#include <string>

#include "fileReading.h"
#include "money.h"


class mapOperations {
    public:
    void mapRounding(std::map<std::string, money::singleProduct>& productsMap) {};
    void mapSumming(std::map<std::string, money::singleProduct>& productsMap) {};
};



#endif //MAPOPERATIONS_H
