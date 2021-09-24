#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FastIO
    // solution start here
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi s(n,0), p(n,0), v(n,0);
        int high = 0;
        for(int i=0; i<n; i++){
            cin >> s[i] >> p[i] >> v[i];
            int value = (p[i]/(s[i]+1))*v[i];
            if (value > high) high = value;
        }
        cout << high<< "\n";
    }

    // solution end here
    return 0;
}