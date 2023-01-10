/*Napisz funkcję, która dostaje jako argument wskaźnik do tablicy typu int oraz rozmiar tablicy 
i odwraca kolejność elementów w tablicy. Nie korzystaj z dostępu do elementów tablicy operatorem [ ].*/

#include <iostream>

void func(int *arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j <  size - 1 - i; j++){
            int temp = *(arr + j + 1);
            *(arr + j + 1) = *(arr + j);
            *(arr + j) = temp;
        }
    }
}

int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    int *ptr = arr;
    func(ptr, size);
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}