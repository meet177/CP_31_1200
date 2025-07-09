#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        if(n & 1) {
            ll mid = (n+1)/2;
            //mid + (x*(mid-1)) = k
            //x = (k - mid)/(mid-1)
            //(6/3 = 2)
            ll x = 0;
            if(k >= mid) {
                x = 1 + (k - mid)/(mid - 1);
            }
            k = k + x;
            if(k%n == 0) cout << n << "\n";
            else cout << k%n << '\n';
        }else {
            if(k%n == 0) cout << n << "\n";
            else cout << k%n << "\n";
        }
    }
    return 0;
}