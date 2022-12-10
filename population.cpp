/*Pewna obojnacza populacja rozwija się w taki sposób, że na wiosnę wszystkie osobniki łączą się w pary,
a każda para ma jedno młode.
W lecie liczebność nie zmienia się. Przez jesień populacja pozbywa się dziesięciu najsłabszych osobników.
Zimę przeżywa 60% populacji. Napisz funkcję rekurencyjną,
która przyjmie początkową liczebność populacji oraz rok i porę roku (wiosna - 0, ..., zima - 3). 
Funkcja powinna zwrócić liczebność populacji w podanym roku, po zakończeniu podanej pory roku. 
Zakładamy, że początkowa liczebność jest odczytana w roku 0, na początku wiosny. 
Jeżeli pośrednim lub ostatecznym wynikiem będzie liczba niecałkowita, zaokrąglamy wynik na niekorzyść populacji. 
*/

#include <iostream>

int pop(int size, int year, int season){
    if(year == 0){
        return size;
    }
    if(season == 0){
        std::cout << size << "\n";
        return pop(size + size / 2, year, 1);
    }
    if(season == 1){
        std::cout << size << "\n";
        return pop(size, year, 2);
    }
    if(season == 2){
        return pop(size - 10, year, 3);
    }
    if(season == 3){
        return pop(size * .6, year - 1, 0);
    }
    else{
        return 0;
    }
}

int main(){
    std::cout << pop(2000, 10, 0);
    return 0;
}