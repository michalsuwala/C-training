/*Napisz funkcję, która w argumencie przyjmuje napis (c-string) a następnie sprawdza, 
czy dany napis złożony jest z samych cyfr. W przypadku, gdy napis składa się z samych cyfr, 
funkcja powinna zwrócić liczbę całkowitą, którą reprezentuje napis lub wartość -1 w przeciwnym wypadku. 
W funkcji głównej wczytaj od użytkownika napis i wyświetl wynik działania funkcji.
PRZYKŁADY:
IN: "123ak"
OUT: -1
IN: "1001"
OUT: 1001*/

#include <iostream>
#include <cmath>


int func(char str[]){
    int size = -1, num = 0;
    for(int i = 0; str[i] != 0; i++){
        if(str[i] >= 48 && str[i] <= 57){
            size++;
        }
        else{
            return -1;
        }
    }
    for(int i = 0; str[i] != 0; i++){
        num += (str[i] - 48) * pow(10, size);
        --size;
    }
    return num;
}

int main(){
    char str[] = "54d5709";
    std::cout << func(str);
    return 0;
} 