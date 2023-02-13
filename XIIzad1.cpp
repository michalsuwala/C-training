/*Napisz program, który zdefiniuje typ złożony Point reprezentujący punkt w dwuwymiarowej przestrzeni euklidesowej. 
Punkt powinien być opisany za pomocą dwóch współrzędnych. Zadeklaruj wszystkie pola klasy jako prywatne i dodaj odpowiednie akcesory. 
Zdefiniuj funkcję globalną do pobierania od użytkownika współrzędnych i wstawiania ich do obiektu klasy Point.
Wczytaj od użytkownika współrzędne dwóch punktów. 
Oblicz i wyświetl odległość pomiędzy tymi punktami - czy lepiej to zrobić w funkcji globalnej czy metodzie?*/

#include <iostream>
#include <cmath>

class Point{
	double x, y;
	public:
		double getX(){ return x; }
		double getY(){ return y; }
		void setX(double x) { this->x = x; }
    	void setY(double y) { this->y = y; }
};

Point get_points(){
	double x, y;
	std::cin >> x >> y;
	Point point;
	point.setX(x);
	point.setY(y);
	return point;
}

double dist(Point a, Point b){
	return std::sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) + (a.getY() - b.getY()) * (a.getY() - b.getY()));
}

int main(){
	Point point_a, point_b;
	point_a = get_points();
	point_b = get_points();
	std::cout << dist(point_a, point_b);
	return 0;
}