/*Napisz funkcję search_string(), która przyjmie tablicę napisów, 
jej rozmiar oraz wskaźnik na funkcję pf odpowiedniej postaci. 
Funkcja search_string() powinna zwrócić wskaźnik na napis, 
dla którego funkcja pf zwróci największą wartość. 
Zdefiniuj funkcję search_string() tak, 
aby jako funkcja pf mogła być wywołana funkcja strpbrk, 
której jako drugi argument zostanie przekazany napis złożony z samogłosek.*/

#include <iostream>
#include <cstring>

char *search_string(char dest[][10], int size,  char *(*pf)(const char*, const char*)){
    char a[] = "aey";
    char *breakset = a;
    char *result = pf(dest[0], breakset);
    for(int i = 0; i < size; i++){
        if(result < pf(dest[i], breakset)){
            result = dest[i];
        }
    }
    return result;
}

int main(){
    char dest[3][10] = {{"kveld"}, {"morgen"}, {"bjornen"}};
    int size = 3;
    char *res = search_string(dest, size, std::strpbrk);
    for(int i = 0; *(res + i) != 0; i++){
        std::cout << *(res + i);
    }
    return 0;
}