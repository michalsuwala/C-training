/*Napisz program, który usunie plik stworzony w poprzednim zadaniu.*/

#include <iostream>
//#include <cstdio>

int main(){
    if(remove("C:\\Users\\user\\Documents\\nums.txt") != 0) { std::cout << "Error"; }
    else { std::cout << "Deleted "; }
    return 0;
}