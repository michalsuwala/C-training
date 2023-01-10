/*Napisz program, który wykona kopię wczytanego z klawiatury napisu, w ten sposób, 
że do napisu docelowego (o tej samej wielkości co napis źródłowy) zostaną zapisane tylko małe litery, 
reszta zostanie zignorowana. W miejscu pozostałych, niewykorzystanych znaków wstaw symbol '-' (minus). 
Program napisz bez używania pętli. (podpowiedź: std::copy_if(), std::fill()).
Przykład:
WE: aBcDeFg
WY: aceg---*/

#include <iostream>
#include <algorithm>

int main(){
    char orig[100];
    char dest[100];
    std::cin >> orig;
    int i = 0;
    while(orig[i] != 0){
        ++i;
    }
    std::copy_if(orig, orig + i, dest, [](int x){return (x > 96 && x < 123);});
    int big = std::count_if(orig, orig + i, [](int x){return (x > 96 && x < 123);});
    std::fill(dest + big, dest + i, '-');
    for(int j = 0; dest[j] != 0; j++){
        std::cout << dest[j];
    }
    return 0;
}