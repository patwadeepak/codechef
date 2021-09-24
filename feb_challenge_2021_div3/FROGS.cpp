#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <tuple>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

int main(){
    FastIO
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> weights(n);
        set<tuple<ll, ll, ll>> frog;

        for(auto &x : weights) cin >> x;

        ll pos=0;
        for(auto &x : weights){
            ll l; cin >> l;
            frog.insert({pos++, x, l});
        }

        ll leaps=0, i, w, l, i1, w1, l1;
        for(auto it=frog.begin(); it != frog.end(); it++){
            tie(i, w, l) = *it;
            auto it1 = it; it1++;
            tie(i1, w1, l1) = *it1;
            if(w > w1){
                ll frog_dest = i+l;
                while(true){
                    auto found_frog = frog.lower_bound({frog_dest, -1, 0});
                    tie(i1, w1, l1) = *found_frog;
                    if(found_frog == frog.end()){
                        frog.insert({frog_dest, w, l});
                        leaps++;
                        frog.erase(it);
                        break;
                    }
                    else if(w1 > w){
                        frog.insert({frog_dest, w, l});
                        leaps++;
                        frog.erase(it);
                        //send existing frog away also
                        break;
                    }
                    else{
                        leaps++;
                        frog_dest += l;
                    }
                }
            }
        }
        cout << leaps << "\n";
    }
}