#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;

int main(){
    FastIO
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        
        vector<pair<ll, ll>> weights(n);
        ll i=0;
        for(auto &x : weights){
            ll w; cin >> w;
            x.first = w;
            x.second = i++;
        }

        vector<ll> leaps(n);
        for(auto &x : leaps) cin >> x;
        
        sort(weights.begin(), weights.end());

        ll total=0;

        for(ll i=1; i<n; i++){
            if(weights[i-1].second > weights[i].second){
                ll n = ceil((weights[i-1].second - weights[i].second + 1)/(double)leaps[weights[i].second]);
                weights[i].second += n*leaps[weights[i].second];
                total += n;
            }
            else if (weights[i-1].second == weights[i].second){
                if(weights[i-1].first > weights[i].first){
                    ll n = ceil((weights[i].second - weights[i-1].second + 1)/(double)leaps[weights[i-1].second]);
                    weights[i-1].second += n*leaps[weights[i-1].second];
                    total += n;
                }
                else{
                    ll n = ceil((weights[i-1].second - weights[i].second + 1)/(double)leaps[weights[i].second]);
                    weights[i].second += n*leaps[weights[i].second];
                    total += n;
                }
            }
        }
        cout << total << endl;
    }
}