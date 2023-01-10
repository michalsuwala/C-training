/*Napisz funkcję, do użycia jako komparator w funkcji qsort, 
która pozwoli posortować napisy rosnąco względem ich ostatnich znaków. 
Jeżeli ostatnie znaki są jednakowe, należy porównać przedostatnie itd. */

#include <iostream>
#include <cstdlib>

int comp(const void *pa, const void *pb){
    int n1, n2;
    const char *a = (const char*)pa;
    const char *b = (const char*)pb;
    for(int i = 0; a[i] != 0; i++){
        n1 = i;
    }
    for(int i = 0; b[i] != 0; i++){
        n2 = i;
    }
    for(;n1 >= 0 && n2 >= 0; --n1, --n2){
        if(a[n1] != b[n2]){
            return a[n1] - b[n2];
        }
    }
    return 0;
}

int main(){
    char arr[5][5] = {{"bggf"}, {"tdsa"}, {"tlla"}, {"gtpq"}, {"port"}};
    std::qsort(arr, 5, sizeof(arr[0]), comp);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            std::cout << arr[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}