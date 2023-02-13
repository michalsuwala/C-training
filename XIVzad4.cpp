/*Stwórz funkcję, która przyjmuje ścieżkę do pliku tekstowego. W pliku tekstowym znajdują się liczby całkowite 
oddzielone pojedynczymi spacjami. Funkcja powinna wczytać te liczby zwiększyć o jeden i ponownie zapisać do pliku.*/

#include <iostream>
#include <fstream>

void increase(const char *path){
    FILE* data = fopen(path, "r");
    int size = 0, temp;
    while(fscanf(data, "%d", &temp) != EOF){
        size++;
    }
    fclose(data);
    int arr[size];
    data = fopen(path, "r");
    for(int i = 0; i < size; i++){
        fscanf(data, "%d", &temp);
        arr[i] = temp;
    }
    fclose(data);
    data = fopen(path, "w");
    for(int i = 0; i < size; i++){
        fprintf(data, "%d ", arr[i] + 1);
    }
    fclose(data);
}

int main(){
    increase("C:\\Users\\user\\Documents\\numsz1.txt");
    return 0;
}

/*void increase(const char *path){
    std::fstream file;
    file.open(path, std::ios::in | std::ios::out);
    int
}*/