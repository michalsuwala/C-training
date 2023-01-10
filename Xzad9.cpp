/*Zaprojektuj funkcję, która zwróci indeks szukanej wartości w posortowanej tablicy liczb całkowitych. 
Funkcja powinna zwrócić -1, jeśli nie uda się znaleźć takiej wartości w tablicy. 
Rozwiązanie powinno być rozwiązaniem optymalnym. Napisz program, który przetestuje działanie tej funkcji. */

#include <iostream>
#include <cstdlib>

int func0(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
        }
        if(arr[i] > key){
            return -1;
        }
    }
    return -1;
}
int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int func1(int *arr, int *key, int (*func)(const void*, const void*), int count){
    return int((int*)std::bsearch(key, arr, count, sizeof(int), func) - arr);
}

int main(){
    int n = 5;
    int arr[5] = {1,3,4,5,8};
    int a = 5;
    int *key = &a;
    std::cout << func0(arr, n, a) << "\n";
    std::cout << func1(arr, key, comp, n);
    return 0;
}