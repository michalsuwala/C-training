/*Zaprojektuj i zaimplementuj klasę String do obsługi napisów. Klasa ta powinna mieć metody:
- konstruktor domyślny, konstruktor inicjujący i konstruktor kopiujący
- destruktor
- length() - zwracającą długość napisu
- cstring() - zwracającą wskaźnik na tablicę znakową w tylu c
- append(...) - dodającą do aktualnego napisu inny napis
- clear() - czyszczącą napis
- empty() - zwracającą informację czy napis jest pusty
- print() - drukującą napis na ekranie
- operator przypisania '=' - zadbaj o głęboką kopię obiektu
Przetestuj tworzoną klasę w programie głównym na obiektach automatycznych i dynamicznych.*/

#include <iostream>
#include <cstring>

class String{
    char *str;
    int size;
public:

    String() : str(nullptr), size(0) {}

    String(const char *string){
        size = std::strlen(string);
        str = new char[size + 1];
        std::strcpy(str, string);
    }

    String(const String &string){
        size = string.size;
        str = new char[size + 1];
        std::strcpy(str, string.str);
    } 

    ~String(){ delete[] str; }

    String copy(const String &s){
        if(this != &s){
            delete[] str;
            str = new char[std::strlen(s.str) + 1];
            std::strcpy(str, s.str);
            size = s.size;
        }
        return *this;
    }

    //below incorrect
    int length(){
        return size;
    }
    void append(char *a_str, int a_size){
        char *temp = new char[size + a_size + 1];
        for(int i = 0; i < size; i++){
            temp[i] = str[i];
        }
        for(int i = size , j = 0; i < size + a_size; i++, j++){
            temp[i] = a_str[j];
        }
        delete[] str;
        str = temp;
        size = size + a_size - 1;
    }
    void print(){
        for(int i = 0; str[i] != 0; i++){
            std::cout << str[i];
        }
    }
    char *cstring(){
        return str;
    }
};

int main(){
    int size = 4;
    String string("Wujo");
    string.print();
    return 0;
}