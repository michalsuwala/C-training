/*
Zdefiniuj strukturę City opisującą miasto i zawierającą składowe: nazwa miasta (string), ilość mieszkańców (uint), 
dwie współrzędne geograficzne (2x double).
Zdefiniowany jest plik tekstowy typu csv (coma-separated values, https://pl.wikipedia.org/wiki/CSV_(format_pliku)) 
zawierający listę takich miast. W programie głównym wczytaj z tego pliku dane i stwórz na ich podstawie tablicę obiektów typu City.*/

#include <iostream>
#include <string>
#include <fstream>

struct City{
    std::string name;
    unsigned int population;
    double x, y;
};


std::ostream& operator<<(std::ostream& out, const City city){
  out << city.name << " has a population of " << city.population
      << " and is located at (" << city.x << ", " << city.y
      << ").";
  return out;
}


int main(){
    std::ifstream file;
    int size = -1, index = 0;
    std::string line;
    file.open("C:\\Users\\user\\Documents\\numsz1.txt");
    if(!file.good()){
        perror("Error");
        return 1;
    }
    while(std::getline(file, line)){
        size++;
    }
    file.close();
    City cities[size];
    file.open("C:\\Users\\user\\Documents\\numsz1.txt");
    std::getline(file, line);
    while(file.good()){
        std::getline(file, cities[index].name, ',');
        std::getline(file, line, ',');
        cities[index].population = std::stoi(line);
        std::getline(file, line, ',');
        cities[index].x = std::stod(line);
        std::getline(file, line);
        cities[index].y = std::stod(line);
        index++;
    }
    file.close();
    std::cout << cities[1];
    //std::cout << cities[1].name << " " << cities[1].population << " " << cities[1].x;
    return 0;
}