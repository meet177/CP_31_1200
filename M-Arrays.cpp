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
        ll n,m;
        cin >> n >> m;
        vector<ll> rem(m,0);
        for(ll i=0; i<n; i++) {
            ll x;
            cin >> x;
            rem[x % m]++;
        }
        //we are keeping remainder of any value with m
        ll ans = 0;
        //now if we have any element with 0 remainder then we can make only one group of all
        if(rem[0] != 0) ans++;
        //when we have m even and we have some elements with rem m/2 then it will also contain one group
        if(m % 2 == 0 && rem[m/2] != 0) ans++;
        //now we are making pairs 
        for(ll i=1; i<(m+1)/2; i++) {
            if(rem[i] == 0 && rem[m-i] == 0) continue;
            ll x = rem[i], y = rem[m-i];
            ans += (1 + max(0LL,abs(x-y)-1));
        }
        cout << ans << "\n";
    }
    return 0;
}