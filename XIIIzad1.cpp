/*Zaliczenie z pewnego przedmiotu wygląda tak, że studenci piszą dwa kolokwia, oba za 50 punktów. 
Ocena dostateczna przyznawana jest w przedziale (50-60] punktów, i rośnie o połowę oceny co 10 punktów aż do 100. 
Student, który nie otrzyma zaliczenia, może poprawić jedno z kolokwiów ale wtedy może otrzymać co najwyżej ocenę dostateczną. 
Zakładamy, że student, który nie otrzyma zaliczenia, zawsze będzie poprawiał kolokwium, które gorzej napisał.
Napisz klasę, w której znajduje się: numer indeksu studenta, wynik pierwszego kolokwium, wynik drugiego kolokwium i wynik poprawy. 
Numer indeksu musi być przekazany w konstruktorze klasy.  Wszystkie pola tej klasy mają być prywatne.
Napisz funkcję, która przyjmie tablicę obiektów takich klas a zwróci średnią ocen (nie punktów) zdobytych z tego przedmiotu. 
Tablicę w wynikami cząstkowymi zainicjuj pseudolosowo.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

class Tests{
    int index;
    int first_test;
    int second_test;
    int impr_test;
public:
    Tests() : index() {}
    Tests(int indx) : index(indx){
        index = indx;
        srand(time(NULL));
        first_test = 50 * rand() / RAND_MAX;
        second_test = 50 * rand() / RAND_MAX;
        if(first_test <= 25 || second_test <= 25){
            impr_test = 50 * rand() / RAND_MAX;
        }
    }
    float grade(){
        if(first_test <= 25 || second_test <= 25){
            if(first_test > second_test){
                if(first_test + impr_test >= 50){
                    return 3;
                }
                else{
                    return 2;
                }
            }
            else{
                if(second_test + impr_test >= 50){
                    return 3;
                }
                else{
                    return 2;
                }
            }
        }
        if(first_test + second_test < 60){
            return 3;
        }
        if(first_test + second_test < 70){
            return 3.5;
        }
        if(first_test + second_test < 80){
            return 4;
        }
        if(first_test + second_test < 90){
            return 4.5;
        }
        return 5;

    }
};

float score(Tests tests[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += tests[i].grade();
    }
    return (float)sum / n;
}

int main(){
    const int n = 150;
    Tests tests[n];
    std::cout << score(tests, n);
    return 0;
}