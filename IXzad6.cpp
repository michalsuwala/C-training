#include <iostream>

int **func(int arr0[], int arr1[], int size0, int size1){
    int **res = new int *[size0];
    for(int i = 0; i < size0; i++){
        res[i] = new int[size1];
    }   
    for(int i = 0; i < size0; i++){
        for(int j = 0; j < size1; j++){
            res[i][j] = arr0[i] * arr1[j];
        }
    }
    return res;
}

int main(){
    int a[3] = {1,2,3}, b[3] = {1,2,3};
    int n0 = 3, n1 = 3;
    int **res = func(a,b,n0,n1);
    for(int i = 0; i < n0; i++){
        for(int j = 0; j < n1; j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < n0; i++){
        delete[] res[i];
    }
    delete[] res;
    return 0;
}