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
    string s; cin >> s;
    map<char, bool> note;
    note['P'] = false;
    note['C'] = false;
    note['M'] = false;

    for(auto &x : s) note[x] = true;

    if (note['P'] && note['C'] && note['M'])
        cout << "YES\n";
    else cout << "NO\n";

}

int main(){
    FastIO
    int t; cin >> t;
    while(t--) solve();    
}