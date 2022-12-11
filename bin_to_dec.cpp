#include <iostream>
#include <cmath>

int func(int bin[], int size){
    int result = 0;
    for(int i = size - 1, j = 0; j < size; i--, j++){
        result += bin[i] * pow(2, j);
    }
    return result;
}

int main(){
    int size = 7;
    int bin[size] = {1,0,0,0,0,1,1};
    std::cout << func(bin, size);
    return 0;
}