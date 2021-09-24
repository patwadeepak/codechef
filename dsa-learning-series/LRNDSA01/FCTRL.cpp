#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int

int main(){
    FastIO
    
    // solution start here
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = floor(n/5);
        int total = 0;
        while(cnt){
            total += cnt;
            cnt = floor(cnt/5);
        }
        cout << total << "\n";
    }
    // solution end here

    return 0;
}