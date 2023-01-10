/*Napisz program, który uporządkuje alfabetycznie tablicę napisów za pomocą funkcji qsort 
oraz za pomocą funkcji std::sort.*/

#include <iostream>
#include <algorithm>
#include <cstdlib>

int comp(const void *a, const void *b){
    return *(char*)b - *(char*)a;
}

int main(){
    char arr[7] = "hytter";
    std::sort(arr, arr + 6);
    for(int i = 0; i < 6; i++){
        std::cout << arr[i] << "\n";
    }
    std::cout << "\n";
    std::qsort(arr, 6, sizeof(char), comp);
    for(int i = 0; i < 6; i++){
        std::cout << arr[i] << "\n";
    }
    return 0;
}