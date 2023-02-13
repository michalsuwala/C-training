/*Napisz program, który umożliwi użytkownikowi wprowadzenie wiadomości zawierającej informacje o jego imieniu, wieku, wzroście i wadze 
w następującym formacie np. "Ala 12 162.52 52.28". Odczytaj informacje z tak przekazanej wiadomości i zapisz je w odpowiednich zmiennych. 
Następnie program powinien wyświetlić te informację w następujący sposób:
Imię
Wiek (w systemie szesnastkowym)
Wzrost (z dokładnością do 2 miejsc po przecinku)
Waga (z dokładnością do 3 miejsc po przecinku)*/

#include <iostream>
#include <string>
#include <sstream>

int main(){
    std::string data;
    std::getline(std::cin, data);
    std::string name;
    int age;
    float height, weight;
    std::stringstream dat(data);
    dat >> name >> age >> height >> weight;
    std::cout << name << "\n" << std::hex << age << std::endl;
    std::cout.precision(3); 
    std::cout << std::fixed << height << std::endl;
    std::cout.precision(2);
    std::cout << std::fixed << weight << std::endl;
    return 0;
}