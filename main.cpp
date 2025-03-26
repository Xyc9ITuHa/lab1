#include <fstream>
#include <iomanip>
#include <iostream>

#include "fileReading.h"
#include "mapOperations.h"
#include "money.h"
#include "operatorOverloading.h"


using namespace std;
using namespace money;



using namespace std;
using namespace money;

int main() {
    // cout global tweaks
    cout.setf(ios::fixed); //making dot fixed in position
    cout.precision(2); // making uotput to always show 2 nums after , in combination with previous one
    setlocale(LC_ALL, "en_US.UTF-8");

    //objects to use methods
    mapOperations mapRedactor;
    fileReading fileReader;

    //variables
    map<string, singleProduct> roundedMap = fileReader.productsMap;
    double price;
    int size = fileReading::itemsList.size();\


    fileReader.readIn("data.txt"); //reading and writing data to map<>

    mapRedactor.mapRounding(roundedMap);

    cout << "\nyour total items:\n" << endl;
    cout << fileReading::itemsList << "\n\n" << endl;


    for (int i = 0; i < size; i++) {
        price = fileReader.productsMap[fileReading::itemsList[i]].price;
        fileReader.productsMap[fileReading::itemsList[i]].price = MoneyOperations::roundPrice(price);
    }

    cout << "Rounded items:\n" << fileReader.productsMap << endl; //outputtig rounded map
    fileReader.writeInMap("data.txt"); //writing in rounded map
    double sum = money::MoneyOperations::sumAll(fileReader.productsMap);//summing all prices * quantity
    cout <<  "\tsum:\t" << sum << endl; // outputting sum

    ofstream outputFile("data.txt", ios::app); //outputting sum in file (to much to do if using methods just for sum)
    if (outputFile.is_open()) {
        outputFile << "\tsum:\t" << sum << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
    outputFile.close();

    return 0;
}