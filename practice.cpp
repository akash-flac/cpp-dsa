#include<iostream>
using namespace std;

int findUnique(int arr[], int length){
    
    int ans = 0;
    for(int i = 0; i < length; i++)
    {
       ans = ans^arr[i];
    }
    return ans;
}
//void printArray(int arr[], int length){
//    for(int i = 0; i < length; i++)
//    {
//        cout << arr[i] ;
//    }
//}


int main(){
    int a[5] = {1,1,2,5,5};
    cout << findUnique(a, 5) ;
    //printArray(a, 5);

}