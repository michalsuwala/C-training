/*Napisz program, który dopisze na końcu podanego w linii poleceń pliku aktualną datę i czas w formacie "DD-MM-YYYY hh:mm:ss".*/

#include <iostream>
#include <fstream>
#include <ctime>

int main(){
    std::ofstream file;
    file.open("C:\\Users\\user\\Documents\\matr.txt", std::ios::app);
    if(!file.good()){
        perror("Error");
        return 1;
    }
    std::string date;
    time_t t = time(NULL);
    tm* ct = localtime(&t);
    char res[100];
    std::sprintf(res, "\n%d-%d-%d %d:%d:%d", ct->tm_mday, 1 + ct->tm_mon, 1900 + ct->tm_year, ct->tm_hour, ct->tm_min, ct->tm_sec);
    
    std::string str;
    for(int i = 0; res[i] != 0; i++){
        std::cout << res[i];
        str.push_back(res[i]);
    }
    //int i = 0;
    //while(file << res[i]){ i++; std::cout << res[i];}
    file << str;
    file.close();
    return 0;
}