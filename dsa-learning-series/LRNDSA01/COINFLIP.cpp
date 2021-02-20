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
        int g; cin >> g;
        while(g--){
            int i,n,q;
            cin >> i >> n >> q;
            int result = n/2 + n%2;
            if((i==1&&q==1)||(i==2&&q==2))
                result = n - result;
            cout << result << "\n";
        }
    }    
    // solution end here

    return 0;
}