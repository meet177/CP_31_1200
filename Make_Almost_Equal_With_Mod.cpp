#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll>arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll gcd = 0;
        for(int i=1; i<n; i++) {
            gcd = __gcd(gcd, abs(arr[i]-arr[i-1]));
        }
        //whatever gcd of differences came for that k we will get more than 2 distinct values but when we do it with 2*gcd it will become only 2 distinct values
        cout << (gcd << 1) << "\n";
    }
    return 0;
}