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
        cin >> n;
        string s;
        cin >> s;
        ll zeroes = 0;
        for(ll i=0; i<n; i++) {
            if(s[i] == '0') zeroes++;
        }
        //already all one
        if(zeroes == 0) {
            cout << "DRAW\n";
            continue;
        }
        //odd length string
        if(n & 1) {
            if(s[n/2] == '0') {
                if(zeroes == 1) cout << "BOB\n";
                else cout << "ALICE\n";
            }else {
                cout << "BOB\n";
            }
        }
        //even length string
        else {
            cout << "BOB\n";
        }
    }
    return 0;
}