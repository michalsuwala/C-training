/*Radar morski na statku to prawdopodobnie najczęściej używany sprzęt elektroniczny podczas nawigacji. 
To doskonałe narzędzie do wykrywania obiektów wokół nas. Niestety jesteśmy tak bardzo uzależnieni od radaru, 
że czasami używamy go częściej niż własnych oczu do obserwacji wokół. 
Jednakże inna sytuacja miała miejsce, gdy pewien marynarz odczytywał dane z notatek pozostawionych na pokładzie swojego statku. 
W notatkach kapitan pokładu zapisał położenia N obiektów na morzu za pomocą współrzędnych biegunowych w następujący sposób:
    R1 F1 R2 F2 ... Rn Fn
gdzie R to promień wodzący obiektu (odległość), zaś F to amplituda punktu (wartość kąt skierowanego w radianach).
Zaimplementuj funkcję, która posortuje dane przedstawione w notatce tak, 
aby obiekty były w kolejności od najmniej do najbardziej odległego od statku naszego bohatera, który znajduje się w punkcie (0, 0). 
W sytuacji, gdy oba obiekty są tak samo odległe należy wybrać ten o większej amplitudzie.
Napisz program, który przetestuje działanie tej funkcji 
i wyświetli współrzędne w układzie kartezjańskim tych obiektów w odpowiedniej kolejności.
Konwersja ze współrzędnych biegunowych do kartezjańskich:
   x = R * cos(F)
   y = R * sin(F)
Przykład:
IN:   [1.2 6.1 1.2 1.1 5.4 3.1]
OUT:
    1.179 -0.219
    0.544  1.069
   -5.395  0.225*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

int comp(const void *a, const void *b){
    double x1 = ((const double*)a)[0];
    double y1 = ((const double*)a)[1];
    double x2 = ((const double*)b)[0];
    double y2 = ((const double*)b)[1];
    return -((x2 * x2 + y2 * y2) - (x1 * x1 + y1 * y1));
}

void func(double array[], int n){
    double coord[n][2];
    for(int i = 0; i < n; i++){
        coord[i][0] = array[2 * i] * cos(array[2 * i + 1]);
        coord[i][1] = array[2 * i] * sin(array[2 * i + 1]);
    }
    std::qsort(coord, n, 2 * sizeof(double), comp);
    //std::reverse(coord, coord + n);
    for(int i = 0; i < n; i++){
        std::cout << coord[i][0] << " " << coord[i][1] << "\n";
    }
}

int main(){
    int n = 4;
    double arr[] = {5.8, 7.4, 1.2, 6.1, 1.2, 1.1, 5.4, 3.1};
    func(arr, n);
    return 0;

}