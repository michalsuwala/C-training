 #include <iostream>

float mul(float a, float b){
   return a * b;
}

float amin(float a, float b){
if(a < b){
   return a;
}
   return b;
}

void reduce(float *arr, float *arr_l, float *res, float(*func)(float, float)){
    for(int i = 0; arr + i != arr_l; i++){
        *(res + i) = func(*(arr + i), *(arr_l - i - 1));
    }
}

int main(){
    int n = 6;
    float *arr = new float [n]{1,8,4,7,9,2};
    float *arr1 = new float[n / 2]; 
    float *arr2 = new float[n / 2];
    reduce(arr, arr + n, arr1, mul);
    reduce(arr, arr + n, arr2, amin);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    for(int i = 0; i < n / 2; i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n";
    for(int i = 0; i < n / 2; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << "\n";
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    return 0;
}