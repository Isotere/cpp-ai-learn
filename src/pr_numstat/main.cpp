#include <iostream>

#include "numstat.h"

int main() {
    std::cout << "Hello from pr_numstat\n";

    auto nums = read_numbers(std::cin);

    if (std::cin.eof()) {
        std::cout << "Ввод завершен по EOF\n";
    } else if (std::cin.fail()) {
        std::cerr << "Ввод остановлен: встретилось нечисловое значение\n";
    } else if (std::cin.bad()) {
        std::cerr << "Ошибка потока ввода\n";
    }

    std::cout << "Прочитано: ";
    for (double x : nums) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
