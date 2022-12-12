/*Napisz funkcję, która przyjmuje jednobajtową liczbę całkowitą bez znaku v, 
liczbę całkowitą b i zmienną logiczną f. 
Funkcja powinna pozostawić jedynie wartość 4 najmłodszych bitów liczby v, 
a następnie zanegować wartość tych 4-ech bitów, jeżeli f jest równe true, 
w przeciwnej sytuacji ten krok powinien być pominięty. 
Na koniec funkcja powinna zanegować bit na pozycji b i zwrócić nową wartość. 
W przogramie głównym Wyświetli wartość zwróconą przez funkcję z zadanymi argumentami.
*/

#include <iostream>
int func(unsigned char v, int b, bool f){
    if(f){
        v = v << 4;
        v = ~v;
        v = v >> 4;
    }
    int n = 1;
    n = n << b;
    v = v ^ n;
    return v;
}
    
int main(){
    unsigned char v = 13;
    std::cout << func(v, 6, true);
    return 0;
}