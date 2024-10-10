#include<iostream>
using namespace std;

void swapArray(int arr[], int length){
    
    int start = 0;

    while(start+1 < (length) ){
    swap(arr[start], arr[start+1]);
    start = start + 2;
    }
}

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] ;
    }
}


int main(){
    int a[6] = {1,2,3,4,5,6};
    swapArray(a, 6);
    printArray(a, 6);

}