/*Napisz program, który podzieli podany string na tokeny (fragmenty napisu) rozdzielone podanym znakiem. 
Zbierz wszystkie tokeny do tablicy stringów i następnie wyświetl je na ekranie. 
Do wykonania zadania można użyć funkcji strtok() z pliku <cstring>.
PRZYKŁAD:
string str = "ala;ma kota;i;dwa psy"
char delimeter = ';'
tokeny: "ala", "ma kota", "i", "dwa psy"*/

#include <iostream>
#include <cstring>

int main(){
    char str[] = "ala;ma kota;i;dwa psy";
    const char *delimeter = ";";
    char *token = std::strtok(str, delimeter);
    std::string arr[7];
    int i = 0;
    while (token){
        arr[i] = token;
        token = std::strtok(nullptr, delimeter);
        ++i;
    }
    for(int j = 0; j < i; j++){
        std::cout << arr[j] << " ";
    }
    return 0;
}