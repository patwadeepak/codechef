#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll minOps(ll xi, ll yi, ll min_ops, vector<ll> &x, vector<ll> &y){
    ll ops = 0;
    for(ll i=0; i<x.size(); i++){
        if(!(x[i]==xi && y[i]==yi)){
            if( xi == x[i] || yi == y[i] || (abs(y[i] - yi) == abs(x[i] - xi))) 
                ops++;
            else 
                ops += 2;
        }
    }
    return min(ops, min_ops);
}

void solve() {
    ll n; cin >> n;
    vector<ll> x(n), y(n);
    for(ll i=0; i<n; i++) cin >> x[i];
    for(ll i=0; i<n; i++) cin >> y[i];

    ll min_ops = LONG_LONG_MAX;
    for(ll i=0; i<n-1; i++){
        min_ops = minOps(x[i], y[i], min_ops, x, y);
        for(ll j=i+1; j<n; j++){            
            min_ops = minOps(x[j], y[j], min_ops, x, y);
            min_ops = minOps(x[i], y[j], min_ops, x, y);
            min_ops = minOps(x[j], y[i], min_ops, x, y);
            ll xx, yy;

            if(abs(y[i]-y[j]) != abs(x[i]-x[j])){
                xx = y[i] - y[j] + x[i] + x[j];
                yy = y[i] + y[j] + x[i] - x[j];
                
                if(xx%2==0 && yy%2==0){
                    xx /=2;
                    yy /=2;
                    min_ops = minOps(xx, yy, min_ops, x, y);
                }

                xx = x[i] - y[i] + y[j] + x[j];
                yy = x[j] - x[i] + y[j] + y[i];
                if(xx%2==0 && yy%2==0){
                    xx /=2;
                    yy /=2;
                    min_ops = minOps(xx, yy, min_ops, x, y);
                }

            }
            min_ops = minOps(x[j], x[j]+y[i]-x[i], min_ops, x, y);
            min_ops = minOps(x[i], x[i]+y[j]-x[j], min_ops, x, y);
            min_ops = minOps(y[j]-y[i]+x[i], y[j], min_ops, x, y);
            min_ops = minOps(y[i]-y[j]+x[j], y[i], min_ops, x, y);
            min_ops = minOps(x[j], -x[j]+x[i]+y[i], min_ops, x, y);
            min_ops = minOps(x[i], -x[i]+x[j]+y[j], min_ops, x, y);
            min_ops = minOps(x[i]+y[i]-y[j], y[j], min_ops, x, y);
            min_ops = minOps(x[j]+y[j]-y[i], y[i], min_ops, x, y);
        }
    }
    cout << ((min_ops==INT_MAX) ? 0 : min_ops) << endl;
}

int main() {
    ll t; cin >> t;
    while(t--) solve(); 
}
