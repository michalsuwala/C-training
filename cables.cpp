#include <iostream>

bool func(int n, int positive, int negative, int cables[], int n_cables){
    int pos, neg;
    bool result = 1;
    for(int i = 0; i < n_cables; i += 2){
        if(cables[i] > cables[i + 1]){
            int temp = cables[i];
            cables[i] = cables[i + 1];
            cables[i + 1] = temp;
        }
    }
    for(int i = 0; i < n_cables - 2; i += 2){
        for(int j = 0; j < n_cables - i - 2; j += 2){
            if(cables[j] > cables[j + 2]){
                int temp1 = cables[j], temp2 = cables[j + 1];
                cables[j] = cables[j + 2];
                cables[j + 1] = cables[j + 3];
                cables[j + 2] = temp1;
                cables[j + 3] = temp2;
            }
        }
    }
    for(int i = 0; i < n_cables; i += 2){
        if(cables[i + 1] == positive){
            pos = i + 1;
        }
        if(cables[i] == negative){
            neg = i;
        }
    }
    for(int i = neg + 1; i < pos - 1;){
        if(result == 0){
            return result;
            break;
        }
        result = 0;
        for(int j = i + 1; j < pos; j += 2){
            if(cables[i] == cables[j]){
                i = j + 1;
                result = 1;
            }
        }
    }
    return result;
}

int main(){
    int n = 8, positive = 6, negative = 1, cables[n] = {0, 1, 2, 1, 2, 3, 3, 5, 6, 5}, n_cables = 10;
    std::cout << func(n, positive, negative, cables, n_cables);
    return 0;
}