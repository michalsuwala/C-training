#include <iostream>

void func(char arr[]){
    int n = 0, m = 0, o = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        bool f = 1;
        for(int j = i + 1; arr[j] != '\0'; j++){
            if(arr[j] == arr[i]){
                f = 0;
            }
        }
        if(f == 1){
            n++;
        }
    }
    char arr1[n];
    int arr2[n];
    for(int i = 0; i < n; i++){
        arr2[i] = 1;
    }
    for(int i = 0; arr[i] != '\0'; i++){
        bool f = 1;
        for(int j = i + 1; arr[j] != '\0'; j++){
            if(arr[j] == arr[i]){
                f = 0;
                arr2[m]++;
            }
        }
        if(f == 1){
            arr1[m] = arr[i];
            m++;
            }
        }
    
    for(int i = 0; i < n; i++){
        std::cout << arr1[i] << ": " << arr2[i] << "\n";
    }
}

int main(){
    char arr[] = "hytta";
    func(arr);
    return 0;
}