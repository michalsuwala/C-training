#include <iostream>

void digit2letter(char arr[]){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] >= 49 && arr[i] < 59){
            arr[i] = 97 + arr[i] - 48;
        }
    }
}

int main(){
    int n = 11;
    char arr[n] = "ab62CD13aZ";
    digit2letter(arr);
    for(int i = 0; arr[i] != '\0'; i++){
        std::cout << arr[i];
    }
    return 0;
}