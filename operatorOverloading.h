//
// Created by хус on 26.03.2025.
//

#ifndef OPERATOROVERLOADING_H
#define OPERATOROVERLOADING_H
#include <map>
#include <ostream>
#include <vector>

#include "money.h"

inline std::ostream &operator<<(std::ostream &os, const money::singleProduct &p) {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << "|" << p.price << " | " << p.quantity << " | " << std::endl;
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &vec) {
    for (const auto &str: vec) {
        os << str << " ";
    }
    return os;
}

inline std::ostream &operator<<(std::ostream &os, const std::map<std::string, money::singleProduct> &map) {
    for (const auto &[key, value]: map) {

        os << key << " | " << value << std::endl; // WHY NOT WORKING
        // IM BREAKING MY HEAD OVER IT
        // FOR IT JUST NOT TO WORK
        // GOD DAMMIT
        // nvm I'm just stupid. It was working I didn't call for it
    }
    return os;
}

inline std::ofstream &operator<<(std::ofstream &of, const std::map<std::string, money::singleProduct> &map) {
    for (const auto &[key, value]: map) {
        of << key << " " << value << std::endl; // there is mistake with third <<   | solvation -
    }
    return of;
}

#endif //OPERATOROVERLOADING_H
