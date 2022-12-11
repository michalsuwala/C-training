#include <iostream>

int main(){
    int n = 10;
    for(int i = 0; i < 2 * n; i++){
        std::cout << "_";
    }
    std::cout << "\n";
    for(int i = 0; i < n; i++){
        int j = 2 * n - 2 - 2 * i;
        for(int k = 0; k < i; k++){
            std::cout << " ";
        }
        std::cout << "\\";
        for(; j > 0; j--){
            std::cout << " ";
        }
        std::cout << "/" << "\n";
    }
    return 0;

}