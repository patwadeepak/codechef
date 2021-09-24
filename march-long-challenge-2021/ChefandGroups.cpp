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
    string s; cin >> s;
    int count = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1' && (i+1 > s.size()-1 || s[i+1] == '0')){
            count++;
        }
    }
    cout << count << endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}