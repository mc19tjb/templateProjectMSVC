#include "calc.h"

#include <iostream>

int main(void){
    std::cout << "3 + 4 is : " << Add(3, 4) << std::endl;
    std::cout << "3 - 4 is : " << Subtract(3, 4) << std::endl;
    std::cout << "3 * 4 is : " << Multiply(3, 4) << std::endl;
    std::cout << "3 / 4 is : " << Divide(3, 4) << std::endl;
    try{
    std::cout << "Trying divide by zero " << Divide(3, 0.0) << std::endl;
    }
    catch(std::invalid_argument& exception){
        std::cout << "Invalid Argument Exception: " << exception.what() << std::endl;
    };
    return 0;
}