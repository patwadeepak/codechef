#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    unordered_map<int, int> freqMap;
    for(int i=0; i<n; i++) {
        int num; cin >> num;
        freqMap[num]++;
    }

    int maxEqualInts = 1;
    int numOfOperations = 0;
    for(auto it=freqMap.begin(); it!=freqMap.end(); it++){
        int count;
        if(it->first != it->first^x){
            count = it->second + (freqMap.count(it->first^x) ? freqMap[it->first^x] : 0);
            if(count > maxEqualInts){
                maxEqualInts = count;
                numOfOperations = min(it->second, (freqMap.count(it->first^x) ? freqMap[it->first^x] : 0)); 
            }
        }
        else{
            count = it->second;
            if(count > maxEqualInts){
                maxEqualInts = count;
                numOfOperations = 0;
            }
        }
        if(count == maxEqualInts)
            numOfOperations = min(min(it->second, (freqMap.count(it->first^x) ? freqMap[it->first^x] : 0)), numOfOperations);
    }
    cout << maxEqualInts << " " << numOfOperations << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve(); 
}