/*Napisz funkcję find_substring(), która w stringu podanym w pierwszym argumencie wyszukuje wystąpienia stringu 
podanego w drugim argumencie. Funkcja powinna zwracać wskaźnik na pierwszy znak identycznego podciągu lub nullptr 
jeżeli takiego podciągu nie ma.*/

#include <iostream>
#include <cstring>

char *find_substring(char arr0[], char arr1[]){
    int len = 0;
    for(int i = 0; arr1[i] != 0; i++){
        ++len;
    }
    for(int i = 0; arr0[i] != 0; i++){
        if(std::strncmp(arr0 + i, arr1, len) == 0){
            return arr0 + i;
        }
    }
    return nullptr;
}

int main(){
    char arr0[] = "Hundene drikker vann", arr1[] = "drikker";
    std::cout << find_substring(arr0, arr1);
    return 0;
}