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

int lis(vector<int> &arr){  
    int n = arr.size();
    vector<int> lis(n); 
    lis[0] = 1;
    for (int i = 1; i < n; i++ ){ 
        lis[i] = 1;
        for (int j = 0; j < i; j++ ){
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis.begin(), lis.end());
}  

void solve(){
    int n; cin >> n;
    vector<int> h(n);
    vector<int> iq(n);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++) cin >> iq[i];

    
}

int main(){
    FastIO
    int t; cin >> t;
    while(t--) solve();    
}