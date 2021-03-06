#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    int start_row=0, ens_row=n-1;
    int start_col=0, end_col=m-1;
    while(true){
        for(auto &x:a[start_row]){
            if(x == '0')
                continue;
        }
    }
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}