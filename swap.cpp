#include <iostream>

void swap(void* a, void* b, int size){
    char temp;
    char *x = (char*)a;
    char *y = (char*)b;
    for(int i = 0; i < size; i++){
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }
}

int main(){
    int a = 7, b = 10;
    char c = 'w', d = '3';
    swap(&a, &b, sizeof(a));
    std::cout << a << "\t" << b << "\n";
    swap(&c, &d, sizeof(c));
    std::cout << c << "\t" << d;
    return 0;
}
