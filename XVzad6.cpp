/*Napisz program, który w pliku tekstowym znajdzie wszystkie słowa, które zawierają podciąg liter "any". Wypisz te słowa na ekranie.*/

#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream file;
    std::string word;
    file.open("C:\\Users\\user\\Documents\\matr.txt");
    if(!file.good()){
        perror("Error");
        return 1; 
    }
    while(file >> word){
        if(word.find("any") != -1){
            std::cout << word << "\n";
        }
    }
    file.close();
    return 0;
}