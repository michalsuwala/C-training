#include <iostream>

void cosh(double x){
    double result = 1, step = 1, factorial = 1;
    for(int i = 1; i < 6; i++){
        step *= x * x;
        factorial *= 2 * i * (2 * i - 1);
        result += step / factorial;
    }
    std::cout << result;
}

int main(){
    double x;
    std::cin >> x;
    cosh(x);
    return 0;
}