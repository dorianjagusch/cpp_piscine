#include <iostream>
#include <stdexcept> // For std::runtime_error

int main() {
    try {
        int numerator = 10;
        int denominator = 0;
        int result = numerator / denominator; // This will trigger an exception
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}