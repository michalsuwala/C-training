/*Ranking gry NewCSShooter przechowywany jest  na serwerze w następujący sposób:
MystiqueHero;1365;6890;15210
Frizz;5400;6200;11000
Każdy wiersz reprezentuje statystyki rozegranych meczy dla danego użytkownika. 
Pojedynczy wiersz zawiera następujące informacje oddzielone od siebie średnikiem: 
nazwa użytkownika, ilość wygranych meczy, ilość rozegranych meczy, ilość dokonanych likwidacji. 
Przykład 
    MystiqueHero;1365;6890;15210,
można zinterpretować, że gracz MystiqueHero wygrał 1365 meczy na 6890 wszystkich rozegranych meczy i dokonał 15210 likwidacji.
Zbuduj ranking graczy obliczając ich wynik rankingowy. Napisz funkcję, która przyjmuje dynamiczną tablicę napisów (c-string), 
w której w każdym elemencie przechowywany jest zapis statystyki danego gracza oraz drugą taką tablicę  wyjściową na wyniki. 
Funkcja powinna w drugą tablicę wyjściową wpisać informacje o graczu oraz jego wynik liczony w następujący sposób: 
wygrane mecze  + wszystkie mecze + ilość likwidacji. 
Możesz założyć że nazwa użytkownika to nie więcej niż 12 znaków oraz całkowity wynik to liczba całkowita złożona z maksymalnie 10 cyfr. 
Napisz program testujący zaimplementowaną funkcję.
IN:
[
“MystiqueHero;1365;6890;15210”,
“Frizz;5400;6200;11000”,
“Ziemniak;9965;11000;73000”,
“Evel00na;10;10;90”
]
OUT:
[
“MystiqueHero 23465”, //(bo 1365 + 6890 + 15210 = 23465)
“Frizz 22600”,
“Ziemniak 93965”,
“Evel00na 110”,
]*/

#include <iostream>
#include <cstdio>

void func(char **stats, char **res, int n){
    for(int i = 0; i < n; i++){
        char name[13];
        int wins, games, kills;
        sscanf(stats[i], "%[^;];%d;%d;%d", name, &wins, &games, &kills);
        int score = wins + games + kills;
        sprintf(res[i], "%s %d", name, score);
    }
}

int main(){
     int n = 4;
    char **stats = new char *[n];
    for(int i = 0; i < n; i++){
        stats[i] = new char[46];
    }
    char **res = new char *[n];
    for(int i = 0; i < n; i++){
        res[i] = new char[46];
    }
    stats[0] = (char*)"MystiqueHero;1365;6890;15210";
    stats[1] = (char*)"Frizz;5400;6200;11000";
    stats[2] = (char*)"Ziemniak;9965;11000;73000";
    stats[3] = (char*)"Evel00na;10;10;90";
    func(stats, res, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; res[i][j] != 0; j++){
            std::cout << res[i][j];
        }
        std::cout << "\n";
    }
    for(int i = 0; i < n; i++){
        delete[] stats[i];
        delete[] res[i];
    }
    delete[] stats;
    delete[] res;
    return 0;
}