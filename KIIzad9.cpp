#include <iostream>

int det(int *arr){
    int res = arr[3] * arr[0] - arr[2] * arr[1];
    if(res < 0){
        return -1;
    }
    return 0;
}
int func(int **arr, int **arr_l, int (*f)(int *)){
    for(int i = 0; arr + i != arr_l; i++){
        if(f(arr[i]) < 0){
            return i;
        }
    }
    return -1;
}

int main(){
    int n = 3;
    int **arr = new int *[n];
    for(int i = 0;  i < n; i++){
        arr[i] = new int[4]{1,1,0,1};
    }
    std::cout << func(arr, arr + n * 4, det);
    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}