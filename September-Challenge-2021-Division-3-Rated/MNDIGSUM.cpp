#include <bits/stdc++.h>

using namespace std;

// int calcNBaseSum(int num, int base){
//     int sum=0;
//     while(num){
//         sum += num%base;
//         num /= base;
//     }
//     return sum;
// }

int convertToDecimal(string num, int base){
    int n=0;
    int length = num.size()-1;
    int i=0, digit;
    while(length>=0){
        digit = (num[length] >= 'A' && num[length] <= 'Z') ? (10 + num[length] - 'A') : num[length] - '0';
        n += pow(base, i)*digit;
        i++;
        length--;
    }
    return n;
}

bool compareStringNum(string str1, int base1, string str2, int base2){
    return convertToDecimal(str1, base1) < convertToDecimal(str2, base2);
}

vector<char> getDigitsTMakeSum(int sum){
    
}

void solve() {
    int n, l, r, b;
    cin >> n >> l >> r;
    int max_sum = (int)log2(n) + 1;
    for(int i=1; i<=max_sum; i++){
        vector<char> mydigits = getDigitsTMakeSum(i);
    }
    cout << b << endl;
    // string str;
    // int n;
    // char ch = 'y';
    // bool keepPlaying = true;
    // while(keepPlaying){
    //     cin >> str >> n;
    //     cout << convertToDecimal(str, n) << endl;
    //     cout << "Want to keep playing enter y else n: ";
    //     cin >> ch;
    //     keepPlaying = ch == 'y';
    // }

}

int main() {
    int t; cin >> t;
    while(t--) solve();  
}