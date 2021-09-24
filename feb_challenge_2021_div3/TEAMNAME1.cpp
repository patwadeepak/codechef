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

        unordered_set<char> letters;
        unordered_set<string> rest_letters;

        for(auto &x : words){
            letters.insert(x[0]);
            rest_letters.insert(x.substr(1,x.length()-1));
        }

        ll total_words =   letters.size()*rest_letters.size();
        ll new_words = total_words - n;

        cout << new_words*(new_words-1) << endl;
    }
}