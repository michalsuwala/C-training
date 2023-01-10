/*Napisz dwie funkcje condition i action. Funkcja condition powinna przyjąć liczbę całkowitą i zwrócić wartość logiczną. 
Funkcja action powinna przyjmować referencję na liczbę całkowitą i nic nie zwracać. 
Funkcja condition ma sprawdzać, czy w liczbie powtarza się którakolwiek cyfra. 
Funkcja action powinna odwrócić kolejność cyfr w tej liczbie.
Napisz funkcję modify_array, która przyjmie tablicę liczb całkowitych, 
jej rozmiar oraz dwa wskaźniki na funkcje o nagłówkach takich jak condition i action. 
Dla każdego elementu tablicy spełniającego warunek condition należy wywołać funkcję action.*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>


bool condition(int x){
    int size = 0;
    int temp = x;
    while(temp >= 1){
        ++size;
        temp /= 10;
    }
    char arr[size + 1];
    sprintf(arr, "%d", x);
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]){
                return 1;
            }
        }
    }
    return 0;
}

void action(int &x){
    std::string temp = std::to_string(x);
    std::reverse(temp.begin(), temp.end());
    x = std::stoi(temp);
}

int main(){
    int x = 4532;
    action(x);
    std::cout << x << "\n" << condition(x);
    return 0;
}