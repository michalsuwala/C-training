#include <iostream>
#include <cmath>

int func(int n, float x[], float y[], float z[], float r, float xx, float yy){
    int index = 0;
    int dis = sqrt(pow((xx - x[0]), 2) + pow((yy - y[0]), 2));
    int closer = sqrt(pow(z[0], 2) + pow(dis, 2));
    for(int i = 1; i < n; i++){
        dis = sqrt(pow((xx - x[i]), 2) + pow((yy - y[i]), 2));
        int temp = sqrt(pow(z[i], 2) + pow(dis, 2));
        if(temp < closer){
            closer = temp;
            index = i;
        }
    }
    if(closer > r){
        return -1;
    }
    else{
        return index;
    }
}

int main(){
    int n = 6;
    float x[n] = {2,2,3,5,6,8}, y[n] = {2,6,3,7,1,6}, z[n] = {2,1,1.5,2,2,2};
    float r = 2.5, xx = 7, yy = 2;
    std::cout << func(n, x, y, z, r, xx, yy);
    return 0;
}
