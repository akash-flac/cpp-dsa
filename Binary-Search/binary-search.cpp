#include<iostream>
using namespace std;

int binarysearch(int ar[], int size, int key)
{   
    int s = 0;
    int e = size-1;
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

        int mid = (s+e)/2;
    }

    return -1; 
}

int main()
{
   int arr[] = {1, 5, 7, 9, 11};//15, 20, 45, 50, 52, 58, 60, 70, 85, 100};
   cout << "mai to chal raha hi";
   cout << " Index of the given elemnt is " << binarysearch(arr, 5, 7) << endl;
}
