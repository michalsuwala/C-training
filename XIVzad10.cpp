/*Zmodyfikuj poprzednią funkcję tak aby możliwe było wprowadzenie dowolnie długiego napisu w miejsce gwiazdek. 
Gwiazdki mogą wystąpić więcej niż jeden raz.*/

#include <iostream>
#include <fstream>
#include <string>


void func(const char *path, const std::string from_str, const std::string to_str){
    std::ifstream file;
    file.open(path);
    if(!file.good()){
        perror("Error");
        return;
    }
    std::string line, file_str;
    while(std::getline(file, line)){
        file_str += line + "\n";
    }
    auto pos = file_str.find(from_str);
    while(pos != std::string::npos){
        file_str.replace(pos, from_str.length(), to_str);
        pos = file_str.find(from_str , pos);
    }
    file.close();
    std::ofstream ofile;
    ofile.open(path);
    ofile << file_str;
    ofile.close();
}


int main(){
    func("C:\\Users\\user\\Documents\\numsz1.txt", "*****", "rower");
    return 0;
}