#include <iostream>
#include <cmath>

int func(int arr[], int size){
    int comp = 0;
    int num;

    for(int i = 0; i < size; i++){
        int k = 1;
        int sum = 0;

        for(int j = 0, n = arr[i]; n >= 1;j++){ 
            int zer = k & n;
            if(zer){
                sum++;
            }
            n = n >> 1;
        }
        if(sum >= comp){
            comp = sum;
            num = arr[i];
        }
    }
    return num;
}

int main(){
    int size = 6;
    int arr[size] = {1, 2, 7, 4, 14, 64};
    std::cout << func(arr, size);
    return 0;
}