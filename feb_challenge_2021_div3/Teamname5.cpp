#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
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
        
        vector<string> full_words;
        map<char, int> letters;
        map<string, int> words;
        set<pair<int,int>> wordnum;
        string w;
        for(int i=0; i<n; i++){
            cin >> w;
            full_words.push_back(w);

            if(letters.find(w[0]) == letters.end())
                letters[w[0]] = i;

            if(words.find(w.substr(1, w.length()-1)) == words.end())
                words[w.substr(1, w.length()-1)] = i;
            
            wordnum.insert({letters[w[0]], words[w.substr(1, w.length()-1)]});
        }
        ll count = 0;

        set<pair<int,int>>::iterator it, it2, present_a, present_b, not_found=wordnum.end();
        pair<int,int> a,b;
        // Naive solution
        for(it = wordnum.begin(); it!=not_found; it++){
            it2=it;it2++;
            for(; it2 != not_found; it2++){
                if(it->first != it2->first && it->second != it2->second){
                    a = make_pair(it->first, it2->second);
                    b = make_pair(it2->first, it->second);
                    present_a = wordnum.find(a);
                    if(present_a == not_found){
                        present_b = wordnum.find(b);
                        if(present_b == not_found)
                            count++;
                    }
                }
            }
        }
        cout << 2*count << "\n";
    }
}