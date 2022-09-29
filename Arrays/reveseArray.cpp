#include<iostream>
using namespace std;

void reverseArray(int arr[], int length){
    int start = 0;
    int end = length - 1;
    while(start<=end){
    swap(arr[start], arr[end]);
    start++;
    end--;
    }
}

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] ;
    }
}


int main(){
    int a[5] = {1,2,3,4,5};
    reverseArray(a, 5);
    printArray(a, 5);

}