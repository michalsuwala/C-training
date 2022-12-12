/*Napisz program, który dla tablicy liczb całkowitych przesuwa o jeden w prawo wszystkie elementy tablicy 
(tak, żeby wartość elementu o indeksie 0 znalazła się w elemencie o indeksie 1, wartość elementu o indeksie 1 
znalazła się w elemencie o indeksie 2, zaś wartość elementu o indeksie n-1 w elemencie o indeksie 0).
*/

#include <iostream>

void func(int arr[], int n){
    int l_temp = arr[n - 1];
    int temp0 = arr[0], temp1 = arr[1];
    for(int i = 1; i < n; i++){
        arr[i] = temp0;
        temp0 = temp1;
        temp1 = arr[i + 1];
    }
    arr[0] = l_temp;
}

int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    func(arr, n);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << "\t";
    }
    return 0;
}