/*Zdefiniuj typ wyliczeniowy AnimalType zawierający kilka typowych nazw zwierząt domowych. 
Zaprojektuj klasę Animal, która posiada dwa pola: zmienną typu wyliczeniowego AnimalType 
oraz tablicę będącą maksymalnie 10 znakową nazwą pupila. 
Dodatkowo klasa powinna zawierać metodę say_something(int n). 
Funkcja say_something() w zależności od typu zwierzęcia powinna wyświetlić odpowiedni komunikat 
np. dla kota "miał" oraz powtórzyć go n razy, gdzie n zostało przekazane w argumencie metody. 
Uzupełnij klasę o odpowiedni destruktor oraz konstruktor kopiujący.*/

#include <iostream>
#include <string>

enum AnimalType{DOG, CAT, PARROT, CHICKEN, RABBIT};

class Animal{
    AnimalType type;
    std::string name;
public:
    Animal(AnimalType animal, std::string name) : type(animal), name(name) {}
    Animal(const Animal &animal_t) : type(animal_t.type), name(animal_t.name) {}
    ~Animal(){}

    void say_something(int n){
        switch(type){
            case CAT:
                for(int i = 0; i < n; i++){
                    std::cout << "mew" << " ";
                }
                break;
            case DOG:
                for(int i = 0; i < n; i++){
                    std::cout << "woof" << " ";
                }
                break;
            case PARROT:
                for(int i = 0; i < n; i++){
                    std::cout << "Panie Kominiarzu" << " ";
                }
                break;
            case CHICKEN:
                for(int i = 0; i < n; i++){
                    std::cout << "koko" << " ";
                }
                break;
            case RABBIT:
                for(int i = 0; i < n; i++){
                    std::cout << "skryt" << " ";
                }
                break;
        }
    }
};

int main(){
    Animal animal(PARROT, "Bożena");
    animal.say_something(3);
    return 0;
}