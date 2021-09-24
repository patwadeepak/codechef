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
    int n, h, x; 
    cin >> n >> h >> x;
    vector<int> t(n);
    int diff = h-x;
    bool result = false;
    for(auto &x : t){
        cin >> x;
        if(diff <= x){
            result = true;
            break;
        }
    }
    cout << ((result) ? "YES" : "NO") << endl;        
}

int main(){
    FastIO
    solve();
}