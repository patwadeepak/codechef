#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef vector<int> vi;

int main(){
    FastIO
    
    int n; cin >> n;
    for(int i=10; i>=1; i--){
        if(n%i==0){
            cout << i;
            break;
        }
    }
}