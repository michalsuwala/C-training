#include <iostream>
#include <cstring>

void null_set(void *arr1, void *arr2, int n, int size){
 unsigned char *arr11 =  (unsigned char*)arr1;
 unsigned char *arr22 =  (unsigned char*)arr2;
 for(int i = 0; i < n * size; i += size){
  int f = std::memcmp(arr11 + i, arr22 + i, size);
  if(f == 0){
   std::memset(arr11 + i, 0, size);
   std::memset(arr22 + i, 0, size);
  }
 }
}

int main(){
 int n = 4;
 float arr1[n] = {8.0,9.3,10.7,11.0};
 float arr2[n] = {8.0,3.1,10.7,4.2};
 null_set(arr1, arr2, n, sizeof(float));
 for(int i = 0; i < n; i++){
  std::cout << arr1[i] << " ";
 }
 std::cout << "\n";
 for(int i = 0; i < n; i++){
  std::cout << arr2[i] << " ";
 }
 return 0;
}