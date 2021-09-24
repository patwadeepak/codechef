#include <bits/stdc++.h>

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> cache;
int minOps(int xi, int yi, int min_ops, vector<int> &x, vector<int> &y){
    if(cache.count({xi, yi})) return cache[{xi,yi}];
    int ops = 0;
    for(int i=0; i<x.size(); i++){
        if(!(x[i]==xi && y[i]==yi)){
            if( xi == x[i] || yi == y[i] || (abs(y[i] - yi) == abs(x[i] - xi))) 
                ops++;
            else 
                ops += 2;
        }
    }
    cache[{xi,yi}] = min(ops, min_ops);
    return min(ops, min_ops);
}

void solve() {
    cache.clear();
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) cin >> y[i];

    int min_ops = INT_MAX;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            min_ops = minOps(x[i], y[i], min_ops, x, y);
            min_ops = minOps(x[i+1], y[i+1], min_ops, x, y);
            min_ops = minOps(x[i], y[j], min_ops, x, y);
            min_ops = minOps(x[j], y[i], min_ops, x, y);
            
            if(abs(y[i]-y[j]) != abs(x[i]-x[j])){
                int xx, yy;
                xx = y[i] - y[j] + x[i] + x[j];
                yy = y[i] + y[j] + x[i] - x[j];
                
                if(xx%2==0 && yy%2==0){
                    xx /=2; yy /=2;
                    min_ops = minOps(xx, yy, min_ops, x, y);
                }

                xx = x[i] - y[i] + y[j] + x[j];
                yy = x[j] - x[i] + y[j] + y[i];
                if(xx%2==0 && yy%2==0){
                    xx /=2; yy /=2;
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
    int t; cin >> t;
    while(t--) solve(); 
}
