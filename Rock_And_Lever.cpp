#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"

ll bits(ll n) {
    ll ans = 0;
    while(n) {
        ans++;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        vector<ll> freq(31,0);
        for(ll i=0; i<n; i++) {
            ll b = bits(arr[i]);
            freq[b-1]++;
        }
        ll ans = 0;
        for(ll i=0; i<31; i++) {
            ans += (freq[i]*(freq[i]-1))/2;
        }
        cout << ans << "\n";
    }
    return 0;
}