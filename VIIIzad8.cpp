/*Napisz funkcję print2d(), która wyświetli wartości automatycznej tablicy dwuwymiarowej, 
bez względu na wielkość tej tablicy. W programie głównym stwórz przykładowe dwuwymiarowe tablice 
i wyświetl ich wartości za pomocą funkcji print2d().*/

#include <iostream>

void print2d(int **arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int rows = 5, cols = 5;
    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++){
        arr[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = 1;
        }
    }
    print2d(arr, cols, rows);
    for(int i = 0; i < cols; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}