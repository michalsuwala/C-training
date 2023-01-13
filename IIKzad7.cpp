/*Napisz funkcję, która przyjmuje dwie równoliczne dynamiczne tablice wskaźników na napisy (c-string). 
W pierwszej tablicy, w każdym napisie zapisana jest tablica rejestracyjna, która została przechwycona przez fotoradar. 
Zakładamy że każda tablica rejestracyjna rozpoczyna się od dwóch lub trzech liter wskazujących miejscowość rejestracji, 
a następnie biały znak oraz ciąg cyfr (długość ciągu to 4 lub 5 cyfr). 
Należy pomóc jednostce policji w pogrupowaniu rejestracji według miejscowości, 
aby odpowiednio rozesłać poszczególnym jednostkom numery rejestracji wskazane do wystawienia mandatu. 
Funkcja powinna zapisać do drugiej tablicy napisy, które są połączeniem tablic rejestracyjnych dla konkretnego województwa 
(zobacz przykład). Funkcja ma zwrócić liczbę napisów w wyjściowej tablicy. 
Kolejność województw i rejestracji pojazdów w tablicy wynikowej nie ma znaczenia. 
Napisz program testujący zaimplementowaną funkcję.
IN:
[
“LRY 1234”,
“LU 87654”,
“WA 1234”,
“LRY 888”,
“LU 999”
]
OUT:
[
“LRY 1234 888”,
“LU 87654 999”,
“WA 1234”
]
*/

#include <iostream>
#include <cstdio>
#include <cstring>


int func(char **arr, char **result, int n){
    char names[n][4], numbers[n][6];
    int num = 1;
    for(int i = 0; i < n; i++){
        sscanf(arr[i], "%[^ ] %s", names[i], numbers[i]);
    }
    sprintf(result[0], "%s", arr[0]);
    int index = 0;
    bool f = 0;
    for(int i = 1; i < n; i++){
        for(int j = index; j >= 0; j--){
            f = 0;
            if(strcmp(names[i], names[j]) == 0){
                f = 1;
                std::strncat(result[j], " ", 2);
                std::strcat(result[j], numbers[i]);
                break;
            }
        }
        if(f == 0){
            sprintf(result[index + 1], "%s", arr[i]);
            index++;
            num++;
        }
    }
    return num;
}

int main(){
    int n = 5;
    char **arr = new char *[n];
    for(int i = 0; i < n; i++){
        arr[i] = new char[10];
    }
    char **res = new char *[n];
    for(int i = 0; i < n; i++){
        res[i] = new char[4 + n * 6];
    }
    arr[0] = (char*)"LRY 1234";
    arr[1] = (char*)"LU 87654";
    arr[2] = (char*)"WA 1234";
    arr[3] = (char*)"LRY 888";
    arr[4] = (char*)"LU 999";
    int num = func(arr, res, n);
    for(int i = 0; i < num; i++){
        std::cout << res[i] << "\n";
    }
    return 0;
}