#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

int main(){
    FastIO
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll lowest = 1e9 + 1, highest = -1e9 - 1, value=0;
        for(ll i=0; i<n; i++){
            cin >> value;
            if (highest < value)
                highest = value;
            if (lowest > value)
                lowest = value;
        }
        cout << 2*abs(highest - lowest) << "\n";
    }
}