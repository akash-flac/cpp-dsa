#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    
    while((n-i)>0)
    {
       int j = 0 ;
       while(j<(n-i))
       {
       cout << " " ;
       j++;
       }
       
       j = 0;
       while(j < i )
        {
            cout << "#" ; 
            j++;
        }

       cout << endl;
       i++;
    }
    
    
}
