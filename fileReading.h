//
// Created by хус on 23.03.2025.
//

#ifndef FILEREADING_H
#define FILEREADING_H
#include <map>
#include <vector>
#include "money.h"


class fileReading {
    public:
    std::map<std::string, money::singleProduct> productsMap;
    static std::vector<std::string> itemsList;
    int countStrings();
    void readIn(const std::string& fileName);
    void writeInMap(const std::string& fileName);
    private:
    std::string line;
};



#endif //FILEREADING_H
