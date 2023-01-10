/*Napisz właną funkcję, która otrzymuje w argumentach dwa napisy i zwraca informacje o tym, 
który z nich jest wcześniejszy w porządku alfabetycznym (==0, <0, >0).*/

#include <iostream>

int func(char str0[], char str1[]){
    for(int i = 0; str0[i] != 0 && str1[i] != 0; i++){
        if(str0[i] < str1[i]){
            return 1;
        }
        else if(str0[i] > str1[i]){
            return -1;
        }
    }
    return 0;
}

int main(){
    char a[] = "hytta", b[] = "hester";
    std::cout << func(a, b);
    return 0;
}