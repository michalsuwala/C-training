/*Zdefiniuj strukturę Rect, reprezentującą prostokąt. Struktura ta ma składać się z dwóch elementów - długości boków a i b.
Stwórz funkcję print_rect(..), która wyświetla na ekranie długości boków podanego w parametrze prostokąta. 
Stwórz funkcję area(...), która zwróci wielkość pola podanego w parametrze prostokąta.
W programie stwórz obiekt automatyczny i dynamiczny typu Rect i przetestuj działanie zdefiniowanych funkcji.*/

#include <iostream>

struct Rect{
    int a, b;
};

void print_rect(const Rect& r){
    std::cout << r.a << "\n";
    std::cout << r.b << "\n";
}

int area(const Rect& r){
    return r.a * r.b;
}

int main(){
    Rect rectangle;
    rectangle.a = 7;
    rectangle.b = 7;
    print_rect(rectangle);
    std::cout << area(rectangle);
    return 0;
}