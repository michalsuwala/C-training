/*
Napisz program, który wczyta od użytkownika dodatnią liczbę całkowitą r 
i wyświetli na ekranie terminala koło zbudowane ze znaków ‘#’ o promieniu równym r (zgodnie z przykładem poniżej). Równanie koła ma postać: x^2+y^2 <= r^2. Do obliczenia pierwiastka kwadratowego użyj funkcji std::sqrt() z biblioteki <cmath>.
*/

#include <iostream>

int main(){
    int r;
    std::cin >> r;
    for(int x = -r; x <= r; x++){
        for(int y = -r; y <= r; y++){
            if(x * x + y * y <= r * r){
                std::cout << "#";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}