#include <iostream>

int func(int n){
    if(n < 2){
        return 1;
    }
    else if(n >= 2 && n < 10){
        return 2 * func(n - 1);
    }
    else{
        return 3 * func(n - 1) - func(n - 3);
    }
}

int main(){
    std::cout << func(10);
    return 0;
}