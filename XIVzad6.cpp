/*Stwórz prostą strukturę do obsługi macierzy. Zdefiniuj funkcje write_mat() i read_mat() do zapisu/odczytu macierzy 
do/z pliku tekstowego (formatowanego). Plik tekstowy ma być sformatowany w ten sposób, że w pierwszym wierszu są dwie 
liczby całkowite: szerokość i wysokość macierzy a w następnych liniach są zapisane kolejno elementy macierzy rozdzielone 
spacją w postaci liczb zmiennoprzecinkowych.
*/

#include <iostream>

void write_mat(int m, int n, float **mat, const char *path){
    FILE* file = fopen(path, "w");
    if(file == NULL){
        std::cout << "Error";
        return;
    }
    
    fprintf(file, "%d %d\n", m, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fprintf(file, "%.1f ", mat[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void read_mat(float **mat, const char *path){
    FILE* file = fopen(path, "r");
    if(file == NULL){
        std::cout << "Error";
        return;
    }
    int m, n;
    fscanf(file, "%d %d\n", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fscanf(file, "%f ", &mat[i][j]);
        }
        fscanf(file, "\n");
    }
    fclose(file);
}

int main(){
    int m = 3, n = 3;
    float **mat = new float*[m];
    for(int i = 0; i < m; i++){
        mat[i] = new float[n]; 
        for(int j = 0; j < n; j++){
            mat[i][j] = j;
        }
    }
    float **matr = new float *[m];
    for(int i = 0; i < m; i++){
        matr[i] = new float[n]; 
    }
    write_mat(m, n, mat, "C:\\Users\\user\\Documents\\matr.txt");
    read_mat(matr, "C:\\Users\\user\\Documents\\matr.txt");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << matr[i][j] << " ";
        }
        std::cout << "\n";
    }
    for(int i = 0; i < m; i++){
        delete[] mat[i];
    }
    delete[] mat;
    for(int i = 0; i < m; i++){
        delete[] matr[i];
    }
    delete[] matr;
    return 0;
}