#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define whole(x) (x).begin(), (x).end()

const int M = 1e9 + 7;

void setupIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

ll lcm(ll x, ll y) {
    return (x*y)/__gcd(x,y);
}

ll sumof(ll n) {
    return n*(n+1)/2;
}
int main() {
    setupIO();
    int t;
    cin >> t;
    while(t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        ll mul_x = n/x;
        ll mul_y = n/y;
        ll mul_both = n/lcm(x,y);
        ll rem_x = mul_x - mul_both;
        ll rem_y = mul_y - mul_both;
        ll sum_x = (sumof(n) - sumof(n-rem_x));
        ll sum_y = (sumof(rem_y));
        cout << sum_x - sum_y << "\n";
    }
    return 0;
}