//
// Created by хус on 23.03.2025.
//
#include <fstream>
#include <iostream>
#include "money.h"
#include "fileReading.h"
#include "operatorOverloading.h"

std::vector<std::string> fileReading::itemsList;

int fileReading::countStrings() {
    std::ifstream inputFile("data.txt");
    int linesCount = 0;
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            linesCount++;
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    return linesCount;
}
void fileReading::readIn(const std::string &fileName) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        int quantity; // creating variables to store data
        double price;
        std::string name;
        std::string unit;
        int i = 0;
        while (inputFile >> name >> price >> quantity >> unit) { // checking if we can succesfully read 4 things
            productsMap[name] = money::singleProduct{price, quantity}; // save them in map with a key of "name" variable
            itemsList.push_back(name);
            i++;
            std::cout << name << " " << price << " " << quantity << " " << unit << std::endl;
        }
    } else {
        std::cerr << "Unable to open file" << std::endl;
        exit(5);
    }
}


void fileReading::writeInMap(const std::string &fileName) {
    std::ofstream outputFile(fileName, std::ios::app);
    if (outputFile.is_open()) {
        outputFile << "\n" << "\n" << "↓ rounded prices ↓" << "\n" << std::endl;
        outputFile << productsMap << std::endl;

    } else {
        std::cerr << "Unable to open file" << std::endl;
        exit(10);
    }
}

using namespace money;
using namespace std;
int fileManage(int argc, char *argv[]) {
    fileReading fileReader;
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) { // checking if file is succesfully opened
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }
    fileReader.readIn("data.txt");
    wcout << fileReader.productsMap.size() << endl;

    return 1;
}
