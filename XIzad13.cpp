/*Napisz funkcję w języku C++, która znajduje element pojawiający się w tablicy tylko raz, gdy inne elementy pojawiają się dwukrotnie. 
Funkcja w argumencie powinna przyjąć wskaźnik na tablicę liczb całkowitych oraz rozmiar tej tablicy. 
Napisz program w języku C++, który przetestuje działanie tej funkcji.*/

#include <iostream>

int func(int *arr, int n){
    int result = arr[0];
    for(int i = 1; i < n; i++) 
        result ^= arr[i];
    return result;
}
/*int func(int *arr, int n){
    bool f;
    for(int i = 0; i < n; i++){
        f = 1;
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            if(arr[i] == arr[j]){
                f = 0;
                break;
            }
        }
        if(f){
                return i;
            }
    }
    return -1;
}*/

int main(){
    int arr[9] = {1,2,1,2,4,3,5,4,5};
    std::cout << func(arr, 9);
    return 0;
}