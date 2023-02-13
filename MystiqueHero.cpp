/*Ranking gry NewCSShooter przechowywany jest  na serwerze w następujący sposób:
MystiqueHero;1365;6890;15210
Frizz;5400;6200;11000
Każdy wiersz reprezentuje statystyki rozegranych meczy dla danego użytkownika. Pojedynczy wiersz zawiera następujące informacje 
oddzielone od siebie średnikiem: nazwa użytkownika, ilość wygranych meczy, ilość rozegranych meczy, ilość dokonanych likwidacji. 
Przykład 
    MystiqueHero;1365;6890;15210,
można zinterpretować, że gracz MystiqueHero wygrał 1365 meczy na 6890 wszystkich rozegranych meczy i dokonał 15210 likwidacji.
Zbuduj ranking graczy obliczając ich wynik rankingowy. Napisz funkcję, która przyjmuje dynamiczną tablicę napisów (c-string), 
w której w każdym elemencie przechowywany jest zapis statystyki danego gracza oraz drugą taką tablicę  wyjściową na wyniki. 
Funkcja powinna w drugą tablicę wyjściową wpisać informacje o graczu oraz jego wynik liczony w następujący sposób: wygrane mecze  
+ wszystkie mecze + ilość likwidacji. Możesz założyć że nazwa użytkownika to nie więcej niż 12 znaków oraz całkowity wynik to 
liczba całkowita złożona z maksymalnie 10 cyfr. Napisz program testujący zaimplementowaną funkcję.*/

#include <iostream>
#include <string>
#include <algorithm>
#include <ostream>
#include <cstdio>
#include <fstream>
#include <cstring>

struct Players{
    char name[13];
    int wins;
    int matches;
    int kills;
};


std::ostream& operator<<(std::ostream& out, const Players& player){
    std::string temp(player.name);
    int sum = player.kills + player.matches + player.wins;
    out << temp << " " << sum;
    return out;
}


void func(const char *path){
    Players temp;
    FILE* file = fopen(path, "r");
    if(file == NULL){
        perror("Error");
        return;
    }
    int size = 0;
    Players player;
    while(fscanf(file, "%[^;];%d;%d;%d", temp.name, &temp.wins, &temp.matches, &temp.kills) != EOF){
        size++;
    }
    fseek(file, 0, SEEK_SET);
    Players res[size];
    int i = 0;
    while(fscanf(file, "%[^;];%d;%d;%d", res[i].name, &res[i].wins, &res[i].matches, &res[i].kills) != EOF){
        i++;
    }
std::sort(res, res + size, [](const Players a, const Players b){
        int a_sum = a.kills + a.matches + a.wins;
        int b_sum = b.kills + b.matches + b.wins;
        return a_sum > b_sum;
    });
    std::for_each(res, res + size, [](const Players a){ std::cout << a << "\n"; });
    fclose(file);
}


int main(){
    func("C:\\Users\\user\\Documents\\numsz1.txt");
    return 0;
}