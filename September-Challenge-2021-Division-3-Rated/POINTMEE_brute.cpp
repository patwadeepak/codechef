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
    int max_x = INT_MIN, min_x = INT_MAX, max_y = INT_MIN, min_y = INT_MAX;
    
    for(int i=0; i<n; i++){
        cin >> x[i];
        if(max_x < x[i]) max_x = x[i];
        if(min_x > x[i]) min_x = x[i];
    }

    for(int i=0; i<n; i++){
        cin >> y[i];
        if(max_y < y[i]) max_y = y[i];
        if(min_y > y[i]) min_y = y[i];
    }

    int min_ops = INT_MAX;
    for(int i=min_x; i<=max_x; i++){
        for(int j=min_y; j<=max_y; j++){
            min_ops = minOps(i, j, min_ops, x, y);
        }
    }

    cout << min_ops << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve(); 
}
