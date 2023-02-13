/*Zaprojektuj i zaimplementuj klasę Array realizującą funkcjonalność dynamicznej tablicy (typu int).  W klasie zdefiniuj metody:
- konstruktory - domyślny, inicjujący, kopiujący
- int& at(int i) - zwracającą referencję na i-ty element tablicy,
- void append(int v) - dodającą element na koniec tablicy,
- void insert(int i, int v) - wstawiającą element v za i-tym elementem,
- void resize(int size) - zmieniającą rozmiar tablicy na nowy, zachowując elementy już dodane do tablicy,
- int size() - zwracającą rozmiar tablicy,
- void clear() - czyszczącą całą zawartość obiektu.
 Napisz program, w którym przetestujesz implementację tej klasy.*/

 #include <iostream>

 class Array{
    int *arr;
    int n;
public:
    Array() {}
    Array(int *arr, int n) : arr(arr), n(n) {}
    Array(const Array &array) : arr(array.arr), n(array.n) {}
    ~Array() {
        delete[] arr;
    }
    int& at(int i){
        return *(arr + i);
    }
    void append(int v){
        int *temp = new int[n + 1];
        for(int i = 0; i < n; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = new int[n + 1];
        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }
        arr[n] = v;
        delete[] temp;
        n++;
        /*resize(n + 1);
        arr[n] = v;
        n++;*/
    }
    void insert(int j, int v){
        int *temp = new int[n + 1];
        for(int i = 0; i < j; i++){
            temp[i] = arr[i];
        }
        temp[j] = v;
        for(int i = j + 1; i < n + 1; i++){
            temp[i] = arr[i - 1];
        }
        delete[] arr;
        arr = new int[n + 1];
        for(int i = 0; i < n + 1; i++){
            arr[i] = temp[i];
        }
        delete[] temp;
        n++;
    }
    void resize(int size){
        int *temp = new int[size];
        int elements = (size < n) ? size : n;
        for(int i = 0; i < elements; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        n = size;
    }
    int size(){
        return n;
    }
    
 };

 int main(){
    int n = 5;
    int *arr = new int[n]{1,2,3,4,5};
    Array array(arr, n);
    std::cout << array.at(2) << "\n";
    array.append(6);
    std::cout << array.at(5) << "\n";
    array.insert(1, 9);
    std::cout << array.at(1) << " " << array.at(2) << "\n";
    array.resize(8);
    std::cout << array.at(1) << " " << array.size();
    delete[] arr;
    return 0;
 }