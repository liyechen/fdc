//
// Created by Yechen Li on 2020/10/15.
//

#ifndef FDC_UTIL_H
#define FDC_UTIL_H

#include <iostream>

std::string addZeroToFront(std::string str, uint len) {
    if (str.size() >= len) {
        return str;
    }
    str = std::string( len - str.size(), '0').append(str);
    return str;
}

#endif //FDC_UTIL_H
