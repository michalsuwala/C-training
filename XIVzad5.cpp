/*Stwórz funkcję write_array(), która zapisze podaną w argumencie tablicę liczb zmiennoprzecinkowych (float) do pliku 
(nazwa podana w argumencie funkcji) w postaci binarnej (nieformatowanej), gdzie każdy element tablicy jest kodowany na czterech bajtach.
Stwórz analogiczną funkcję read_array(), która wczyta z takiego pliku (nazwa podana w argumencie funkcji) 
dane do przekazanej w argumencie tablicy liczb zmiennoprzecinkowych (float). Funkcja powinna wczytać 
nie więcej elementów niż zadeklarowana wielkość tablicy i zwrócić rzeczywistą ilość wczytanych elementów.*/

#include <iostream>

void write_array(float *arr, int size, const char *path){
    FILE* file = fopen(path, "wb");
    if(file == NULL){
        std::cout << "Error";
        return;
    }
    fwrite(arr, sizeof(float), size, file);
    fclose(file);
}

int read_array(float *arr, int size, const char *path){
    FILE* file = fopen(path, "rb");
    if(file == NULL){
        return -1;
    }
    int res = fread(arr, sizeof(float), size, file);
    fclose(file);
    return res;
}

int main(){
    int n = 5;
    float arr[n] = {2,45,32,2,6};
    write_array(arr, n, "C:\\Users\\user\\Documents\\numsf.txt");
    float ar[n];
    std::cout << read_array(ar, n, "C:\\Users\\user\\Documents\\numsf.txt") << std::endl;
    std::cout << ar[0] << " " << ar[n - 1];
    return 0;
}

