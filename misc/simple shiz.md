```
sort(arr, arr + n, greater<int>());

```

- here, this will get me the wrong output. if i wanna create a frequency map of this string, then in "auto i : s", i already accounts for the current character, 
```
//and so it should be "map[i]" instead.
for(auto i : s){

            map[s[i]]++;

        }
        
       OR
       
for(int i=0; i<s.size(); i++){

            map[s[i]]++;

        }
```

