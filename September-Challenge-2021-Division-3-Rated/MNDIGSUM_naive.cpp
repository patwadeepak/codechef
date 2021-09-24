#include <bits/stdc++.h>

using namespace std;

int convert(int num, int base, int min_sum){
    int rem, sum=0;
    while(num){
        rem = num%base;
        sum += rem;
        num /= base;
        if(sum > min_sum) return min_sum;
    }
    return sum;
}

void solve() {
    int n, l, r, b;
    cin >> n >> l >> r;
    int min_sum = INT_MAX;
    for(int i=l; i<=r; i++){
        int sum = convert(n,i, min_sum);
        if(min_sum > sum){
            b=i;
            min_sum=sum;
        }
        if(i>n){
            break;
        }
    }
    cout << b << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();  
}