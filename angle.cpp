#include <iostream>
#include <cmath>

int func(int y_cord[], int size, int angle){
    double m_ang = sin(angle);
    bool result = 1;
    for(int i = 1; i < size; i++){
        double sin_ang = (y_cord[i] - y_cord[i - 1]) / sqrt(pow(y_cord[i] - y_cord[i - 1], 2) + 1);
        if(sin_ang > m_ang){
            result = 0;
        }
    }
    return result;
}

int main(){
    int arr[8] = {1,1,2,3,2,6,3,2};
    std::cout << func(arr, 8, 50);
    return 0;
}