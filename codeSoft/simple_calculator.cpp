#include <iostream>
#include <limits>

int main(){
    std::cout << "---------- This is a simple calculator ----------" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Enter two numbers and an operation (e.g., a + b) with spaces..." << std::endl;

    int a, b, key;
    char op;

    start:
    std::cout << "To exit, press 1. To continue, press 0: ";
    std::cin >> key;

    if (key == 0) {
        std::cout << "Enter the operation as:\n";
        std::cout << "1. Addition as '+'\n";
        std::cout << "2. Subtraction as '-'\n";
        std::cout << "3. Multiplication as '*'\n";
        std::cout << "4. Division as '/'\n";

        std::cout << "Enter your calculation: ";
        
        if (!(std::cin >> a >> op >> b)) {
            std::cout << "Invalid input. Please enter two numbers and an operation (e.g., 5 + 3)." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto start;
        }

        if (op == '+') {
            std::cout << "Result: " << a + b << std::endl;
        } 
        else if (op == '-') {
            std::cout << "Result: " << a - b << std::endl;
        } 
        else if (op == '*') {
            std::cout << "Result: " << a * b << std::endl;
        } 
        else if (op == '/') {
            if (b != 0) {
                std::cout << "Result: " << static_cast<double>(a) / b << std::endl;
            } else {
                std::cout << "Error: Division by zero is undefined." << std::endl;
            }
        } 
        else {
            std::cout << "Invalid operation. Please enter a valid operator (+, -, *, /)." << std::endl;
        }

        goto start;
    } 
    else if (key == 1) {
        exit(0);
    }
}
