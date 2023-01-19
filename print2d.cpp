#include <iostream>

void print2d(void *arr, int m, int n){
    int *array = (int*)arr;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << *(array + n * i + j) << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int m = 3, n = 2;
    int arr[m][n] = {{2,1},{5,3},{3,1}};
    print2d(arr, m, n);
    return 0;
}