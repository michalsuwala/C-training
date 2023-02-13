/*Napisz funkcję, która otrzymuje jako argumenty tablice points1 i points2 o argumentach typu Point  
i przepisuje zwartość tablicy points1 do tablicy points2. */

#include <iostream>

class Point{
	double x, y;
	public:
		double getX(){ return x; }
		double getY(){ return y; }
		void setX(double x) { this->x = x; }
    	void setY(double y) { this->y = y; }
};

void point_cpy(Point points1[], Point points2[], int n){
    for(int i = 0; i < n; i++){
        points2[i].setX(points1[i].getX());
        points2[i].setY(points1[i].getY());
    }
}