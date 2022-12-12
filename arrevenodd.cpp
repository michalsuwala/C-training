/*Napisz program, który utworzy n-elementową tablicę liczb całkowitych i zapełni ją danymi. 
Program powinien zmodyfikować zawartość tablicy tak, aby liczby parzyste znalazły się w początkowej, 
a liczby nieparzyste w końcowej części tablicy. Kolejność liczb w ramach grupy parzystych i nieparzystych 
jest dowolna.
*/
#include <iostream>

void func(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] % 2 != 0 && arr[j+1] % 2 == 0){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    func(arr, n);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << "\t";
    }
    return 0;
}