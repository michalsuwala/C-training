/*Napisz funkcję, która przyjmie dwa parametry liczbę całkowitą x oraz liczbę całkowitą d, 
w której zapisana będzie cyfra. Funkcja powinna zwrócić liczbę wystąpień cyfry d w liczbie x. 
W implementacji tej funkcji nie używaj pętli.*/

#include <iostream>
#include <algorithm>
#include <cstdio>

int func(long long int x, int d){
    char arr[100];
    std::sprintf(arr, "%lld", x);
    return std::count(arr, arr + 100, d + 48);
}

int main(){
    long long int x = 29302438393243245;
    int d = 3;
    std::cout << func(x, d);
    return 0;
}