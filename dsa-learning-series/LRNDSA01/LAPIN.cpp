#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    FastIO
    
    // Solution start here
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int left[26] = {0}, right[26] = {0};

        double len = s.length();
        double pivot = (len-1)/2;
        
        for(int i = 0; i<len; i++){
            if(i < pivot)
                left[int(s[i])-int('a')] += 1;
            else if (i > pivot)
                right[int(s[i]-int('a'))] += 1;
        }

        bool yes = false;
        for(int i = 0; i<26; i++){
            if (left[i] != right[i]){
                yes = false;
                break;
            }                
            else
                yes = true;
        }

        cout << (yes ? "YES" : "NO") << "\n";
    }

    // solution end here

    return 0;
}