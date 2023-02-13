/*Napisz program w języku C++, który będzie w stanie zaszyfrować i odszyfrować wiadomość szyfrem AtBash. Szyfr AtBash jest to prosty 
monoalfabetyczny szyfr podstawieniowy pochodzenia hebrajskiego, którego działanie polega na zamianie litery leżącej w odległości X 
od początku alfabetu na literę leżącą w odległości X od jego końca. Szyfrowanie powinno usuwać wszystkie białe znaki w tekście. */

#include <iostream>
#include <string>

void atbash(std::string &s){
    std::string res;
    for(int i = 0, j = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            char c = 'z' - (std::tolower(s[i]) - 'a');
            res.push_back(c);
        }
        else if(s[i] == 32){
            continue;
        }
        else{
            res.push_back(s[i]);
        } 
        j++;
    }
    s = res;
}

int main(){
    std::string str = "non e una ragazza11";
    atbash(str);
    std::cout << str << "\n";
    atbash(str);
    std::cout << str;
    return 0;
}