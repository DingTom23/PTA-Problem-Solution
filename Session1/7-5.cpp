#include <iostream>

int main() {
    char ch_up;
    std::cin >> ch_up;
    char ch_low = ch_up + 32;
    int ch_low_int = (int)ch_low;
    std::cout << ch_low << ','
        << ch_low_int << std::endl;
    return 0;
}