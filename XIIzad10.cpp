/*Zdefiniuj strukturę vec2d, składającą się z dwóch pół x i y typu zmiennoprzecinkowego, która będzie reprezentowała wektor dwuwymiarowy. 
Utwórz tablicę automatyczną obiektów tego typu. Z pomocą funkcji z biblioteki <algorithm>:
- wypełnij tę tablicę wektorami, których poszczególne współrzędne spełniają zależność: 
x jest liczbą pseudolosową z zakresu domkniętego <-1, 1> a y jest liczbą przeciwną do x (std::generate);
- wypisz na ekranie wszystkie elementy tej tablicy (std::for_each);
- posortuj wszystkie wektory w tablicy malejąco względem współrzędnej y (std::sort);
- znajdź wektor o najmniejszej współrzędnej x (std::min_element).*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct vec2d{
    float x, y;
};

int main(){
    srand(time(NULL));
    int n = 10;
    vec2d vects[n];
    std::generate(vects, vects + n, [&]{
        vec2d v;
        v.x = -1 + 2 * float(rand())/RAND_MAX;
        v.y = -v.x;
        return v;
    });
    std::sort(vects, vects + n, [](const vec2d a, const vec2d b){
        return a.y > b.y;
    });
    std::for_each(vects, vects + n, [](const vec2d v){
        std::cout << v.x << " " << v.y << "\n";
    });
    vec2d *min;
    min = std::min_element(vects, vects + n, [](const vec2d a, const vec2d b){
        return a.x < b.x;
    });
    std::cout << min->x;
    return 0;
}
