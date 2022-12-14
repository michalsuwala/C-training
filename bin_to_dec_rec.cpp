/*Napisz funkcję rekurencyjną, która zamienia liczbę binarną, reprezentowaną za pomocą napisu, na liczbę całkowitą. 
Zademonstruj jej użycie.
PRZYKŁAD:
IN: "10010011"
OUT: 147
*/

#include <iostream>
#include <cmath>


int func(char str[], int size, int i = 0, int result = 0){
    if(str[i] != 0){
        result += (str[i] - 48) * pow(10, size - 2);
        return func(str, size - 1, i + 1, result);
    }
    else{
        return result;
    }
}

int main(){
    char str[] = "10010011";
    int size = 9;
    std::cout << func(str, size);
    return 0;
}