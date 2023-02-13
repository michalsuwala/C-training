/*Zaprojektuj klasę Contestant w języku C++, która ma trzy pola: napis name i dwie liczby całkowite age oraz ratings. 
Dodatkowo klasa powinna posiadać metodę add_to_file, która w argumencie przyjmuje nazwę pliku. Metoda ta powinna zapisać 
instancje klasy do pliku, o nazwie przekazanej w argumencie. Ponadto zaimplementuj funkcję output_highest_rated, 
która w argumencie przyjmuje nazwę pliku. Funkcja output_highest_rated powinna w pliku, o nazwie przekazanej w argumencie, 
znaleźć uczestnika o największej ocenie i zwrócić odpowiedni obiekt klasy Contestant. Napisz program w języku C++, 
który przetestuje działanie tak zaprojektowanej klasy.*/

#include <iostream>
#include <string>
#include <fstream>

class Contestant{
    std::string name;
    int age, ratings;
public:

    Contestant() {}

    Contestant(std::string nam, int ag, int rating) : name(nam), age(ag), ratings(rating) {};

    void add_to_file(const char *path){
        int pos = 0;
        std::string line;
        std::ofstream file;
        file.open(path, std::ios::app);
        if(!file.good()){
            perror("Error");
            return;
        }
        file << name << age << ratings << "\n";
        file.close();
        /*std::fstream file;
        file.open(path, std::fstream::out | std::fstream::app);
        if(!file.good()){
            perror("Error");
            return;
        }
        file.write((char*)this, sizeof(this));
        file.close();*/
    }

    void output_highest_rated(const char *path, Contestant *result){  
        std::ifstream file;
        Contestant temp;
        file.open(path);
        if(!file.good()){
            perror("Error");
            return;
        }
        file.read((char*)&temp, sizeof(temp));
        while(!file.eof()){
            if(temp.ratings > result->ratings){
                result->age = temp.age;
                result->ratings = temp.ratings;
                result->name = temp.name;
            }
            file.read((char*)&temp, sizeof(temp));
        }
        file.close();
    }

    std::string getName(){
        return this->name;
    }
};

int main(){
    Contestant cont("Mariusz", 7, 4);
    cont.add_to_file("C:\\Users\\user\\Documents\\numsz1.txt");
    Contestant *max = new Contestant;
    max->output_highest_rated("C:\\Users\\user\\Documents\\numsz1.txt", max);
    std::cout << max->getName();
    delete max;
    return 0;
}