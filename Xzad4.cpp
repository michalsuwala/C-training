/*Napisz program, który posortuje tablicę dowolnych liczb rzeczywistych arr1 malejąco 
oraz tablicę dowolnych liczb całkowitych arr2 rosnąco. 
Do sortowania wykorzystaj algorytm qsort z biblioteki standardowej c 
i algorytm std::stort z biblioteki standardowej c++. */

#include <iostream>
#include <algorithm>

int comp(const void *x, const void *y){
    return *(int*)y - *(int*)x;
}

int main(){
    int n = 7;
    int arr[n] = {5,7,3,2,1,6,2};
    std::sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }
    std::qsort(arr, n, sizeof(int), comp);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }
    return 0;
}