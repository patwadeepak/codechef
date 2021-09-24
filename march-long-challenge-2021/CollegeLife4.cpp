#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

ll minPrice(ll n, ll e, ll h, ll a, ll b, ll c){
    
    double ymaxi = min(h/3.0, (double)min(n, e+h-2*n));
    ll xmax = min(e/2, min(n, (ll)round((e-h+3*ymaxi)/2)));
    ll ymax = (ll)ymaxi;
    ll zmax = min(e, min(h, n));
    if(xmax < 0 || ymax < 0 || zmax < 0) return -1;

    ll xmin = max(n - ymax - zmax, (ll)0);
    ll ymin = max(n - xmax - zmax, (ll)0);
    ll zmin = max(n - xmax - ymax, (ll)0);

    n -= xmin + ymin + zmin;
    ll sum = xmin*a + ymin*b + zmin*c;

    vector<vector<ll>> price = {{a, xmax-xmin}, {b, ymax-ymin}, {c, zmax-zmin}};
    sort(price.begin(), price.end());
    ll val = min(n, price[0][1]);
    sum += price[0][0]*val;
    n -= val;
    int i=1;
    while(n){
        ll val = min(n, price[i][1]);
        sum += price[i][0]*val;
        n -= val;
        i++;
    }
    return sum;
}

void solve(){
    int n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    ll result = minPrice(n, e, h, a, b, c);
    cout << result << endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}