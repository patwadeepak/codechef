#include <bits/stdc++.h>

using namespace std;

int minOps(int xi, int yi, int min_ops, vector<int> &x, vector<int> &y){
    int ops = 0;
    for(int i=0; i<x.size(); i++){
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
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) cin >> y[i];

    int min_ops = INT_MAX;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(x[i] == x[j]){
                for(int k=min(y[i], y[j]); k<=max(y[i], y[j]); k++)
                    min_ops = minOps(x[i], k, min_ops, x, y);
            }
            else if(y[i] == y[j]){
                for(int k=min(x[i], x[j]); k<=max(x[i], x[j]); k++)
                    min_ops = minOps(k, y[i], min_ops, x, y);
            }
            else if(y[i] - y[j] == x[i] - x[j]){
                int c = y[i] - x[i];
                for(int k=min(x[i], x[j]); k<=max(x[i],x[k]); k++)
                    min_ops = minOps(k, k + c, min_ops, x, y);
            }
            else if(y[i] - y[j] == x[j] - x[i]){
                int c = y[i] + x[i];
                for(int k=min(x[i], x[j]); k<=max(x[i],x[k]); k++)
                    min_ops = minOps(k, c - k, min_ops, x, y);
            }
        }
    }
    cout << min_ops << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve(); 
}
