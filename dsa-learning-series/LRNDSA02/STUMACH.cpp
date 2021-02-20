#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

int main(){
    FastIO
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        set<pair<ll,ll>> box;
        ll s;
        for(ll i=0; i<n; i++){
            cin >> s;
            box.insert({s,i});
        }

        ll min_cap = 0, pos = n, sum=0, last_index=n;
        for(auto it=box.begin(); it != box.end(); it++){
            if (pos >= it->second){
                sum += (it->first - min_cap)*pos;
                pos = it->second;
                min_cap = it->first;
            }
        }
        cout << sum << "\n";
    }    
}