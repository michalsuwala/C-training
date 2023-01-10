/*Napisz funkcję, która przyjmuje w argumentach liczbę 4-bajtową całkowitą nieujemną word 
oraz cztery wskaźniki na 1-bajtowe liczby całkowitą nieujemne b0,b1,b2,b3. 
Funkcja ma wpisać w argumenty wskazywane wskaźnikami b0..b3 wartości kolejnych bajtów z liczby word. 
Zadanie zrealizuj za pomocą arytmetyki wskaźnikowej i odpowiedniego ich rzutowania. Przetestuj działanie funkcji.*/

#include <iostream>

void func(unsigned int word, unsigned char *b0, unsigned char *b1, unsigned char *b2, unsigned char *b3){
    void *ptr = &word;
    *b0 = *(unsigned char*)ptr;
    ptr = (char*)ptr + 1;
    *b1 = *(unsigned char*)ptr + 1;
    ptr = (char*)ptr + 1;
    *b2 = *(unsigned char*)ptr + 2;
    ptr = (char*)ptr + 1;
    *b3 = *(unsigned char*)ptr + 3;
}

int main(){
    unsigned int word = 909825556;
    unsigned char a, b, c, d;
    unsigned char *b0 = &a, *b1 = &b, *b2 = &c, *b3 = &d;
    func(word, b0, b1, b2, b3);
    std::cout << int(d);
    return 0;
}