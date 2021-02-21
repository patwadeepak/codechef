#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

void solve(){
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int min_diff=1e9 + 10;
    for(int i=k-1; i<n; i++){
        int diff = a[i] - a[i-k+1];
        if(min_diff > diff)
            min_diff = diff;
    }
    cout << min_diff <<endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--) solve();    
}