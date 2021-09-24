#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

int main(){
    FastIO
    
    // Solution start here
    
    int n;
    cin >> n;
    vector<ll> a(n); 
    for(ll& x : a) cin >> x;
    sort(a.begin(), a.end());

    ll high = a[0]*n;
    for(int i=1; i < n; i++){
        ll calc_value = a[i]*(n-i);
        if (calc_value > high){
            high = calc_value;
        }
    }
    cout << high;
    // solution end here

    return 0;
}