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

string tobinary(ll n){
    string a;
    while(n){
        if(n%2) a = '1' + a;
        else a = '0' + a;
        n/=2;
    }
    return a;
}

ll todecimal(string &a){
    ll n = 0;
    ll i = a.size()-1;
    for(auto &x : a) n += (x-'0')*pow(2, i--);
    return n;
}

void solve(){
    ll c; cin >> c;
    string cstr = tobinary(c);
    string astr, bstr;
    bool first = true;
    for(auto &x : cstr){
        if(x == '1'){
            if(first){
                astr += '1';
                bstr += '0';
                first = false;
            }
            else{
                astr += '0';
                bstr += '1';
            }
        }
        else{
            astr += '1';
            bstr += '1';
        }
    }
    cout << todecimal(astr)*todecimal(bstr) << endl;
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}