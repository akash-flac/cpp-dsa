#include<iostream>
using namespace std;

int main(){
    int n ;
    cout << "Enter the value of n" << endl ;
    cin >> n ;

    bool isPrime = 1;

    for(int i = 2 ; i < n ; i++){

        //if rem=0, not a prime
        if(n%i == 0){
            isPrime = 0;
            break;
        }
    }

    if(isPrime == 0){

        cout << "Not a prime number" << endl ;
    }
    else{
        cout << n << " is a prime number" << endl ;
    }


}