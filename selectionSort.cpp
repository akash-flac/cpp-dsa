#include<iostream>
using namespace std;

int selectionSort(int arr[], int size)
{  
    for(int i = 0; i < size - 1; i++)
    {    
        int min = i;
        for( int j = i; j < size - 1; j++)
        {
        if (min > arr[j])
        swap(min, arr[j]);
        }
    return min;

    swap(arr[i], min); 
    }    
}

int main()
{
    int array[] = {12, 11, 5, 6, 3};
    cout << selectionSort(array, 5); 

}