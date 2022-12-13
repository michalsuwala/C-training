/*Zdefiniuj funkcję, która przyjmuje jako argumenty: napis str oraz 
automatyczną tablicę liczb całkowitych bez znaku occ o długości równej ilości znaków w napisie str. 
Funkcja powinna w i-ty element tablicy occ wpisać liczbę wystąpień 
(w całym napisie str) i-tego znaku z tego napisu.
Napis str może zawierać jedynie małe i wielkie litery oraz spacje. 
Małe i wielkie litery zliczamy łącznie, jako ten sam znak.
PRZYKŁAD:
IN str = “Ala ma kota”
OUT occ = [4, 1, 4, 2, 1, 4, 2, 1, 1, 1, 4]
*/

#include <iostream>

void func(char str[], int occ[]){
    int size = 0;
    for(int i = 0; str[i] != '\0'; i++){
        int times = 0;
        for(int j = 0; str[j] != '\0'; j++){
            if(str[i] == 32){
                if(str[i] == str[j]){
                    times++;
                }
            }
            else{
                if(str[i] == str[j] || str[i] == str[j] + 32 || str[i] == str[j]  - 32){
                    times++;
                }
            }
        }
        occ[i] = times;
    }
}

int main(){
    char str[] = "Ala ma kota";
    int occ[11];
    func(str, occ);
    for(int i = 0; i < 11; i++){
        std::cout << occ[i] << "\t";
    }
    return 0;
}