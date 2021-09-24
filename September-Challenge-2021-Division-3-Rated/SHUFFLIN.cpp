#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int even = 0;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(x%2 == 0) even++;
    }

    int evenreq = (n + 1) /2;
    int oddreq = n - evenreq;

    int sum =0;
    sum += min(even, evenreq);
    sum += min(n-even, oddreq);

    cout << sum << endl;
    
}

int main() {
    int t; cin >> t;
    while(t--) solve(); 
}