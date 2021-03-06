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
    int m, h; cin >> m >> h;
    int bmi = m/(h*h);
    if(bmi <= 18) cout << 1 << endl;
    else if(bmi > 18 && bmi <= 24) cout << 2 << endl;
    else if(bmi > 24 && bmi <= 29) cout << 3 << endl;
    else cout << 4 << endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}