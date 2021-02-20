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

        ll n, count=0; cin >> n;
        
        map<char, set<string>> wordmap;
        string w;
        for(int i=0; i<n; i++){
            cin >> w;
            auto it = wordmap.find(w[0]);
            if(it == wordmap.end()){
                wordmap[w[0]] = set<string>({w.substr(1, w.length()-1)});
            }
            else{
                wordmap[w[0]].insert(w.substr(1, w.length()-1));
            }
        } 
        set<string> s;
        for(auto it1=wordmap.begin(); it1!=wordmap.end(); it1++){
            auto it2=it1; it2++;
            for(; it2!=wordmap.end(); it2++){
                auto sit_end = set_union( (it1->second).begin(), (it1->second).end(),
                                          (it2->second).begin(), (it2->second).end(),
                                            s.begin());
                ll n_unique = s.size();
                count += (n_unique - (it1->second).size()) * (n_unique - (it2->second).size());
            }
        }

        cout << 2*count << "\n";
    }
}