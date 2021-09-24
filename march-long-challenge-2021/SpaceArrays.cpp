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
typedef vector<int> vi;

void solve(){
    ll n; cin >> n;
    ll x, sum=0;

    vector<ll> a(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
        sum += i+1-a[i];
    }
    sort(a.begin(), a.end());
    bool result = true;

    for(ll i=0; i<n; i++){
        if(a[i] > i+1) result = false;
    }

    if(result){
        if(sum <= 0 || sum%2==0) result = false;
    }

    cout << ((result) ? "First" : "Second") << endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}