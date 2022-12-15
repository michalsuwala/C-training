/*Napisz funkcję, która w parametrze przyjmuje tablicę liczb całkowitych. 
Funkcja powinna zwrócić element o największej liczbie bitów o wartości 1, 
jeśli w tablicy jest więcej liczb o takiej samej ilości bitów, funkcja powinna zwrócić tę, 
która wystąpiła w tablicy, jako ostatnia. Zilustruj działanie tej funkcji 
i wyświetli wynik zwrócony przez funkcję.*/

#include <iostream>

int func(int arr[], int size = 6){
    int max = 0, temp = 0;
    int result;
    for(int i = 0; i < size; i++){
        temp = 0;
        for(int j = 0; j < size; j++){
            if((arr[i] >> j) & 1 == 1){
                temp++;
            }
        }
        if(temp >= max){
            max = temp;
            result = arr[i];
        }
    }
    return result;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 64};
    std::cout << func(arr);
    return 0;
}