#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
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
        
        unordered_set<string> words;
        string w;
        for(int i=0; i<n; i++){
            cin >> w;
            words.insert(w);
        }
        ll count = 0;
        unordered_set<string>::iterator it, it2, present_a, present_b, not_found=words.end();
        string a,b;
        // Naive solution
        for(it = words.begin(); it!=not_found; it++){
            it2=it;it2++;
            for(; it2 != not_found; it2++){
                a = *it, b = *it2;
                char temp = a[0];
                a[0] = b[0];
                b[0] = temp;
                present_a = words.find(a);
                if(present_a == not_found){
                    present_b = words.find(b);
                    if(present_b == not_found)
                        count++;
                }
            }
        }
        cout << 2*count << "\n";
    }
}