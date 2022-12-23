/*Napisz funkcję mul(), która mnoży dwie macierze reprezentowane przez dynamicznie alokowane tablice dwuwymiarowe 
oraz funkcję print_matrix(), która wyświetla tak zdefiniowaną macierz. */

#include <iostream>

void mul(int **arr1, int **arr2, int n, int m, int o, int p){
    if(m != o){
        return; 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            int temp = 0;
            for(int k = 0, l = 0; k < o, l < m; k++, l++){
                temp += arr1[i][l] * arr2[k][j];
            }
            
            std::cout << temp << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int n = 4, m = 5, o = 5, p = 7;
    int **arr1 = new int *[n];
    for(int i = 0; i < n; i++){
        arr1[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr1[i][j] = 2;
        }
    }
    int **arr2 = new int *[o];
    for(int i = 0; i < o; i++){
        arr2[i] = new int[p]; 
    }
    for(int i = 0; i < o; i++){
        for(int j = 0; j < p; j++){
            arr2[i][j] = 2;
        }
    }
    mul(arr1, arr2, n, m, o, p);
    for(int i = 0; i < n; i++){
        delete[] arr1[i];
    }
    delete[] arr1;
    for(int i = 0; i < o; i++){
        delete[] arr2[i];
    }
    delete[] arr2;
    return 0;
}
