#include "numstat.h"

std::vector<double> read_numbers(std::istream& in) {
    std::vector<double> result{};

    double val{};
    while (in >> val) {
        result.push_back(val);
    }

    return result;
}