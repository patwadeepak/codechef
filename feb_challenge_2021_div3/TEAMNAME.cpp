#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;

int main(){
    FastIO
    ll t; cin >> t;
    while(t--){

        ll n; cin >> n;
        
        vector<string> words;
        string w;
        for(int i=0; i<n; i++){
            cin >> w;
            words.push_back(w);
        }

        uniordered_set<char> letters;
        unordered_set<string> rest_letters;

        for(auto &x : words){
            letters.insert(x[0]);
            rest_letters.insert(x.substr(1,x.length()-1));
        }
        cout << letters.size() <<" " << rest_letters.size() << endl;

        // for(auto &x : words) cout << x << " "; cout << endl;

        // unique letters
        // string first_char;
        // for(auto &x : words){
        //     first_char += x[0];
        //     for(int i=0; i<first_char.length(); i++){
                
        //     }
        // }
        
        // count num of different words
        // hell bell best test
        // h,b,t
        // h - hest
        // b - 
        // t - tell
        // 2
        // check if n > 2.
        // nC2 = 2C2 = 1
        // multiply by 2 for repetitions

        // 3x2 + 2x1
        // 6 + 2 = 8 
        // 8 - 4 = 4
        // 4/2 = 2
    }
}