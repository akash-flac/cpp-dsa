#include<bits/stdc++.h>
using namespace std;
void Pair(){
        pair<int, int> p = {1,3};
        cout << p.first << " and " << p.second << endl;

        //nested pairs
        pair<int, pair<int, int>> q = {1, {2, 3}};
        cout<< q.first << " and " << q.second.first << " and " << q.second.second << endl ; 

        pair<int, int>arr[] = { {1,2}, {4,3}, {9,7}};
        cout << arr[1].second;

    }

    void Vector(){
        vector<int> v;
        v.push_back(1);
        v.emplace_back(3);
        cout << v[0] << " and " << v[1] << endl ;

        vector<int>w(4, 5);
        for(vector<int>::iterator it = w.begin(); it != w.end(); it++){          //......(1)
        cout << *(it) << " " ;
        }

        cout << endl ;

       
        for(auto it = w.begin(); it != w.end(); it++){       //......(2)
        cout << *(it) << " " ;
        }

        //Both (1) and (2) do the same thing. "auto" automatically assigns the vector iterator of correct data type

        cout << endl;

        for(auto it : w ){
            cout << it << " ";   //......(3)

        //(3) also does the same thing. A foreach loop is used here.
        }

        v.erase(v.begin(), v.end());
        cout << "v[0]" << v[0] << endl ;

        w.erase(w.begin(), w.end());
        cout << "w[0]" << w[0] << "w[1]" << w[1];
    }

    void Map(){
        map<int, int>mpp; //map<"key", "value">mpp

        mpp[1] = 2;
        mpp.emplace({3, 1});
        mpp.insert({2, 4});
        mpp[{2, 3}] = 10;

        for(auto it : mpp)
        {
            cout << it.first << " " << it.second << endl ;
        }
    }

int main(){

    //Pair();
    //Vector();

    
}