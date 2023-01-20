#include <iostream>

void gen_mat(float **matr, int n){
 for(int i = 0; i < n; i++){
  for(int j = 0; j < i * i + 1; j++){
   matr[i][j] = float(i + j) / 2;
  }
 }
}

int main(){
 int n;
 std::cin >> n;
 float **matr = new float *[n];
 for(int i = 0; i < n; i++){
  matr[i] = new float[i * i + 1];
 }
 gen_mat(matr, n);
 for(int i = 0; i < n; i++){
  for(int j = 0; j < i * i + 1; j++){
   std::cout << matr[i][j] << " ";
  }
  std::cout << "\n";
 }
 for(int i = 0; i < n; i++){
  delete[] matr[i];
 }
 delete[] matr;
 return 0;
}