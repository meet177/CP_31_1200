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
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        unordered_map<ll,ll> mpp;
        for(ll i=0; i<n; i++) {
            ll diff = arr[i] - i;
            mpp[diff]++;
        }
        ll ans = 0;
        for(auto& it : mpp) {
            ll freq = it.second;
            ans += (freq)*(freq-1)/2;
        }
        cout << ans << '\n';
    }
    return 0;
}