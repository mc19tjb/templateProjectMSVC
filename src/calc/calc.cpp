#include "calc.h"

#include <stdexcept>

double Add(double a, double b){
    return a + b;
};
double Subtract(double a, double b){
    return a - b;
};
double Multiply(double a, double b){
    return a * b;
};
double Divide(double a, double b){
    if(b == 0){
      throw std::invalid_argument("Cannot Divide By Zero");
        //return 0;  // Hacky way of handling divide by 0.
    } else{
    return a / b;
    }
};