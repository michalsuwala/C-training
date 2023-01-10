/*Zdefiniuj strukturę reprezentującą macierz o rozmiarze 3x3 liczb zmiennoprzecinkowych. 
Zdefiniuj funkcję print_mat() wypisującą na ekranie elementy tej macierzy.
Zdefiniuj funkcję add_mat() dodawania liczby do takiej macierzy; funkcja ma zwracać nowo obliczoną macierz. 
Napisz program testujący.*/

#include <iostream>

const int N = 3;

struct Matrix{
    float matrix[N][N];
};

void print_mat(const Matrix* m){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout << m -> matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
std::cout << "\n";
}

float** add_mat(const Matrix* m, float val){
    float **mat = new float *[N];
    for(int i = 0; i < N; i++){
        mat[i] = new float[N];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mat[i][j] = m -> matrix[i][j] + val;
        }
    }
    return mat;
}

void del_arr(float **arr){
    for(int i = 0; i < N; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

int main(){
    Matrix matrix;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix.matrix[i][j] = i + j;
        }
    }
    print_mat(&matrix);
    float **new_mat = add_mat(&matrix, 5);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout << new_mat[i][j] << " ";
        }
        std::cout << "\n";
    }
    del_arr(new_mat);
    return 0;
}