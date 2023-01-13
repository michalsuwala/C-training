/*Napisz program, który przyjmuje od użytkownika dwie liczby całkowite n i m. 
Utwórz dynamiczną tablicę dwuwymiarową liczb całkowitych nieujemnych arr2d o rozmiarze nx2m 
i wypełnij ją losowymi wartościami z przedziału <0,10). 
Następnie utwórz drugą dynamiczną tablicę dwuwymiarową liczb zmiennoprzecinkowych arr2d_2 o n wierszach. 
Korzystając z kolejnych elementów tablicy arr2d wypełnij kolejne wiersze tablicy arr2d_2 w następujący sposób: 
kolejne dwa elementy z każdego wiersza scal w liczbę zmiennoprzecinkową, 
w której mniejsza z tych dwóch liczb będzie częścią całkowitą, a większa - częścią ułamkową. 
Następnie wyświetl zawartość tablicy arr2d_2.
Przykład:
IN:
    n: 3
    m: 4
    arr2d:  [3 5 2 3 5 0 3 3]
                [0 4 1 2 0 1 9 1]
                [3 1 6 0 1 2 2 9]
OUT:
    arr2d_2:      [3.5 2.3 0.5 3.3]
                         [0.4 1.2 0.1 1.9]
                         [3.1 0.6 1.2 2.9]
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    int m, n;
    std::cin >> n >> m;
    int **arr2d = new int *[n];
    for(int i = 0; i < n; i++){
        arr2d[i] = new int [2 * m];
    } 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * m; j++){
            arr2d[i][j] = 10 * rand() / RAND_MAX;
        }
    }
    float **arr2d_2 = new float *[n];
    for(int i = 0; i < n; i++){
        arr2d_2[i] = new float [m];
    } 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr2d_2[i][j] = arr2d[i][2 * j] + float(arr2d[i][2 * j + 1]) / 10;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * m; j++){
            std::cout << arr2d[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << arr2d_2[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < n; i++){
        delete[] arr2d[i];
        delete[] arr2d_2[i];
    }
    delete[] arr2d;
    delete[] arr2d_2;
    return 0;
}