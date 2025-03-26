//
// Created by хус on 25.03.2025.
//

#include "mapOperations.h"
#include "fileReading.h"
#include "money.h"

void mapRounding(std::map<std::string, money::singleProduct>& productsMap, const std::vector<std::string>& itemList) {

    unsigned long long size = itemList.size(); // lets just ignore that holy shit amount of memory used
    double price;

    for (int i = 0; i < size; i++) {
        double roundingProcessor = productsMap[itemList[i]].price;
        std::cout << "Before: " << roundingProcessor << std::endl;
        price = productsMap[itemList[i]].price;
        productsMap[itemList[i]].price = std::round(price * 10) / 10;
        std::cout << "After: " << productsMap[itemList[i]].price << std::endl;
    }

}

