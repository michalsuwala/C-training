/*Napisz funkcję pointsInCircle() , która przyjmuje tablicę typu Point oraz trzy liczby rzeczywiste a, b i r, 
będące parametrami  równania okręgu (x - a)^2 + (y - b)^2 = r^2. Funkcja powinna zwrócić, za pomocą argumentu, 
wskaźnik na tablicę wskaźników na punkty położone w zdefiniowanym kole. 
W funkcji głównej stwórz testową tablicę punktów wygenerowaną pseudolosowo i przetestuj funkcję pointsInCircle(). */

#include <iostream>
#include <cstdlib>
#include <ctime>

class Point{
	double x, y;
	public:
		double getX(){ return x; }
		double getY(){ return y; }
		void setX(double x) { this->x = x; }
    	void setY(double y) { this->y = y; }
};

Point **pointsInCircle(Point point[], double a, double b, double r, int n){
    int len = 0;
    for(int i = 0; i < n; i++){
        if((point[i].getX() - a) * (point[i].getX() - a) + (point[i].getY() - b) * (point[i].getY() - b) <= r * r){
            len++;
        }   
    }
    Point **points1 = new Point* [len];
    for(int i = 0, j = 0; j < len; i++){
        if((point[i].getX() - a) * (point[i].getX() - a) + (point[i].getY() - b) * (point[i].getY() - b) <= r * r){
            points1[j] = new Point;
            points1[j]->setX(point[i].getX()); 
            points1[j]->setY(point[i].getY()); 
            j++;
        }   
    }

    return points1;
}

int main(){
    srand(time(NULL));
    int n = 100;
    Point points[n];
    for(int i = 0; i < n; i++){
        points->setX(10 * double(rand())/RAND_MAX);
        points->setY(10 * double(rand())/RAND_MAX);
    } 
    Point **points1 = pointsInCircle(points, 3.0, 3.0, 4.0, n);
    std::cout << points1[0]->getX() << " " << points1[0]->getY();
    delete[] points1;
    return 0;
}