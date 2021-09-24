#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

ll minPrice(int n, int e, int h, int a, int b, int c){
    
    int ymax = e+h-2*n;
    if(ymax < 0) return -1;
    
    ll minP = -1, val=0;
    for(int y=ymax; y>=0; y--){
        int zmax = h-3*y;
        int zmin = 2*n - 2*y - e;
        for(int z=zmax; z>=max(0,zmin); z--){
            int x = n - y - z;
            if(x<0) continue;        
            val = a*x + b*y + c*z;
            if(minP == -1 || (minP > val && x+y+z>=n)) {
                minP = val;
            }
        }
    }
    return minP;
}
// This solution passed only 2 test cases.
// Others were TLE for obvious reasons.
void solve(){
    int n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    int result = minPrice(n, e, h, a, b, c);
    cout << result << endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}