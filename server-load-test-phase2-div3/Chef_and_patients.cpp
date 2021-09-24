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
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> deck;
    vi ans(n);
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end(), greater <>());
    
    int hrs = 1;
    for(int i=0; i<n; i++){
        if(i+1>n || a[i].first != a[i+1].first){
            ans[a[i].second] = hrs++;
            while(deck.size()){
                auto x = deck.back();
                ans[x.second] = hrs++;
                deck.pop_back();
            }
        }
        else{
            deck.push_back(a[i]);
        }
    }
    while(deck.size()){
        auto x = deck.back();
        ans[x.second] = hrs++;
        deck.pop_back();
    }

    for(auto x: ans) cout << x << " "; cout << endl;
    
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--){
        solve();
    }
}