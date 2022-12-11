#include <iostream>
#include <cmath>

void func(int &num){
    int temp = 0;
    for(int i = 0; num >= 1; i++){
        temp += (num % 2) * pow(10, i);
        num /= 2;
    }
    num = temp;
}

int main(){
    int num = 67;
    func(num);
    std::cout << num;
    return 0;
}