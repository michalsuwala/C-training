/*Wykorzystując wskaźniki na funkcje napisz program w języku C++, 
który w zależności od wywołania funkcji f znajdzie w tablicy 
liczb całkowitych wartość minimalną lub maksymalną.*/

#include <iostream>

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int func(int arr[], int size, int (*f)(int, int)){
    int res = arr[0];
    for(int i = 1; i < size; i++){
        res = f(arr[i], res);
    }
    return res;
}

int main(){
    int size = 6;
    int arr[size] = {3,5,6,4,2,6};
    std::cout << func(arr, size, max);
    return 0;
}