/*Napisz program, który wczyta z pliku tekstowego wszystkie napisy do tablicy napisów.*/

#include <iostream>
#include <string>

int main(){
    FILE* file = fopen("C:\\Users\\user\\Documents\\matr.txt", "r");
    std::string temp;
    int size = 0;
    while(fscanf(file, "%s", &temp) != EOF){
        size++;
    }
    fclose(file);
    std::string arr[size];
    file = fopen("C:\\Users\\user\\Documents\\matr.txt", "r");
    int count = 0;
    char arra[size][100];
    while(fscanf(file, "%s", arra[count]) != EOF){
        arr[count] = arra[count];
        count++;
    }
    fclose(file);
    std::cout << arr[size - 1];
    return 0;
}