/*Napisz program, który napis w tablicy znaków wyświetli w taki sposób, że każde słowo 
(ciąg znaków oddzielony spacją) będzie wyświetlone w nowej linii.
Zmodyfikuj poprzednie zadanie tak, aby pierwszy znak w każdym słowie, jeżeli jest literą, 
został wyświetlony z użyciem wielkiej litery.
*/

#include <iostream>

void func(char arr[]){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == 32){
            arr[i] = 10;
            if(arr[i + 1] >= 97 && arr[i + 1] <= 122){
                arr[i + 1] -= 32;
            }
        }
    }
}

int main(){
    char arr[] = "Jeg snakker to fisker";
    func(arr);
    for(int i = 0; arr[i] != '\0'; i++){
        std::cout << arr[i];
    }
    return 0;
}