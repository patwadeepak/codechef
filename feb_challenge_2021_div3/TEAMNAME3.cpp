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
        
        unordered_set<string> full_word;
        unordered_set<string> words;
        unordered_set<char> letters;
        string w;
        for(int i=0; i<n; i++){
            cin >> w;
            full_word.insert(w);
            words.insert(w.substr(1, w.length()-1));
            letters.insert(w[0]);
        }

        ll count = 0;
        unordered_set<string>::iterator wit1, wit2, present_a, present_b;
        unordered_set<char>::iterator lit1, lit2;
        string a,b;
        // Naive solution
        wit1 = words.begin(); wit2 = words.begin(); wit2++;
        for(; wit2!=words.end(); wit1++,wit2++){
            lit1 = letters.begin();
            for(; lit1 != letters.end(); lit1++){
                lit2 = lit1; lit2++;
                for(; lit2 != letters.end(); lit2++){
                    a = (*lit1)+(*wit1);
                    b = (*lit2)+(*wit2);
                    present_a = full_word.find(a);
                    if(present_a == full_word.end()){
                        present_b = full_word.find(b);
                        if(present_b == full_word.end())
                            count++;
                    }
                    a = (*lit1)+(*wit2);
                    b = (*lit2)+(*wit1);
                    present_a = full_word.find(a);
                    if(present_a == full_word.end()){
                        present_b = full_word.find(b);
                        if(present_b == full_word.end())
                            count++;
                    }
                }
            }
        }
        cout << 2*count << "\n";
    }
}