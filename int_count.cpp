/*Napisz program, wyszuka w napisie wszystkie liczby a następnie na ekranie poda ich sumę. 
Zakładamy, że w napisie może się znajdować dowolna ilość liczb całkowitych 
i są zawsze poprzedzone symbolem spacji.
Przykład:

WEJŚCIE: "Ala ma 5 kotow, 3 psy i 19 myszek"

WYJŚCIE: 27
*/

#include <iostream>
#include <cmath>

void func(char arr[]){
    int result = 0,  n = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == 32){
            for(int j = 1; arr[i + j] >= 48 && arr[i + j] <= 57; j++){
                n++;
            }
            for(int j = 1; arr[i + j] >= 48 && arr[i + j] <= 57; j++){
                result += (arr[i + j] - 48) * pow(10, n - 1);
                n--;
            }
        }
    }
    std::cout << result;
}

int main(){
    char arr[] = "Ala ma 5 kotow, 3 psy i 19 myszek";
    func(arr);
    return 0;
}