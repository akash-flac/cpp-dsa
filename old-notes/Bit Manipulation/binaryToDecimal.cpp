#include<iostream>
#include<math.h>
using namespace std;

int binaryToDecimal(int num){
    int digit, ans = 0, i = 0;

    while(num != 0)
    {  digit = num&1 ;
       ans = ((digit) * pow(2, i)) + ans;
       num = num/10; 
       i++;
    }

    return ans;
} 

int main()
{
    int n;
    cout << "Enter the binary number : ";
    cin >> n;
    cout << "Decimal Number : " << endl << binaryToDecimal(n) ; 

}