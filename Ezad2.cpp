#include <string>
#include <iostream>


class Hotel{
    float score;
    std::string name;

public:

    Hotel() {}

    Hotel(std::string name, float score) : name(name), score(score) {}

    float getScore(){
        return score;
    }

    std::string getName(){
        return name;
    }
};


std::ostream& operator<<(std::ostream& out, Hotel& hotel){
    std::string name = hotel.getName();
    out << name << " " << hotel.getScore() << "\n";
    return out; 
}


int main(){
    Hotel *hotels = new Hotel[3]{{"Bonacii", 7.2}, {"Elanoa", 6.2}, {"Jurki", 10.0}};
    for(int i = 0; i < 3; i++){
        std::cout << hotels[i];
    } 
    delete[] hotels;
    return 0;
}