/*Wydrukuj na ekranie kilka wylosowanych liczb całkowitych z przedziału 0..1000 w taki sposób, aby zawsze cyfra jedności danej liczby 
znajdowała się pod cyfrą jedności poprzedniej liczby. Wydrukuj te liczby ponownie w postaci szesnastkowej.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    for(int i = 0; i < 5; i++){
        int num = rand() % 1000;
        std::cout.width(3);
        std::cout << std::dec << num;
        std::cout << "\n";
        std::cout.width(3);
        std::cout << std::hex << num;
        std::cout << "\n\n";
    }
    return 0;
}