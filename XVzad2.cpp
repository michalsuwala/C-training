/*Napisz program, który policzy wszystkie słowa w podanym napisie.*/

#include <iostream>
#include <string>
#include <sstream>


int main(){
    std::string sent = "Bjornene og hundene liker oss";
    std::string word;
    std::stringstream sente(sent);
    int words = 0;
    while(sente >> word){
        words++;
    }
    std::cout << words;
    return 0;
}