#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b, total=0;
    cin >> n >> a >> b;
    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        if(x == '1'){
            total += b;
        }
        else {
            total += a;
        }
    }
    cout << total << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve(); 
}