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
        
        map<char, set<int>> wordmap;
        string w, body;
        int j = 0;
        unordered_set<string> myset;
        for(int i=0; i<n; i++){
            cin >> w;
            body = w.substr(1, w.length()-1);
            if(myset.find(body) == myset.end()){
                j++;
                myset.insert(body);
            }
            auto it = wordmap.find(w[0]);
            if(it == wordmap.end()){
                wordmap[w[0]] = set<int>({j});
            }
            else{
                wordmap[w[0]].insert(j);
            }
        }
        // set<string> s;
        for(auto it1=wordmap.begin(); it1!=wordmap.end(); it1++){
            auto it2=it1; it2++;
            for(; it2!=wordmap.end(); it2++){
                auto s1 = it1->second, s2 = it2->second;
                for(int x : s2) s1.insert(x);
                ll n_unique = s1.size();
                count += (n_unique - (it1->second).size()) * (n_unique - (it2->second).size());
            }
        }

        cout << 2*count << "\n";
    }
}