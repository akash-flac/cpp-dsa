#include<iostream>
#include<math.h>
using namespace std;

int decimalToBinary(int num)
{
    int digit, i = 0, ans = 0;

    while(num != 0){
        digit = num&1 ; //(digit = num%2;)
        ans = (digit * pow(10, i)) + ans ;
        num = num>>1; //(num = num/2;)
        i++;
    }
    return ans ;
}

int main(){
int n ;
cout << " Enter the number : " ;
cin >> n ;
int num = abs(n);
cout << decimalToBinary(num) << endl ;
}