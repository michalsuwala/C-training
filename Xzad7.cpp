/*Napisz program, który wczyta od użytkownika liczbę jako napis. Liczba powinna mieć co najwyżej 10 cyfr. 
Następnie program powinien zwiększyć tą liczbę o 10 i ją wyświetlić. */

#include <iostream>
#include <cstdlib>
//#include <cstdio>

int main(){
    char arr[11] = {0};
    char *ptr = nullptr;
    std::cin >> arr;
    long res = strtol(arr, &ptr, 10);
    res += 10;
    std::cout << std::to_string(res);
    return 0; 
}
