#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>

bool comp(const void *a, const void *b){
 const char *x = (const char*)a;
 const char *y = (const char*)b;
 return (std::strcmp(x, y) < 0);
}

int main(){
 srand(time(NULL));
 unsigned int n, min_len, max_len;
 int len = 0;
 std::cin >> n >> min_len >> max_len;
 char **arr = new char *[n];
 for(int i = 0; i < n; i++){
  int size = min_len + rand() % (max_len);
  len += size + 1;
  arr[i] = new char[size + 1];
  for(int j = 0; j < size; j++){
   arr[i][j] = 97 + rand() % 25;
  }
 }
 std::sort(arr, arr + n, comp);
 for(int i = 0; i < n; i++){
  std::cout << arr[i] << "\n";
 }
 for(int i = 0; i < n; i++){
  delete[] arr[i];
 }
 delete[] arr;    
 return 0;
}