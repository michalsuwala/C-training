/*Napisz program, który pobiera od użytkownika dwie liczby całkowite dodatnie n i m. 
Następnie program ma generować i wyświetlać na ekranie pseudolosowe zdanie, 
które ma być zbudowane z n słów a każde słowo ma być zbudowane z co najwyżej m znaków. 
W słowach mają się pojawiać, z równym prawdopodobieństwem, małe i duże litery.
PRZYKŁAD:
IN: 8 5
OUT: jtETN jxpd G DDYmP NYtT HubNe IAByV jmN
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    int n, m, length;
    std::cin >> n >> m;
    char letter;
    bool f;
    for(int i = 0; i < n; i++){
        length = 1 + rand() / (RAND_MAX / m);
        for(int j = 0; j < length; j++){
            f = rand() / (RAND_MAX / 2);
            if(f == 1){
                letter = 65 + rand() / (RAND_MAX / (90 - 65 + 1));
                std::cout << letter;
            }
            else{
                letter = 97 + rand() / (RAND_MAX / (90 - 65 + 1));
                std::cout << letter;
            }
        }
        std::cout << " ";
    }
    return 0;
}