#include<iostream>
using namespace std;

int binarysearch(int ar[], int size, int key)
{   
    int s = ar[0];
    int e = ar[size-1];
    int mid = (s+e)/2 ;
    while(s <= e)
    { 
        if( key == ar[mid])
        {
            return mid; 
        }        

        else if( key < ar[mid] )
        {
            e = mid-1;
        }
        
        else 
        {
            s = mid + 1;
        }

        mid = (s+e)/2;
    }

    return -1; 
}

int main()
{
   int arr[] = {1, 5, 7, 9, 11};
   cout << " Index of the given elemnt is " << binarysearch(arr, 5, 7);
}
