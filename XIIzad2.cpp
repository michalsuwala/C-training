/*Dla klasy z poprzedniego zadania, w programie głównym utwórz: 
(1) obiekt automatyczny tej klasy, (2) obiekt dynamiczny, wskazywany wskaźnikiem, 
(3) tablicę automatyczną obiektów automatycznych, (4) tablicę automatyczną wskaźników na obiekty, 
zainicjuj te wskaźniki w dowolny sposób, (5) dynamiczną tablicę obiektów automatycznych, 
(6) dynamiczną tablicę wskaźników, zainicjuj te wskaźniki. 
Na końcu programu zwolnij pamięć dla wszystkich obiektów tworzonych dynamicznie. 
W każdym przypadku skorzystaj z publicznych metod tej klasy.*/

#include <iostream>

class Point{
	double x, y;
	public:
		double getX(){ return x; }
		double getY(){ return y; }
		void setX(double x) { this->x = x; }
    	void setY(double y) { this->y = y; }
};

int main(){
    Point point_a;
    Point* point_b = new Point;
    Point arr0[5];
    Point* arr1[6];
	Point* arr2 = new Point[7];
	Point** arr3 = new Point*[8];
	delete point_b;
	delete[] arr2;
	delete[] arr3;
	return 0;
}