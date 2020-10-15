//
// Created by Yechen Li on 2020/10/15.
//

#ifndef FDC_FDC_H
#define FDC_FDC_H

#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>

#include "util.h"

namespace fs = std::filesystem;
using namespace std::chrono_literals;

void splitFilesAccordingToDate(const std::string& p);
std::string dirnameFromFileTimeType(const std::tm* time);

std::string dirnameFromFileTimeType(const std::tm* t) {
    std::string dirname;
    int month = t->tm_mon + 1;
    int year = t->tm_year + 1900;
    int day = t->tm_mday;

    dirname += std::to_string(year) + "-" + addZeroToFront(std::to_string(month), 2) + "-" + addZeroToFront(std::to_string(day), 2);

    return dirname;
}

void splitFilesAccordingToDate(const std::string& p) {
    fs::path path(p);
    fs::directory_entry cur(path);

    for (const auto& file : fs::directory_iterator(cur)) {
        if (fs::is_directory(file)) {
            continue;
        }

        std::cout << file.path() << std::endl;

        auto mdTime = file.last_write_time();
        auto cfTime = decltype(mdTime)::clock::to_time_t(mdTime);
        std::string dirname = dirnameFromFileTimeType(std::localtime(&cfTime));

        if (!fs::is_directory(dirname)) {
            fs::create_directory(path/dirname);
        }
        fs::path dir = path/dirname;
        fs::rename(file.path(), dir/file.path().filename());
    }

};

#endif //FDC_FDC_H
