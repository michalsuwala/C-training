/*Napisz program, który wyświetli wszystkie elementy tablicy za pomocą funkcji std::for_each*/

#include <iostream>
#include <algorithm>

void print(int i){
    std::cout << i << "\n";
}

int main(){
    int arr[5] = {1,2,3,4,5};
    std::for_each(arr, arr + 5, print);
    return 0;
}