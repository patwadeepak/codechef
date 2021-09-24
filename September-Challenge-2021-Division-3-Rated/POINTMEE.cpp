#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin >> x[i];
    for(int i=0; i<n; i++) cin >> y[i];

    int h_max=0, v_max=0, m1_max=0, m2_max=0;
    int xi=0, yi=0, c1i=0, c2i=0;
    for(int i=0; i<n; i++){
        int h=0, v=0, m1=0, m2=0;
        int c1 = y[i] - x[i];
        int c2 = y[i] + x[i];
        for(int j=0; j<n; j++){
            if(i!=j){
                if(x[j] == x[i]) h++;
                if(y[j] == y[i]) v++;
                if(y[j] - x[j] == c1) m1++;
                if(y[j] + x[j] == c2) m2++;
            }
        }
        if(h_max<h){
            h_max = h;
            xi = x[i]; 
        }
        if(v_max<v){
            v_max = v;
            yi = y[i]; 
        }
        if(m1_max<m1){
            m1_max = m1;
            c1i = c1; 
        }
        if(m2_max<m2){
            m2_max = m2;
            c2i = c2;
        }
        
    }

    int xx, yy;
    if(h_max > m1_max && h_max > m2_max && v_max > m1_max && v_max > m2_max){
        xx = xi;
        yy = yi;
    }
    else if(h_max > v_max && h_max > m2_max && m1_max > v_max && m1_max > m2_max){
        xx=xi;
        yy=xi+c1i;
    }
    else if(h_max > v_max && h_max > m1_max && m2_max > v_max && m2_max > m1_max){
        xx=xi;
        yy=-xi+c2i;
    }
    else if(v_max > h_max && v_max > m2_max && m1_max > h_max && m1_max > m2_max){
        yy=yi;
        xx=yi-c1i;
    }
    else if(v_max > h_max && v_max > m1_max && m2_max > h_max && m2_max > m1_max){
        yy=yi;
        xx=c2i-yi;
    }
    else {
        xx=(c2i-c1i)/2;
        yy=(c2i+c1i)/2;
    }

    int minOperations = 0;
    for(int i=0; i<n; i++){
        if(!(x[i]==xx && y[i]==yy)){
            if( x[i] == xx || y[i] == yy || (abs(y[i] - yy) == abs(x[i] - xx))) 
                minOperations++;
            else 
                minOperations += 2;
        }
    }

    cout << minOperations << endl;

}

int main() {
    int t; cin >> t;
    while(t--) solve(); 
}
