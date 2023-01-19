#include <iostream>
#include <algorithm>

void func(char names[][100], float arr[], int n){
    for(int i = 0; i < 2 * n - 2; i += 2){
        for(int j = 0; j < 2 * n - i - 2; j += 2){
            if(arr[j] > arr[j + 2]){
                std::swap(arr[j], arr[j + 2]);
                std::swap(arr[j + 1], arr[j + 3]);
                std::swap(names[j / 2], names[(j + 2) / 2]);
            }
            else if(arr[j] == arr[j + 2]){
                if(arr[j + 1] > arr[j + 3]){
                    std::swap(arr[j], arr[j + 2]);
                    std::swap(arr[j + 1], arr[j + 3]);
                    std::swap(names[j / 2], names[(j + 2) / 2]);
                }
            }
        }
    }
}

int main(){
    int n = 3;
    float arr[2 * n] = {1.2, 6.1, 1.2, 1.1, 5.4, 3.1};

    char names[n][100] = {"Alfa", "Omega", "Sigma"};
    func(names, arr, n);
    for(int i = 0; i < n; i++){
        std::cout << names[i] << "\n";
    }
    return 0;
}