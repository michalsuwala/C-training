/*Napisz program w języku C++, który wczyta od użytkownika maksymalnie 100 znakowe słowo. 
Następnie program powinien stworzyć odwrócony odpowiednik napisu wprowadzonego przez użytkownika 
za pomocą arytmetyki wskaźników.*/

#include <iostream>

int main(){
    char str[101] = {0}, reverse[101] = {0};
    std::cin >> str;
    char *s = str, *r  = reverse;
    int len = 0;
    for(;*s; s++, len++);
    s--;
    for(;len > 0; len--, s--, r++){
        *r = *s;
    }
    printf("%s", reverse);
    return 0;
}