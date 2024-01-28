#include <iostream>
#include <limits>

int main() {
    std::cout << "Kích thước của long: " << sizeof(long) << " byte" << std::endl;
    std::cout << "Giới hạn tối đa của long: " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "Giới hạn tối thiểu của long: " << std::numeric_limits<long>::min() << std::endl;

    return 0;
}