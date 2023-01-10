#include <iostream>

int func(char m_array[], char s_array[]){
    for(int i = 0; m_array[i] != 0; i++){
        if(m_array[i] == s_array[0]){
            for(int j = 1; s_array[j] != 0, m_array[j] != 0; j++){
                if(m_array[i + j] != s_array[j]){
                    break;
                }
                if(s_array[j + 1] == 0){
                    return i;
                }
            }
        }
    }
    return 0;    
}

int main(){
    char a[] = "hestene snakker ikke kjott";
    char b[] = "snakker";
    std::cout << func(a, b);
    return 0;
}