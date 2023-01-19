/*Napisz program, który uporządkuje alfabetycznie tablicę napisów za pomocą funkcji qsort 
oraz za pomocą funkcji std::sort.*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

/*int comp(const void *a, const void *b){
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
}*/
bool comps(const void* a, const void* b){
    char *x = (char*)a;
    char *y = (char*)b;
    return std::strcmp(y, x) > 0;
}

int comp(const void *a, const void *b){
    const char *x = *(const char**)a;
    const char *y = *(const char**)b;
    std::cout << std::strcmp(x, y) << " ";
    return std::strcmp(y, x) < 0;
}

int main(){
    int n = 3;
    char **arr = new char *[n];
    for(int i = 0, k = 7; i < n; i++, k--){
        arr[i] = new char[6];
    }
    arr[0] = (char*)"abdss";
    arr[1] = (char*)"zaaas";
    arr[2] = (char*)"deeff";
    std::qsort(arr, n, sizeof(char*), comp);
    //std::sort(arr, arr + n, comps);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            std::cout << arr[i][j];
        }
        std::cout << "\n";
    }
    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}