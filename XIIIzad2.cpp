/*Napisz klasę Mutex, której obiekty w każdym momencie są w jednym z dwóch stanów wolny lub zajęty. Bezpośrednio po utworzeniu 
obiekt typu Mutex powinien być w stanie wolny. Klasa powinna udostępniać następujące publiczne metody:
- lock(), której wywołanie zmienia stan mutexa z wolny na zajęty (w przypadku, gdy mutex jest już w stanie zajęty, 
metoda nie powinna zmieniać jego stanu),
- release(), której wywołanie zmienia stan mutexa z zajęty na wolny (w przypadku, gdy jest już w stanie wolny, 
metoda nie powinna zmieniać jego stanu),
- state() zwracającą wartość true gdy mutex jest w stanie wolny i false w przeciwnym wypadku.
Zadbaj o odpowiednią hermetyzację klasy i o prawidłową inicjalizację obiektów.
W programie głównym stwórz dynamiczną tablicę obiektów Mutex, automatyczną tablicę dynamicznych obiektów Mutex, 
dynamiczną tablicę dynamicznych obiektów Mutex oraz dwuwymiarową tablicę dynamiczną obiektów Mutex. Zadbaj o poprawne zwalnianie pamięci.
*/

#include <iostream>

class Mutex{
    bool state;
public:
    Mutex() : state(1) {}
    void lock(){
        if(state){
            state = 0;
        }
    }
    void release(){
        if(!state){
            state = 1;
        }
    }
    bool fstate(){
        return state;
    }
};

int main(){
    Mutex mutex;
    mutex.lock();
    std::cout << mutex.fstate();

    Mutex *arr0 = new Mutex[5];

    Mutex *arr1[5];
    for(int i = 0; i < 5; i++){
       arr1[i] = new Mutex; 
    }

    Mutex **arr2 = new Mutex*[5];
    for(int i = 0; i < 5; i++){
        arr2[i] = new Mutex;
    }

    Mutex **arr3 = new Mutex*[5];
    for(int i = 0; i < 5; i++){
        arr3[i] = new Mutex[5];
    }

    delete[] arr0;
    for(int i = 0; i < 5; i++){
        delete arr1[i];
        delete arr2[i];
        delete[] arr3[i];
    }
    delete[] arr2;
    delete[] arr3; 
    return 0;
}