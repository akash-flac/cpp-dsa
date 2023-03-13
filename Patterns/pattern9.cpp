#include<iostream>
using namespace std;

int main(){

    int i = 1;
    while(i <= 8){
        int j = 0;
        while(j < i){
           cout << "*" ;
            j++;
        }

        j = 0;
        while(j <= (8-i)){
        cout << i+j  ;
        j++;
        }
        cout << endl;
    i++;
    }

    
}

/*
12345678
**2345678
***345678
****45678
*****5678
******678
*******78
********8
*/