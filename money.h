//
// Created by хус on 23.03.2025.
//

#ifndef MONEY_H
#define MONEY_H
#include <cmath>
#include <iostream>
#include <string>
#include <map>


namespace money {

    struct singleProduct {
        double price;
        int quantity;
    };

    class MoneyOperations {
        public:
        static double roundPrice(double price) {
            int temp = round(price * 10);
            double rounded = temp/10.0;
            return rounded;
        }
        static double sumAll(std::map<std::string, singleProduct>& productsMap) {

            double sum = 0;
            for (const auto& [key, value] : productsMap) {
                sum += value.price * value.quantity;
            }
            return sum;
        }
    };
}
#endif //MONEY_H
