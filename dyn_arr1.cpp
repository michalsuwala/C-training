/*Napisz funkcję, która dostaje jako argumenty dwuwymiarową tablicę tablic o elementach typu int oraz jej wymiary, 
i zmienia kolejność wierszy w tablicy w taki sposób, że wiersz pierwszy ma się znaleźć na miejscu drugiego, 
wiersz drugi ma się znaleźć na miejscu trzeciego itd., 
natomiast ostatni wiersz ma się znaleźć na miejscu pierwszego (przyjmujemy, 
że elementy w wierszu są umieszczone w pamięci obok siebie).*/

#include <iostream>

void func(int **arr, int n, int m){
    int *temp1 = new int[m];
    int *temp2 = new int[m];
    int *temp3 = new int[m];
    for(int i = 0; i < m; i++){
        temp1[i] = arr[n - 1][i];
        temp2[i] = arr[0][i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            temp3[j] = arr[i][j];
            arr[i][j] = temp2[j];
            temp2[j] = temp3[j];
        }
    }
    for(int i = 0; i < m; i++){
        arr[0][i] = temp1[i];
    }
    delete[] temp1;
    delete[] temp2;
    delete[] temp3;
}

int main(){
    int n = 4, m = 5;
    int **arr = new int *[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m]; 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = i * j;
        }
    } 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    func(arr, n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
