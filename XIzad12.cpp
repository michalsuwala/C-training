/*Zdefiniuj strukturę Task, która będzie się składała z pół: (1) nazwa zadania (c-string), 
(2) priorytet zadania (int), wskaźnik run na funkcję realizującą zadanie 
- funkcja ma przyjmować w parametrze napis c-string i liczbę typu int i zwracać void. 
Stwórz pomocniczą funkcję o identycznym nagłówku 'void print(const char*, int)', 
która wyświetli na ekranie podany w parametrze napis i liczbę.
Utwórz dynamiczną n-elementową tablicę wskaźników do obiektów typu Task. 
Zainicjuj wszystkie elementy tej tablicy, a wskaźnik run ustaw na funkcję print().
Z pomocą funkcji z biblioteki <algorithm>:
- posortuj zadania rosnąco względem priorytetu;
- posortuj zadania malejąco względem nazwy zadania;
- dla każdego obiektu z tablicy za pomocą wskaźnika run wywołaj funkcję, na którą wskazuje.*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int N = 20;

struct Task{
    char *task_def;
    int task_imp;
    void (*run)(const char *str, int num);
};

void print(const char *str, int num){
    for(int i = 0; *(str + i) != 0; i++){
        std::cout << *(str + i);
    }
    std::cout << "\n" << num << "\n";
}

bool comp(const Task* t, const Task* r){
    for(int i = 0; (t->task_def + i) != 0 && (r->task_def + i); i++){
        if((t->task_def + i) > (r->task_def + i)){
            return 1;
        }
    }
    return 0;
}

bool compi(const Task* t, const Task* r){
    return t->task_imp < r->task_imp;
}

int main(){
    srand(time(NULL));
    Task *tasks[N];
    for(int i = 0; i < N; i++){
        tasks[i] = new Task;
        tasks[i]->run = *print;
        tasks[i]->task_imp = 20 * rand()/RAND_MAX;
        //char temp[N][N];
        char *temp = new char[20];
        for(int j = 0; j < N - 1; j++){
            temp[j] = 97 + 25 * rand()/RAND_MAX;
        }
        //temp[i][N - 1] = 0;
        temp[N - 1] = 0;
        tasks[i]->task_def = temp; 
    }
    std::sort(tasks, tasks + N, comp);
    std::sort(tasks, tasks + N, compi);
    for(int i = 0; i < N; i++){
        tasks[i]->run(tasks[i]->task_def, tasks[i]->task_imp);
    }

    return 0;
}
