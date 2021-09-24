#include <bits/stdc++.h>

using namespace std;

void solve() {
    bool possible = false; 
		vector<int> a(3);
		int d, e;
		cin >> a[0] >> a[1] >> a[2] >> d >> e;
		int total = a[0]+a[1]+a[2];
		for(int i=0; i<3; i++){
			if(total - a[i] <= d && a[i] <= e) {
				possible = true;
				break;
			}
		}
		string output = possible ? "YES" : "NO";
		cout << output << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}