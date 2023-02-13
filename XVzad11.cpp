/*Dla struktury City opracuj binarny format pliku do przechowywania danych o miastach. Napisz funkcje do zapisu i odczytu tablicy 
z miastami z tak zdefiniowanego pliku binarnego.*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


struct City{
    std::string name;
    unsigned int population;
    float x, y;

    City(){}

    City(std::string name) : name(name) {
        population = 1000000 * rand() / RAND_MAX;
        x = -180 + 180 * float(rand()) / RAND_MAX;
        y = -180 + 180 * float(rand()) / RAND_MAX;
    }

    City(const City &city) : name(city.name), population(city.population), x(city.x), y(city.y) {}
};


std::ostream& operator<<(std::ostream& out, const City city){
  out << city.name << " has a population of " << city.population
      << " and is located at (" << city.x << ", " << city.y
      << ").";
  return out;
}


void ins_cities(const char *path, City city[], int num){
    std::ofstream file;
    file.open(path, std::ios::binary);
    if(!file.good()){
        perror("Error");
        return;
    }
    for(int i = 0 ; i < num; i++){
        file.write((char*)&city[i], sizeof(city[i]));
    }
    file.close();
}


City *read_cities(const char *path){
    std::ifstream file;
    file.open(path, std::ios::binary);
    if(!file.good()){
        perror("Error");
        return nullptr;
    }
    file.seekg(0, std::ios::end);
    int size = file.tellg() / sizeof(City);
    City *res = new City[size];
    file.seekg(0, std::ios::beg);
    int i = 0;
    while(file.read((char*)&res[i], sizeof(res[i]))){
        i++;
    }
    file.seekg(0, std::ios::beg);
    file.close();
    return res;
}


int main(){
    City cities[3]{
        City("Kolonika"), 
        City("Boharda"), 
        City("Fellenoi")
    };
    City *res;
    ins_cities("C:\\Users\\user\\Documents\\cities.txt", cities, 3);
    res = read_cities("C:\\Users\\user\\Documents\\cities.txt");
    std::cout << res[0];
    delete[] res;
    return 0;
}