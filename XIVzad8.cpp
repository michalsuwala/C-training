/*Zdefiniuj funkcje write_bin_mat() i read_bin_mat() do zapisu/odczytu macierzy do/z pliku binarnego (nieformatowanego). 
Plik binarny ma być skonstruowany w ten sposób, że pierwsze dwa bajty kodują szerokość macierzy a dwa kolejne wysokość 
macierzy (liczba całkowita) a następnie jest sekwencja wszystkich elementów macierzy kodowanych na czterech bajtach każdy 
(liczba typu float).*/

#include <iostream>

struct Mat{
    int n, m;
    float **mat;

    /*Mat() {}

    Mat(const Mat &matr) : n(matr.n), m(matr.m), mat(matr.mat) {}*/
};

void write_bin_mat(const char *path, Mat matr){
    FILE* file = fopen(path, "wb");
    if(file == NULL){
        perror("Error");
        return;
    }
    short int arr[2] = {matr.n, matr.m};
    fwrite(arr, sizeof(short int), 2, file);
    fwrite(matr.mat, sizeof(float), matr.n * matr.m, file);
    fclose(file);
}

Mat read_bin_mat(const char *path){
    Mat matr;
    FILE* file = fopen(path, "rb");
    if(file == NULL){
        perror("Error");
    }
    //fscanf(file, "%d %d\n", &matr.n, &matr.m);
    /*for(int i = 0; i < matr.n; i++){
        for(int j =0; j < matr.m; j++){
            fscanf(file, "%f ", &matr.mat[i][j]);
        }
        fscanf(file, "\n");
    }*/
    short int arr[2];
    fread(arr, sizeof(short int), 2, file);
    matr.n = arr[0];
    matr.m = arr[1];
    fread(matr.mat, sizeof(float), matr.m * matr.n, file);
    fclose(file);
    return matr;
}

int main(){
    Mat mat;
    mat.m = 5;
    mat.n = 4;
    mat.mat = new float *[mat.n];
    for(int i = 0; i < mat.n; i++){
        mat.mat[i] = new float[mat.m];
        for(int j = 0; j < mat.m; j++){
            mat.mat[i][j] = i * j;
        }
    }
    write_bin_mat("C:\\Users\\user\\Documents\\matr.txt", mat);
    Mat matr;
    matr.m = 5;
    matr.n = 4;
    matr.mat = new float *[matr.n];
    for(int i = 0; i < matr.n; i++){
        matr.mat[i] = new float[mat.m];
    }
    matr = read_bin_mat("C:\\Users\\user\\Documents\\matr.txt");
    for(int i = 0; i < matr.n; i++){
        for(int j = 0; j < matr.m; j++){
            std::cout << matr.mat[i][j] << " ";
        }
        std::cout << "\n";   
    }
    for(int i = 0; i < matr.n; i++){
        delete[] matr.mat[i];
        delete[] mat.mat[i];
    }
    delete[] matr.mat;
    delete[] mat.mat;
    return 0;
}
