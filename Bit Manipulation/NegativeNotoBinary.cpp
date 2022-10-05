#include<iostream>
#include<math.h>
using namespace std;

int numberToBinary(int num)
{
    int digit, i = 0, ans = 0;

    while(num != 0){
        digit = num&1 ; //(digit = num%2;)
        ans = ((digit) * pow(10, i)) + ans ;
        cout << "answer in " << i << "th iteration : " << ans ;
        num = num>>1; //(num = num/2;)
        i++;
    }
    return ans ;
}

int main(){
cout << " Enter the number : " ;
int n ;
cin >> n ;
int num = abs(n);
cout << numberToBinary(num) << endl ;
 
   





}