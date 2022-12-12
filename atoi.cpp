/*Napisz program, który zamieni reprezentację znakową liczby całkowitej bez znaku (string) 
na zmienną typu liczby całkowitej - ekwiwalent funkcji bibliotecznej atoi().
Przykład:
    char str[] = {'2', '6', '7', '\0'} => int k = 267
*/

#include <iostream>
#include <cmath>

int func(char str[]){
    int n = 0, result = 0;
    for(int i = 1; str[i] != '\0'; i++){
        n++;
    }
    for(int i = 0; str[i] != '\0'; i++){
        result += (int(str[i]) - 48) * pow(10, n);
        n--;
    }
    return result;
}

int main(){
    char str[6] = {'1','2','3','4','5','\0'};
    std::cout << func(str);
    return 0;
}