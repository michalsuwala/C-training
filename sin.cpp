#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

void sin_area(double x1, double x2){
    srand(time(NULL));
    int n = 1000000, k = 0;
    for(int i = 0; i < n; i++){
        double x = x1 + (x2 - x1) * double(rand()) / RAND_MAX;
        double y = double(rand()) / RAND_MAX;
        if(y < sin(x)){
            ++k;
        }
    }
    double area = (x2 - x1) * (double)k / n;
    std::cout << area;
}

int main(){
    sin_area(.2, 3.1);
    return 0;
}