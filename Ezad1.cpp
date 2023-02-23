#include <iostream>

unsigned short int *find_subset(unsigned short int *arr, int n, bool (*func)(unsigned short int *, int), int &num){
    num = 0;
    unsigned short int* res = nullptr;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            unsigned short int *arr2 = new unsigned short int[j - i];
            for(int k = 0; k < j - i; k++){
                arr2[k] = arr[i + k];    
            }
            if(func(arr2, j - i)){
                if(j - i > num){
                    num = j - i;
                    res = arr2;
                }
            }
            else{
                delete[] arr2;
            }
        }
    }
    return res;
}


bool incr(unsigned short int *arr, int n){
    bool f = 1;
    unsigned short int temp = arr[0];
    for(int i = 1; i < n; i++){
        if(temp >= arr[i]){
            f = 0;
            return f;
        }
        temp = arr[i];   
    }
    return f;
}


bool zero_bits(unsigned short int *arr, int n){
    bool f = 1;
    unsigned short int num;
    for(int i = 0; i < n; i++){
        num = arr[i];
        if((num >> 1) ^ 1 != 0){
            f = 0;
            return f;
        }
        while(num >> 2){
            if(num ^ 1 != 0){
            f = 0;
            return f;
        }
        }
    }
    return f;
}

int main(){
    int n = 10;
    int num;
    unsigned short int arr[n] = {1,2,5,2,2,10,11,12,8,3};
    unsigned short int *res;
    res = find_subset(arr, n, incr, num);
    if(res == nullptr){
        return -1;
    }
    for(int i = 0; i < num; i++){
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
    res = find_subset(arr, n, zero_bits, num);
    for(int i = 0; i < num; i++){
        std::cout << res[i] << " ";
    }
    delete[] res;
    return 0;
}