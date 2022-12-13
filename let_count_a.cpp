#include <iostream>

const int N = 52;


int main(){
  srand(time(NULL));
  char alphabet[N];
  for(int i = 0, j = 65; i < N/2; i++, j++){
    alphabet[i] = j;
  }
  for(int i = N/2, j = 97; i < N; i++, j++){
    alphabet[i] = j;
  }
  int m, n;
  std::cout << "words, letters";
  std::cin >> n >> m;
  for(int i = 0; i < n; i++){
    int size = (rand() % m) + 1;
    for(int j = 0; j < size; j++){
      int ind = rand() % N;
      std::cout << alphabet[ind];
    }
    std::cout << " ";
  }
  return 0;
}