/*Napisz program w języku C++, który wczyta od użytkownika dwie liczby całkowite n i x, 
a następnie stworzy dwie n-elementowe tablice liczb całkowitych. 
Następnie program powinien uzupełnić tablicę kolejnymi wartościami 
zaczynając od x i ustawić te wartości w losowej kolejności (wymieszać). 
Na koniec program powinien wyświetlić obie tablicę, 
sumę wartości w tablicach oraz wynik iloczynu skalarnego dwóch tak zdefiniowanych wektorów. 
Spróbuj rozwiązać zadanie wykorzystując głównie algorytmy i funkcje biblioteczne 
np. iota z pliku nagłówkowego numeric.*/

#include <iostream>
#include <numeric>
#include <algorithm>

int main(){
    int n, x;
    std::cin >> n >> x;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    std::iota(arr1, arr1 + n, x);
    std::iota(arr2, arr2 + n, x);
    std::random_shuffle(arr1, arr1 + n);
    std::random_shuffle(arr2, arr2 + n);
    for(int i = 0; i < n; i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    for(int i = 0; i < n; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
    std::cout << std::accumulate(arr1, arr1 + n, 0) << "\n";
    std::cout << std::inner_product(arr1, arr1 + n, arr2, 0);
    delete[] arr1;
    delete[] arr2;
    return 0;
}