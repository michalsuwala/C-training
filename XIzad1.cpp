/*Napisz funkcję, która przyjmuje w argumentach: wskaźnik arr na tablicę liczb całkowitych, 
rozmiar tej tablicy n, liczbę całkowitą k oraz wskaźnik na tablicę liczb całkowitych result. 
Funkcja powinna wprowadzić do tablicy result k największych elementów z tablicy arr przekazanej w argumencie. 
Funkcja nie powinna modyfikować oryginalnej tablicy.*/

#include <iostream>
#include <cstdlib>

int comp(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

void func(int arr[], int n, int k, int res[]){
    int *temp = new int [n];
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }
    std::qsort(temp, n, sizeof(int), comp);
    for(int i = 0; i < k; i++){
        res[i] = temp[i];
    }
    delete[] temp;
}

int main(){
    int n = 7, k = 3;
    int arr[n] = {1,5,2,8,2,4,4}, res[k];
    func(arr, n, k, res);
    for(int i = 0; i < k; i++){
        std::cout << res[i] << " ";
    }
    return 0;
}