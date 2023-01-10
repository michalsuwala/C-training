/*Napisz program, który wczyta od użytkownika dwie liczby całkowite n i x, 
a następnie stworzy dwa n-wymiarowe wektory reprezentowane przez n-elementowe tablice liczb zmiennoprzecinkowych. 
Następnie program powinien:
- uzupełnić tablicę kolejnymi wartościami zaczynając od x (std::generate)
- ustawić te wartości w losowej kolejności (wymieszać) (std::shuffle)
- wyświetlić obie tablice (std::for_each)
- wyświetlić sumę wartości w tablicach (std::accumulate)
- wyświetlić wynik iloczynu skalarnego dwóch wektorów (std::inner_product).*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <numeric>

void print(int x){
    std::cout << x << " ";
}

int main(){
    srand(time(NULL));
    int n, x;
    std::cin >> n >> x;
    float vec0[n], vec1[n];

    int i = x;
    std::generate(vec0, vec0 + n, [&]{return i++;});
    i = x;
    std::generate(vec1, vec1 + n, [&]{return i++;});

    std::random_shuffle(vec0, vec0 + n);
    std::random_shuffle(vec1, vec1 + n);

    std::for_each(vec0, vec0 + n, print);
    std::cout << "\n";
    std::for_each(vec1, vec1 + n, print);
    std::cout << "\n";

    std::cout << std::accumulate(vec0, vec0 + n, 0) << "\n";
    std::cout << std::accumulate(vec1, vec1 + n, 0) << "\n";

    std::cout << std::inner_product(vec0, vec0 + n, vec1, 0);
    return 0;
}