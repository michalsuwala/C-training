/*Napisz funkcję matRows(), która przyjmuje jako argumenty: 
jednowymiarową tablicę automatyczną liczb całkowitych mat, liczby całkowite n, m. 
Tablicę mat należy zinterpretować jako tablicę dwuwymiarową o n wierszach i m kolumnach, 
w której kolejne komórki ustawione są wierszami. Funkcja powinna zwrócić liczbę wierszy, 
w których liczby posortowane są rosnąco.
PRZYKŁAD:
IN n = 2, m = 3
IN mat = [1, 6, 3, 5, 6, 7]
OUT: 1
bo: mat = | 1 6 3 | (nieposortowane)
                  | 5 6 7 | (posortowane)
*/

#include <iostream>

int matRows(int mat[], int n, int m){
    int result = 0;
    for(int i = 0; i < n; i++){
        bool sort = 1;
        for(int j = 0; j < m - 1; j++){
            if(mat[i * m + j] > mat[i * m + j + 1]){
                sort = 0;
            }
        }
        if(sort){
            result++;
        }
    }
    return result;
}

int main(){
    int n = 2, m = 3;
    int mat[n * m] = {1, 6, 3, 5, 6, 7};
    std::cout << matRows(mat, n , m) << "\n";
    char str[4];
    std::cout << (int)str[1] << "\t" << (int)str[2]; 
    return 0;
}