/*Napisz funkcję w języku C++, która przyjmuje wskaźnik na void oraz liczbę całkowitą ptrsize. 
ptrsize jest liczbą bajtów, która reprezentuje zmienną. 
Funkcja powinna odpowiednio zrzutować zmienną na typ char lub int, a następnie zwiększyć jej wartość o jeden. 
Napisz program w języku C++, który sprawdzi działanie tej funkcji dla obu tych typów.*/

#include <iostream>

void func(void *var, int ptrsize){
    if(ptrsize == sizeof(int)){
        int x = *(int*)var + 1;
        *(int*)var = x;
    }
    else if(ptrsize == sizeof(char)){
        char x = *(char*)var + 1;
        *(char*)var = x;
    }
}

int main(){
    int a = 7;
    func((void*)&a, sizeof(int));
    char b = '7';
    func((void*)&b, sizeof(char));
    std::cout << a << " " << b;
    return 0;
}