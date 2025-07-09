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
        ll n;
        char ch;
        cin >> n >> ch;
        string s;
        cin >> s;
        bool already_same = 1;
        for(ll i=0; i<n; i++) {
            if(s[i] != ch) {
                already_same = 0;
                break;
            }
        }
        if(already_same) {
            cout << 0 << "\n";
            continue;
        }
        bool found = 0;
        for(ll i=2; i<=n; i++) {
            bool flag = 1;
            for(ll j=i-1; j<n; j+=i) {
                if(s[j] != ch) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                found = 1;
                cout << 1 << "\n";
                cout << i << "\n";
                break;
            }
        }
        if(!found) {
            ll j = 2;
            while(n % j == 0) j++;
            cout << 2 << "\n";
            cout << j << " " << n << '\n';
        }
    }
    return 0;
}