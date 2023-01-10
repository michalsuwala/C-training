/*Zdefiniuj strukturę vec2d, składającą się z dwóch pół x i y typu zmiennoprzecinkowego, 
która będzie reprezentowała wektor dwuwymiarowy. Utwórz tablicę automatyczną obiektów tego typu. 
Z pomocą funkcji z biblioteki <algorithm>:
- wypełnij tę tablicę wektorami, których poszczególne współrzędne spełniają zależność: 
x jest liczbą pseudolosową z zakresu domkniętego <-1, 1> a y jest liczbą przeciwną do x;
- wypisz na ekranie wszystkie elementy tej tablicy;
- posortuj wszystkie wektory w tablicy malejąco względem współrzędnej y;
- znajdź wektor o najmniejszej współrzędnej x.*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int N = 7;

struct Vec2d{
    float x, y;
};

void add_xy(Vec2d* v){
    float x = -1 + 2 * float(rand())/RAND_MAX;
    v->x = x;
    v->y = 1.0f / x;
}

void print_v(const Vec2d* v){
    printf("%f %f\n", v->x, v->y);
}

float comp_y(const Vec2d* v, const Vec2d* w){
    return w->y < v->y;
}

float comp_x(const Vec2d* v, const Vec2d* w){
    return v->x < w->x;
}

int main(){
    srand(time(NULL));
    Vec2d *vec2d[N];
    for(int i = 0; i < N; i++){
        vec2d[i] = new Vec2d;
    }
    std::for_each(vec2d, vec2d + N, add_xy);
    std::for_each(vec2d, vec2d + N, print_v);

    std::sort(vec2d, vec2d + N, comp_y);
    std::cout << "\n";
    std::for_each(vec2d, vec2d + N, print_v);
    
    Vec2d *vec_min = new Vec2d;
    vec_min = *(std::min_element(vec2d, vec2d + N, comp_x));
    std::cout << "\n";
    print_v(vec_min);
    return 0;
}