/*Napisz program, który obliczy i wyświetli długości dwuwymiarowych wektorów zapisanych 
w jednowymiarowej tablicy liczb zmiennoprzecinkowych. 
Tablica z wektorami wejściowymi ma być skonstruowana w ten sposób, 
że kolejne współrzędne (x, y) każdego wektora zajmują kolejne elementy tablicy, 
czyli:  [x1,y1, x2,y2, x3,y3, …, xn,yn]. 
Zdefiniuj funkcję arr_fun, która w parametrach przyjmie: 
(1) wskaźnik na początek tablicy wektorów, 
(2) wskaźnik na za-ostatni element tej tablicy, 
(3) wskaźnik na początek tablicy wynikowej z obliczonymi długościami oraz 
(4) wskaźnik na funkcję pomocniczą, która zwraca wartość zmiennoprzecinkową 
a w parametrach bierze dwie wartości zmiennoprzecinkowe. 
Zdefiniuj funkcję pomocniczą, która zwróci długość wektora przy podaniu przez parametry jego dwóch współrzędnych.
W funkcji głównej stwórz przykładową dynamiczną tablicę wektorów, 
wyznacz za pomocą stworzonej funkcji arr_fun ich długości i wyświetl powstałą w ten sposób tablicę wynikową. 
W zadaniu nie można używać funkcji z biblioteki <algorithm>.
Przykład:
IN:     [1.0,1.0  2.0,1.0  1.0,3.0  3.0,1.0]
OUT: [1.414214 2.236068 3.162278 3.162278]
*/

#include <iostream>
#include <cmath>

void arr_fun(float *vec, float *vecl, float *res, float (*func)(float, float)){
    int n = 0;
    for(int i = 0; vec + 2 * i != vecl; i++){
        *(res + i) = func(*(vec + 2 * i), *(vec + 2 * i + 1));
        n++;
    }
    for(int i = 0; i < n; i++){
        std::cout << *(res + i) << "\n";
    }
}

float length(float a, float b){
    return std::sqrt(a * a + b * b);
}

int main(){
    const int N = 5;
    float vec[2 * N] = {1,4,1,3,4,2,1,5,2,5};
    float leng[N];
    /*for(int i = 0; i < 2 * N; i += 2){
        printf("Wektor %d: %f\n", i, sqrt(vec[i] * vec[i] + vec[i + 1] * vec[i + 1]));
    }*/
    float *vecl = vec + 2 * N;
    arr_fun(vec, vecl, leng, length);
    return 0;
}
