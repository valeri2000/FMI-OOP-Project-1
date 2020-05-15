#include <iostream>
#include <iomanip>

int main() {
    double a = 5.123432;
    std::cout << std::fixed << std::setprecision(3) << a << '\n';
    a = 1.1;
    std::cout << std::fixed << std::setprecision(3) << a << '\n';

    return 0;
}
