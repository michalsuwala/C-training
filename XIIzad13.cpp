/*Zdefiniuj typ wyliczeniowy składający się z wartości odzwierciedlających typy: CHAR, UCHAR, INT, FLOAT. 
Napisz funkcję, która przyjmie jako argumenty wskaźnik na void, pod którym znajduje się tablica, 
rozmiar tej tablicy oraz zmienną uprzednio zdefiniowanego typu wyliczeniowego oznaczającą typ danych 
znajdujących się w tablicy. Funkcja powinna zwrócić średnią arytmetyczną danych w przekazanej tablicy.*/

#include <iostream>

enum Types{CHAR=1, UCHAR=2, INT=3, FLOAT=4};

float func(void *ptr, int n, Types type){
    float sum = 0;
    if(type == 1){
        char *arr = (char*)ptr;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
    }
    else if(type == 2){
        unsigned char *arr = (unsigned char*)ptr;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
    }
    else if(type == 3){
        int *arr = (int*)ptr;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
    }
    else if(type == 4){
        float *arr = (float*)ptr;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
    }
    return float(sum / n);
}

int main(){
    int n = 4;
    int arr[n] = {1,2,3,4};
    std::cout << func((void*)arr, n, Types(3));
    return 0;
}