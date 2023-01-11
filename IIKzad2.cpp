/*Napisz program w języku C++, który stworzy dynamiczną tablicę dwuwymiarową trójkątną arr o rozmiarze NxN 
wybranego typu liczbowego i wypełni ją dowolnymi wartościami. 
Zdefiniuj funkcję, która w parametrze przyjmie wskaźnik na wskaźnik na typ void (do tablicy trójkątnej arr), 
rozmiar N, wielkość w bajtach pojedynczego elementu sizen tablicy przekazanej w pierwszym parametrze 
oraz dwie współrzędne x, y typu całkowitego. 
Funkcja ma zwrócić wskaźnik typu void ustawiony na podany we współrzędnych x, y element tablicy lub nullptr 
jeżeli nie ma takiego elementu. Pokaż użycie tej funkcji i wykonaj dealokację tablicy arr.
Przykład:
0  1  2  3  4
5  6  7  8
8  9 10
11 12
13
OUT: 7 (dla x=2, y=1)
*/

#include <iostream>

void *func(void **arr, int N, int x, int y, int sizen = sizeof(int)){
    if(N - x < y + 1){
        return nullptr;
    }
    return &((int**)arr)[x][y];
}

int main(){
    const int N = 5;
    int **arr = new int *[N];
    for(int i = 0, j = N; i < N; i++, j--){
        arr[i] = new int [j];
    }
    for(int i = 0, j = N; i < N; i++, j--){
        for(int k = 0; k < j; k++){
            arr[i][k] = i;
        }
    }
    void* res = func((void**)arr, N, 2, 2);
    std::cout << *(int*)res;
    for(int i = 0; i < N; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}