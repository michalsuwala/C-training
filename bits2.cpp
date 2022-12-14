/*Napisz program, który pobiera od użytkownika dwie liczby jednobajtowe bez znaku t, s. 
Wylicz i wyświetl nową wartość w następujący sposób:
1) zamień 4 najmłodsze bity liczby s miejscami z 4 najstarszymi bitami liczby s;
2) w powstałej liczbie zaneguj bit znajdujący się na pozycji będącej wynikiem reszty z dzielenia t przez 8.
PRZYKŁAD:
t = 214; reszta z (t/8) = 6
s = 93 = 0101 1101b
1)   1101 0101b = 213
2)   1001 0101b = 149*/

#include <iostream>


int main(){
    unsigned char t, s;
    int a, b;
    std::cin >> a >> b;
    t = a;
    s = b;
    //1)
    unsigned char first = 15;
    first = first << 4;
    first = first & s;
    first = first >> 4;
    s = s << 4;
    s = s | first;
    std::cout << (int)s << "\n";
    //2)
    unsigned char rem = t % 8;
    rem = 1 << rem;
    t = s ^ rem;
    std::cout << (int)t;
    return 0;
}