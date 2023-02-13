/*
Zdefiniuj klasę Complex służącą do przechowywania liczb zespolonych. 
Zdefiniowana klasa powinna zawierać pola im i re typu double służące do przechowywania odpowiednio części urojonej 
i rzeczywistej liczby zespolonej. Zdefiniuj metodę abs tej klasy, która zwróci moduł liczby zespolonej. 
Napisz funkcję add, która dostaje dwa argumenty typu complex zwraca jako wartość ich sumę. 
W funkcji głównej stwórz dwa dynamiczne obiekty typu Complex i przetestuj działanie zdefiniowanych funkcji.*/

#include <iostream>
#include <cmath>

class Complex{
    double im, re;
    public:
        void setIm(double x){ this->im = x; }
        void setRe(double y){ this->re = y; }
        double getIm(){ return this->im; }
        double getRe(){ return this->re; }
        double abs(){
            return sqrt(this->im * this->im + this->re * this->re);
        }
};

Complex add(Complex num0, Complex num1){
    Complex sum;
    sum.setIm(num0.getIm() + num1.getIm());
    sum.setRe(num0.getRe() + num1.getRe());
    return sum;
}