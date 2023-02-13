/*Napisz program, który zapisze do pliku 10 dowolnych liczb całkowitych.*/

#include <iostream>

int main(){
    FILE* file = fopen("C:\\Users\\user\\Documents\\nums.txt", "wb");

    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    for(int i = 0; i < 10; i++){
    fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
    return 0;
}

