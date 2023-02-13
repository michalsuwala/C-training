/*Stwórz funkcję, która przyjmuje ścieżkę do pliku tekstowego. W pliku tekstowym znajdują się posortowane rosnąco liczby całkowite 
oddzielone pojedynczymi spacjami. Funkcja powinna wczytać te liczby do tablicy i znaleźć w nich wartość minimalną i maksymalną.*/

#include <iostream>
#include <fstream>

/*void min_max(const char *path){
    FILE* data = fopen(path, "r");
    int size = 0, tmp;
    while(fscanf(data, "%d", &tmp) != EOF){
        size++;
    }
    int arr[size];
    fclose(data);
    data = fopen(path, "r");
    for(int i = 0; i < size; i++){
        fscanf(data, "%d", &tmp);
        arr[i] = tmp;
    }
    fclose(data);
    std::cout << arr[0] << " " << arr[size - 1];
}*/

void min_max(const char *path){
    int temp, count = 0;
    int arr[100];
    std::ifstream file;
    file.open(path);
    if(!file.good()){
        std::cout << "Error";
        return;
    }
    while(file >> temp){
        arr[count++] = temp;
    }
    file.close();
    std::cout << arr[0] << " " << arr[count - 1];
}

int main(){
    min_max("C:\\Users\\user\\Documents\\numsz1.txt");
    return 0;
}

