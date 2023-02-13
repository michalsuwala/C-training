/*Napisz funkcje, która przyjmuje ścieżkę do pliku tekstowego oraz 5-cio literowe słowo wczytane od użytkownika. 
Funkcja powinna znaleźć w pliku ciąg znaków "*****"  i zamienić ten ciąg gwiazdek na słowo wczytane od użytkownika. 
Np. Ala ma *****. -> Ala ma rybke.*/

#include <iostream>
#include <string>
#include <fstream>

void func(const char* path, std::string word){
    std::string line;
    int pos = -1, offset = 0;
    std::fstream file;
    file.open(path, std::fstream::in | std::fstream::out);
    if(!file.good()){
        std::cout << "Error";
        return;
    }
    while(getline(file, line)){
        pos = line.find("*****");
        if(pos >= 0){
            file.seekg(pos + offset, std::ios::beg);
            file << word;
        }
        offset += line.length();
        pos = -1;
    }
    file.close();
}

int main(){
    func("C:\\Users\\user\\Documents\\numsz1.txt", "rower");
    return 0;
}