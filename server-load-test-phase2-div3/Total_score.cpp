#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<ll> vi;

void solve(){
    ll n, k; cin >> n >> k;
    vi a(k);
    for(auto &x : a) cin >> x;
    
    ll ans = 0;
    string x;
    for(ll i=0; i<n; i++){
        ans = 0;
        cin >> x;
        for(ll j=0; j<x.size(); j++){
            if(x[j] == '1') ans += a[j];
        }
        cout << ans << endl;
    }
}

int main(){
    FastIO
    ll t; cin >> t;
    while(t--){
        solve();
    }
}