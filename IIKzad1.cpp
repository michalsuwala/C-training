/*Dane są dwie tablice liczb zmiennoprzecinkowych o długościach: (1) 3*N oraz (2) N, gdzie N jest liczbą naturalną. 
Zdefiniuj funkcję fun_arr, która w parametrze przyjmie dwie tablice (o podanej wyżej specyfikacji) 
oraz wskaźnik na pewną dodatkową funkcję fun_aux. 
Funkcja fun_arr z każdych trzech sąsiadujących elementów (o indeksach {3i, 3i+1, 3i+2}) 
z pierwszej tablicy ma obliczyć, za pomocą fun_aux, pojedynczą wartość i wstawić ją do drugiej tablicy w element o indeksie i. 
Funkcja pomocnicza fun_aux, dla trzech podanych liczb, ma zwracać wartość największą.
W funkcji głównej stwórz przykładowe dynamiczne tablice (1) i (2) spełniające warunki z początku zadania 
i wykorzystując funkcje fun_arr i fun_aux, uzupełnij tablicę wyjściową (2). Wypisz na ekranie jej wartości. 
Zadbaj o właściwe zarządzanie pamięcią dynamiczną.
Przykład:
IN:     [1.0,1.0,2.5,   2.0,1.0,-0.5,   -1.5,-3.0,-4.0,   0.0,0.0,0.0,0.0]
OUT: [2.5            2.0             -1.5              0.0]*/

#include <iostream>

void fun_arr(float arr0[], float arr1[], float (*fun_aux)(float, float, float), int N){
    for(int i = 0, j = 0; i < 3 * N; i += 3, j++){
        arr1[j] = fun_aux(arr0[i], arr0[i + 1], arr0[i + 2]);
    }
}

float fun_aux(float a, float b, float c){
    if(a >= b && a >= c){
        return a;
    }
    if(b >= a && b >= c){
        return b;
    }
    return c;
}

int main(){
    const int N = 3;
    float *arr0 = new float[3 * N];
    float *arr1 = new float[N];
    for(int i = 0; i < 3 * N; i++){
        arr0[i] = i;
    }
    fun_arr(arr0, arr1, fun_aux, N);
    for(int i = 0; i < N; i++){
        std::cout << arr1[i] << " ";
    }
    delete[] arr0;
    delete[] arr1;
    return 0;
}