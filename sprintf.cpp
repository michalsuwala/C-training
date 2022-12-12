/*Napisz program, który liczbę całkowitą (bez znaku) na jej reprezentację znakową (string) 
- ekwiwalent funkcji bibliotecznej sprintf().
Przykład:
    int k = 267 => char str[] = {'2', '6', '7', '\0'};
*/

#include <iostream>

void func(int k, char str[]){
    int n = 0, k2 = k;
    for(;k2 >= 1;){
        k2 /= 10;
        n++;
    }
    str[n] = '\0';
    for(int i = n - 1; i >= 0; i--){
        str[i] = (k % 10) + 48;
        k /= 10;
    }
    
}

int main(){
    char str[100];
    int k = 14533;
    func(k, str);
    for(int i = 0; str[i] != '\0'; i++){
        std::cout << str[i] << "\t";
    }
    return 0;
}