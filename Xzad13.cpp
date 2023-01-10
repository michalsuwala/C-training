/*Zaprojektuj funkcję w języku C++, która zwróci indeks szukanej wartości w posortowanej tablicy liczb całkowitych. 
Funkcja powinna zwrócić -1, jeśli nie uda się znaleźć takiej wartości w tablicy. 
Rozwiązanie powinno wykorzystywać algorytm Binary Search. 
Napisz program w języku C++, który przetestuje działanie tej funkcji.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int func(int arr[], int size, int key){
    int* index = (int*)std::bsearch(&key, arr, size, sizeof(int), comp);
    if(index){
        return index - arr;
    }
    else{
        return -1;
    }
}

int main(){
    srand(time(NULL));
    int size = 13;
    int arr[size];
    int key = 7;
    for(int i = 0; i < size; i++){
        arr[i] = 1 + rand()/(RAND_MAX/15);
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::qsort(arr, size, sizeof(int), comp);
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << func(arr, size, key);
    return 0;
}