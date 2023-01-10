/*Wykorzystując wskaźniki na funkcje napisz program, który w zależności od wywołania funkcji mat_operation() 
wykona dodawanie lub odejmowanie dwóch macierzy kwadratowych. 
Wynik operacji na macierzach powinien być zapisany do pierwszej macierzy. 
Jaką zaproponujesz sygnaturę dla tej funkcji i jakie funkcje pomocnicze?
Operacje na tablicach powinny być przeprowadzone za pomocą arytmetyki wskaźników.*/

#include <iostream>

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

void mat_operation(int **mat0, int **mat1, int row, int col, int (*func)(int, int)){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            mat0[i][j] = func(mat0[i][j], mat1[i][j]);
        }
    }    
}

int main(){
    int row = 4, col = 5;
    int **a = new int *[row];
    int **b = new int *[row];
    for(int i = 0; i < row; i++){
        a[i] = new int[col];
        b[i] = new int[col];
        for(int j = 0; j < col; j++){
            a[i][j] = i * j;
            b[i][j] = i * j;
        }
    }
    mat_operation(a, b, row, col, sub);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < row; i++){
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;
    return 0;
}