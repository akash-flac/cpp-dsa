#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

Pair getMinMax(int arr[], int n){

    struct Pair minmax;
    if(n == 1){
        minmax.min = arr[0];
        minmax.max = arr[1];
        return minmax;
    }

    else
    {
    if(arr[0]<arr[1]){
        minmax.min = arr[0];
        minmax.max = arr[1];
    }

    else{
        minmax.min = arr[1];
        minmax.max = arr[0];
    }

    for(int i = 2; i < n; i++){
        if(arr[i] > minmax.max){
            minmax.max = arr[i];
        }

        if(arr[i] < minmax.min){
            minmax.min = arr[i];
        }
    }

    //cout << minmax.min << endl ;
    //cout << minmax.max << endl ;
    return minmax;

    }
}

int main(){

    int array[5] = {23, 2, 56, 45, 1};
    struct Pair minimaxi = getMinMax(array, 5);
    cout << "Min. Element :" << minimaxi.min << endl;
    cout << "Max. ELement :" << minimaxi.max << endl;

    return 0;

}